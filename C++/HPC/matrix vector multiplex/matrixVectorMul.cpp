#include <mpi.h>
#include <iostream>
#include <vector>
#include <iomanip> 
const int M = 4; // A 的列數 (Rows)
const int N = 5; // A 的行數 (Cols) 也就是 b 的長度

int main() {
    using namespace std;
    ios::sync_with_stdio(false);//解綁定C語言
    cin.tie(nullptr);//讓cin不用等cout.flush()
    MPI_Init(NULL,NULL);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (M % size != 0) {// 檢查 M 是否能被 Process 數量整除(簡化實作，避免處理餘數)
        if (rank == 0) {
            cerr << "錯誤：矩陣列數 M (" << M << ") 必須能被 Process 數量整除。" << endl;
        }
        MPI_Finalize();
        return 0;
    }
    int rows_per_processor = M / size;// 計算每個 Process 負責處理多少列
    vector<int> A_flat;// 用一維陣列存矩陣 Row Major
    vector<int> b(N);// 向量 b
    vector<int> c;// 結果向量c只有Rank0需要配置空間接收
    if (rank == 0) {
        int input_A[M * N] = {
            2,  1, 3,  4, 0,  // Row 0
            5, -1, 2, -2, 4,  // Row 1
            0,  3, 4,  1, 2,  // Row 2
            2,  3, 1, -3, 0   // Row 3
        };
        A_flat.assign(input_A, input_A + M * N);
        int input_b[N] = {3, 1, 4, 0, 3};// 向量 b (5x1)
        b.assign(input_b, input_b + N);
        c.resize(M);// 預先配置 c 的空間以便 Gather
    }
    vector<int> local_A(rows_per_processor * N);//用來接收「部分 A」的緩衝區
    vector<int> local_c(rows_per_processor);//用來存放部分c的結果
    MPI_Barrier(MPI_COMM_WORLD);// 同步並開始計時
    double startTime = MPI_Wtime();
    MPI_Scatter(A_flat.data(), rows_per_processor * N, MPI_INT,// Rank 0 把 A 切塊，發送給每個人的 local_A
                local_A.data(), rows_per_processor * N, MPI_INT,
                0, MPI_COMM_WORLD);
    MPI_Bcast(b.data(), N, MPI_INT, 0, MPI_COMM_WORLD);// Rank 0 把完整的 b 傳給所有人
    for (int i = 0; i < rows_per_processor; ++i) {// 每個 Process 只計算自己負責的那幾列 
        local_c[i] = 0; // 初始化
        for (int j = 0; j < N; ++j) {
            local_c[i] += local_A[i * N + j] * b[j];// 因為 local_A 是一維的，所以用 [i * N + j] 存取
        }
    }
    MPI_Gather(local_c.data(), rows_per_processor, MPI_INT,// 把大家算好的部分local_c拼回 Rank 0的完整 c
               c.data(),       rows_per_processor, MPI_INT,
               0, MPI_COMM_WORLD);
    double endTime = MPI_Wtime();
    double local_spent_time = endTime - startTime;
    double most_spent_time = 0;
    MPI_Reduce(&local_spent_time,&most_spent_time,1,MPI_DOUBLE,MPI_MAX,0,MPI_COMM_WORLD);//收集一次時間
    if (rank == 0) {
        cout << "計算結果 c = A x b :" << endl;
        for (int i = 0; i < M; i++) {
            cout << setw(4) << c[i] << endl;
        }
        cout<<"Spent:"<< fixed << setprecision(8)<<most_spent_time<<"seconds."<<endl;
    }
    MPI_Finalize();
    return 0;
}