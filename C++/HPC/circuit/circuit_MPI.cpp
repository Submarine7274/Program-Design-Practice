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
    /* if ((!signal[0] && !signal[1])||(signal[1] && signal[3])
    ||(!signal[2] && !signal[3])||(signal[3] && signal[4])
    ||(!signal[4] && signal[5])||(!signal[5] && signal[6])
    ||(!signal[5] && !signal[6])||(!signal[6] && signal[15])
    ||(!signal[7] && signal[8])||(signal[7] && signal[13])
    ||(!signal[8] && !signal[9])||(!signal[8] && signal[9])
    ||(signal[9] && signal[10])||(!signal[9] && !signal[11])
    ||(!signal[10] && !signal[11])||(!signal[12] && !signal[13])
    ||(signal[13] && signal[14])||(!signal[14] && !signal[15])
    ){
        return 0;
    } */
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
        return false;//early return
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
            solutions.push_back(id);//在第幾個結果找到解
        }
    }
    double end_time = MPI_Wtime();
    double local_time = end_time - start_time;
    int local_solutions_counts = solutions.size();
    int total_solution_count = 0;
    MPI_Reduce(&local_solutions_counts, &total_solution_count, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    double max_time = 0.0;
    MPI_Reduce(&local_time, &max_time, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);
    if(rank == 0){
        cout<<"We have " << total_solution_count<<" solotions."<<endl;
        cout<<"Max spend time is:"<<max_time<<" (second)."<<endl;
    }


    vector<int> all_solution_counts(size);
    MPI_Gather(&local_solution_count, 1, MPI_INT, all_solution_counts.data(), 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        // 2. 計算位移量 (displacements)
        // 這是 MPI_Gatherv 必須的，告訴它 Rank 1 的資料要接著 Rank 0 的後面放...
        vector<int> displacements(size, 0);
        int current_offset = 0;
        for(int i = 0; i < size; i++) {
            displacements[i] = current_offset;
            current_offset += all_solution_counts[i];
        }

        // 3. 準備接收所有解的陣列
        vector<int> all_solutions(total_solution_count);
        
        // 4. 收集所有解
        MPI_Gatherv(solutions.data(), local_solution_count, MPI_INT,
                    all_solutions.data(), all_solution_counts.data(), 
                    displacements.data(), MPI_INT, 0, MPI_COMM_WORLD);
        
        // 5. 【關鍵邏輯】輸出是哪個 CPU 找到的
        // 我們不直接遍歷 all_solutions，而是利用 all_solution_counts 來分組
        int global_index = 0; // 用來追蹤目前讀取到 all_solutions 的第幾個元素
        
        for (int r = 0; r < size; r++) { // 外層迴圈：遍歷每個 CPU (Rank)
            int count_for_this_rank = all_solution_counts[r];
            
            // 如果這個 CPU 有找到解，就列出來
            if (count_for_this_rank > 0) {
                for (int k = 0; k < count_for_this_rank; k++) {
                    int sol = all_solutions[global_index];
                    
                    // 輸出格式：CPU 編號 -> 解 -> 二進位
                    cout << "CPU " << r << " found " << sol << " : ";
                    for (int i = 0; i < 16; i++) {
                        cout << BIT_signalValue(sol, i);
                    }
                    cout << endl;
                    
                    global_index++; // 移動到下一個解
                }
            }
        }
        
    } else {
        // 非 Rank 0 的工作：發送自己的資料
        MPI_Gatherv(solutions.data(), local_solution_count, MPI_INT,
                    NULL, NULL, NULL, MPI_INT, 0, MPI_COMM_WORLD);
    }
    
    MPI_Finalize();
    return 0;
}
/*
int main() {
    using namespace std;
    MPI_Init(NULL, NULL);
    
    int rank, size;
    vector<int> solutions;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    double start_time = MPI_Wtime();//計時
    
    for (int id = rank; id < 65536; id += size) {//每個CPU平均分配工作 這邊其實就可以用reduce輸出有幾個解了
        if (check_circuit(id, 16)) {
            solutions.push_back(id);
        }
    }
    
    double end_time = MPI_Wtime();//結束計時
    double local_time = end_time - start_time;

    /* int MPI_Reduce(
    const void *sendbuf,    // 1. 送出的資料指標 (來源)
    void *recvbuf,          // 2. 接收結果的指標 (目的)
    int count,              // 3. 資料個數
    MPI_Datatype datatype,  // 4. 資料型別
    MPI_Op op,              // 5. 運算操作 (加總、最大值等)
    int root,               // 6. 根 Process 的 Rank (誰負責收結果)
    MPI_Comm comm           // 7. 通訊器
); */
/*
    int local_count = solutions.size();
    int total_count = 0;
    //使用 MPI_Reduce 計算總數量 (MPI_SUM)
    // 參數: (發送資料, 接收資料, 個數, 型別, 運算方式, 根Process, 通訊器)
    MPI_Reduce(&local_count, &total_count, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&local_time, &max_time, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);

    //只有 Rank 0 負責輸出統計結果
    if (rank == 0) {
        cout << "Found " << total_count << " solution(s)." << endl;
        cout << "Total Time: " << max_time << " (sec)" << endl;
    }

    int solution_count = solutions.size();//計算每個process解 的數量
    vector<int> all_solution_counts(size);
    //MPI_Gather(送出資料的指標,送出個數,資料型別,接收的buffer,每個process的接收數,型別,root的process,MPI_COMM_WORLD)
    MPI_Gather(&solution_count, 1, MPI_INT, all_solution_counts.data(), 1, MPI_INT, 0, MPI_COMM_WORLD);
    
    if (rank == 0) {//輸出結果
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
        cout << "Total: " << max_time << " (sec)" << endl;
    } else {

        MPI_Gatherv(solutions.data(), solution_count, MPI_INT,
                    NULL, NULL, NULL, MPI_INT, 0, MPI_COMM_WORLD);
        MPI_Reduce(&local_time, NULL, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);
    }
    
    MPI_Finalize();
    return 0;
}
*/