#include <mpi.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
const int N = 4; // 矩陣大小
struct SwapRecord {// 交換紀錄 (P矩陣)
    int row_k;
    int row_pivot;
};


std::vector<SwapRecord> Parallel_LU_Decompose(std::vector<double>& local_A, int rows_per_proc, int rank, int size) {//平行 LU 分解
    using namespace std;
    vector<SwapRecord> swap_history;
    vector<double> pivot_row(N);
    struct { double value; int global_index; } local_max, global_max;

    for (int k = 0; k < N; k++) {
        local_max.value = -1.0;
        local_max.global_index = -1;
        for (int i = 0; i < rows_per_proc; i++) {
            int global_idx = rank * rows_per_proc + i;
            if (global_idx >= k) {
                double val = abs(local_A[i * N + k]);
                if (val > local_max.value) {
                    local_max.value = val;
                    local_max.global_index = global_idx;
                }
            }
        }
        MPI_Allreduce(&local_max, &global_max, 1, MPI_DOUBLE_INT, MPI_MAXLOC, MPI_COMM_WORLD);
        
        int pivot_row_idx = global_max.global_index;
        if (pivot_row_idx != k) swap_history.push_back({k, pivot_row_idx});

        // 實體交換 (Row Interchange)
        int owner_k = k / rows_per_proc;
        int owner_pivot = pivot_row_idx / rows_per_proc;
        
        if (pivot_row_idx != k) {
            vector<double> temp_row(N);
            if (owner_k != owner_pivot) {
                if (rank == owner_k) {
                    int local_k = k % rows_per_proc;
                    for(int j=0; j<N; j++) temp_row[j] = local_A[local_k * N + j];
                    MPI_Sendrecv_replace(temp_row.data(), N, MPI_DOUBLE, owner_pivot, 0, owner_pivot, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    for(int j=0; j<N; j++) local_A[local_k * N + j] = temp_row[j];
                } else if (rank == owner_pivot) {
                    int local_pivot = pivot_row_idx % rows_per_proc;
                    for(int j=0; j<N; j++) temp_row[j] = local_A[local_pivot * N + j];
                    MPI_Sendrecv_replace(temp_row.data(), N, MPI_DOUBLE, owner_k, 0, owner_k, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                    for(int j=0; j<N; j++) local_A[local_pivot * N + j] = temp_row[j];
                }
            } else if (rank == owner_k) {
                int local_k = k % rows_per_proc;
                int local_pivot = pivot_row_idx % rows_per_proc;
                for (int j=0; j<N; j++) swap(local_A[local_k*N+j], local_A[local_pivot*N+j]);
            }
        }

        // Gaussian Elimination
        if (rank == owner_k) {
            int local_k = k % rows_per_proc;
            for (int j=0; j<N; j++) pivot_row[j] = local_A[local_k * N + j];
        }
        MPI_Bcast(pivot_row.data(), N, MPI_DOUBLE, owner_k, MPI_COMM_WORLD);

        for (int i = 0; i < rows_per_proc; i++) {
            int global_row_idx = rank * rows_per_proc + i;
            if (global_row_idx > k) {
                double factor = local_A[i * N + k] / pivot_row[k];
                local_A[i * N + k] = factor; 
                for (int j = k + 1; j < N; j++) local_A[i * N + j] -= factor * pivot_row[j]; 
            }
        }
    }
    return swap_history;
}

// =========================================================================
// 2. 平行求解器 (Parallel Solver)
//    包含: Parallel Forward Substitution & Parallel Backward Substitution
//    時間複雜度: O(N^2/P) 計算 + O(P) 通訊
// =========================================================================
void Parallel_Solve(const std::vector<double>& local_A, 
                    const std::vector<SwapRecord>& swap_history, 
                    std::vector<double>& local_b, // b 是分散的!
                    int rows_per_proc, int rank, int size) {
    
    // [步驟 A] 應用 P 到 b (這步較麻煩，簡單起見我們收集回 Rank 0 做交換再散佈)
    // 嚴格的平行交換 b 需要複雜的邏輯，這裡為了程式碼清晰度，採用 Gather-Swap-Scatter
    // 註：這步通常很快，因為 b 只是向量
    std::vector<double> global_b(N);
    MPI_Gather(local_b.data(), rows_per_proc, MPI_DOUBLE, global_b.data(), rows_per_proc, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    
    if (rank == 0) {
        for (const auto& swap : swap_history) std::swap(global_b[swap.row_k], global_b[swap.row_pivot]);
    }
    MPI_Scatter(global_b.data(), rows_per_proc, MPI_DOUBLE, local_b.data(), rows_per_proc, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    // 我們需要完整的 x 向量來存放結果
    // (每個 Process 最後都會拿到完整的 x，或者只保留自己負責的部分)
    // 這裡我們設計讓每個 Process 計算完自己那段 y 後廣播，讓大家都有完整的 y
    std::vector<double> y(N); 
    std::vector<double> x(N);

    // ---------------------------------------------------------
    // [步驟 B] 平行 Forward Substitution (Ly = b)
    // ---------------------------------------------------------
    // L 是下三角矩陣 (對角線為 1)
    
    // 依序處理每個 Process (Block)
    for (int p = 0; p < size; p++) {
        // 計算該 Process 負責的變數範圍
        int start_row = p * rows_per_proc;
        int end_row = start_row + rows_per_proc;

        // 1. 如果我是目前的負責人 (Owner)
        if (rank == p) {
            for (int i = 0; i < rows_per_proc; i++) { // 對應全域 row = start_row + i
                double sum = 0;
                // 使用之前已經算出來的 y (0 到 start_row-1)
                for (int j = 0; j < start_row + i; j++) {
                    // local_A 存的是 L (下三角部分)
                    sum += local_A[i * N + j] * y[j];
                }
                // L 對角線為 1
                y[start_row + i] = local_b[i] - sum;
            }
        }

        // 2. 負責人廣播剛剛算好的這一段 y 給所有人
        // 這樣其他人下一輪才能更新
        MPI_Bcast(&y[start_row], rows_per_proc, MPI_DOUBLE, p, MPI_COMM_WORLD);
    }

    // ---------------------------------------------------------
    // [步驟 C] 平行 Backward Substitution (Ux = y)
    // ---------------------------------------------------------
    // U 是上三角矩陣 (對角線非 1)
    
    // 這次要從最後一個 Process 往回做
    for (int p = size - 1; p >= 0; p--) {
        int start_row = p * rows_per_proc;
        
        // 1. 如果我是目前的負責人
        if (rank == p) {
            for (int i = rows_per_proc - 1; i >= 0; i--) { // 倒著解
                int global_i = start_row + i;
                double sum = 0;
                // 使用之前算好的 x (global_i+1 到 N-1)
                for (int j = global_i + 1; j < N; j++) {
                    sum += local_A[i * N + j] * x[j];
                }
                // 除以對角線元素
                x[global_i] = (y[global_i] - sum) / local_A[i * N + global_i];
            }
        }

        // 2. 負責人廣播這一段 x
        MPI_Bcast(&x[start_row], rows_per_proc, MPI_DOUBLE, p, MPI_COMM_WORLD);
    }

    // 最後將 x 存回 local_b (為了符合介面，或者直接輸出 x)
    if (rank == 0) {
        std::cout << "[Rank 0] 平行求解完成 x: ";
        for (double val : x) std::cout << std::fixed << std::setprecision(4) << val << " ";
        std::cout << std::endl;
    }
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (N % size != 0) { MPI_Finalize(); return 0; }
    int rows_per_proc = N / size;

    // 初始化
    std::vector<double> local_A(rows_per_proc * N);
    std::vector<double> local_b(rows_per_proc); // 分散的 b
    
    // 準備資料
    if (rank == 0) {
        std::vector<double> global_A(N * N);
        std::vector<double> global_b(N);
        
        double input_A[N*N] = {
             0.001, 1,  1,  1,
            100.0,  2,  1,  3,
             4.0,  50, -2,  6,
             2.0,   5, 80,  1
        };
        // 解 Ax = {10, 10, 10, 10}
        // 理論解約為 {0.096, 0.05, 0.108, 3.23}
        double input_b[N] = {10, 10, 10, 10};

        for(int i=0; i<N*N; i++) global_A[i] = input_A[i];
        for(int i=0; i<N; i++) global_b[i] = input_b[i];

        // 散佈
        MPI_Scatter(global_A.data(), rows_per_proc * N, MPI_DOUBLE, local_A.data(), rows_per_proc * N, MPI_DOUBLE, 0, MPI_COMM_WORLD);
        MPI_Scatter(global_b.data(), rows_per_proc, MPI_DOUBLE, local_b.data(), rows_per_proc, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    } else {
        // 非 Rank 0 也要接收
        MPI_Scatter(nullptr, 0, MPI_DOUBLE, local_A.data(), rows_per_proc * N, MPI_DOUBLE, 0, MPI_COMM_WORLD);
        MPI_Scatter(nullptr, 0, MPI_DOUBLE, local_b.data(), rows_per_proc, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    }

    // 1. 平行分解
    if (rank == 0) std::cout << "Step 1: 平行 LU 分解..." << std::endl;
    std::vector<SwapRecord> swaps = Parallel_LU_Decompose(local_A, rows_per_proc, rank, size);

    // 2. 平行求解
    if (rank == 0) std::cout << "Step 2: 平行代入求解 (Forward/Backward Substitution)..." << std::endl;
    Parallel_Solve(local_A, swaps, local_b, rows_per_proc, rank, size);

    MPI_Finalize();
    return 0;
}