#include <iostream>
#include <mpi.h>
using namespace std;

#define NUMBER 100000000

bool list[NUMBER + 1] = {false};


int main(int argc, char** argv){
    MPI_Init();

    int world_size;
    MPI_Comm_size();

    int world_rank;
    MPI_Comm_rank();

    int k = 2;
    double start, end;

    start = MPI_Wtime();
    // MPI_Barrier(MPI_COMM_WORLD);

    int start_idx = world_rank * NUMBER / world_size;
    int end_idx = min(NUMBER + 1, (world_rank + 1) * NUMBER / world_size);
    
    while(k * k <= NUMBER){
        
        //3a: marked all multiples of k
        int i = max(k * k, start_idx);
        if(i % k != 0){
            i = (i / k + 1) * k;
        }
        for(; i < end_idx; i += k){
            list[i] = true;
        }

        //3b: find the smallest unmarked number greater than k
        int local_k;
        for(i = max(k + 1, start_idx); i < end_idx; i++){
            if(!list[i]){
                local_k = i;
                break;
            }
        }

        MPI_Reduce();
        MPI_Bcast();
    }

    int local_count = 0;
    for(int i = max(2, start_idx); i < end_idx; i++){
        if(!list[i])  local_count++;
    }
    
    int global_count = 0;
    MPI_Reduce();

    // MPI_Barrier(MPI_COMM_WORLD);
    end = MPI_Wtime();

    double global_time = 0;
    double total_time = end - start;
    MPI_Reduce(&total_time, &global_time, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);
    
    if(world_rank == 0){
        cout << "There are " << global_count << " prime numbers in " << NUMBER << endl;
        cout << "Execution time: " << global_time << "s";
    }


    MPI_Finalize();
    return 0;
}