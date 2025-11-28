#include <iostream>
#include <vector>
#include <mpi.h>

#ifndef BIT_signalValue
#define BIT_signalValue(n, i) (((n) & (1 << (i))) ? 1 : 0)
#endif

bool check_circuit(int id, int input_digits) {
    using namespace std;
    vector<bool> signal(input_digits);
    for (int i = 0; i < input_digits; i++) {
        signal[i] = BIT_signalValue(id, i);
    }
    
    if (!(
        (signal[0] || signal[1]) && (!signal[1] || !signal[3]) && (signal[2] || signal[3]) &&
        (!signal[3] || !signal[4]) && (signal[4] || !signal[5]) &&
        (signal[5] || !signal[6]) && (signal[5] || signal[6]) &&
        (signal[6] || !signal[15]) && (signal[7] || !signal[8]) &&
        (!signal[7] || !signal[13]) && (signal[8] || signal[9]) &&
        (signal[8] || !signal[9]) && (!signal[9] || !signal[10]) &&
        (signal[9] || signal[11]) && (signal[10] || signal[11]) &&
        (signal[12] || signal[13]) && (signal[13] || !signal[14]) &&
        (signal[14] || signal[15])
    )) {
        return false;
    }
    return true;
}

int main() {
    using namespace std;
    MPI_Init(NULL, NULL);
    
    int rank, size;
    vector<int> solutions;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    double start_time = MPI_Wtime();
    
    for (int id = rank; id < 65536; id += size) {
        if (check_circuit(id, 16)) {
            solutions.push_back(id);
        }
    }
    
    double end_time = MPI_Wtime();
    double local_time = end_time - start_time;

    int solution_count = solutions.size();
    vector<int> all_solution_counts(size);
    MPI_Gather(&solution_count, 1, MPI_INT, all_solution_counts.data(), 1, MPI_INT, 0, MPI_COMM_WORLD);
    
    if (rank == 0) {
        int total = 0;
        vector<int> displacements(size, 0);
        for (int i = 0; i < size; i++) {
            displacements[i] = total;
            total += all_solution_counts[i];
        }
        

        vector<int> all_solutions(total);
        

        MPI_Gatherv(solutions.data(), solution_count, MPI_INT,
                    all_solutions.data(), all_solution_counts.data(), 
                    displacements.data(), MPI_INT, 0, MPI_COMM_WORLD);
        
        cout << "Found " << total << " solution(s):" << endl;
        for (int sol : all_solutions) {
            cout << sol << ") ";
            for (int i = 0; i < 16; i++) {
                cout << BIT_signalValue(sol, i);
            }
            cout << endl;
        }
        
        double max_time;
        MPI_Reduce(&local_time, &max_time, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);
        cout << "\033[36mTotal: " << max_time << " (sec)\033[0m" << endl;
    } else {

        MPI_Gatherv(solutions.data(), solution_count, MPI_INT,
                    NULL, NULL, NULL, MPI_INT, 0, MPI_COMM_WORLD);
        MPI_Reduce(&local_time, NULL, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);
    }
    
    MPI_Finalize();
    return 0;
}