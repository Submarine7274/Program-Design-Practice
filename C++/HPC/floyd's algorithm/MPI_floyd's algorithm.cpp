#include <mpi.h>
#include <iostream>
#include <cstdlib> 
#include <cstdio>  
#include <iomanip> 
const int INF = 9999;
const int N = 6; // 矩陣大小

int main() {
    MPI_Init(NULL, NULL);
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (N % size != 0) {// 檢查 N 是否能被 process 數量整除，AI幫我加的安全檢查
        if (rank == 0) std::cerr << "錯誤：N (" << N << ") 必須能被 process 數量整除。" << std::endl;
        MPI_Finalize();
        return 0;
    }
    int rows_per_processor = N / size; //每個processor負責幾列
    int *global_Bstorage = nullptr;
    int **global_B = nullptr;
    if (rank == 0) {
        global_Bstorage = (int *) malloc(N * N * sizeof(int));
        global_B = (int **) malloc(N * sizeof(int *));
        for (int i = 0; i < N; i++) {
            global_B[i] = &global_Bstorage[i * N];
        }
        int input[N*N] = {
            0,   2,   5, INF, INF, INF,
          INF,   0,   7,   1, INF,   8,
          INF, INF,   0,   4, INF, INF,
          INF, INF, INF,   0,   3, INF,
          INF, INF,   2, INF,   0,   3,
          INF,   5, INF,   2,   4,   0
        };
        for(int i=0; i<N*N; i++) global_Bstorage[i] = input[i];
    }
    int *local_Bstorage = (int *) malloc(rows_per_processor * N * sizeof(int));
    int **local_B = (int **) malloc(rows_per_processor * sizeof(int *));
    for (int i = 0; i < rows_per_processor; i++) {
        // 注意：這裡每一列長度還是 N
        local_B[i] = &local_Bstorage[i * N];
    }
    MPI_Scatter(global_Bstorage, rows_per_processor * N, MPI_INT,
                local_Bstorage,  rows_per_processor * N, MPI_INT,
                0, MPI_COMM_WORLD);
    int *pivot_row = (int *) malloc(N * sizeof(int));
    for (int k = 0; k < N; ++k) {
        int owner_rank = k / rows_per_processor;//判斷誰擁有第 k 列
        if (rank == owner_rank) {//擁有者把那一列複製到 pivot_row 準備廣播
            // 計算 k 對應到 local_B 中的哪一列 (區域索引)
            int local_k = k % rows_per_processor;
            for (int j = 0; j < N; ++j) {// 複製資料：可以直接用 local_B[local_k][j] 來存取
                pivot_row[j] = local_B[local_k][j];
            }
        }
        MPI_Bcast(pivot_row, N, MPI_INT, owner_rank, MPI_COMM_WORLD); //廣播 pivot_row
        for (int i = 0; i < rows_per_processor; ++i) {//更新自己負責的列
            for (int j = 0; j < N; ++j) {
                int dist_ik = local_B[i][k];
                int dist_kj = pivot_row[j];
                if (dist_ik != INF && dist_kj != INF) {
                    if (dist_ik + dist_kj < local_B[i][j]) {
                        local_B[i][j] = dist_ik + dist_kj;
                    }
                }
            }
        }
    }
    MPI_Gather(local_Bstorage,  rows_per_processor * N, MPI_INT,
               global_Bstorage, rows_per_processor * N, MPI_INT,
               0, MPI_COMM_WORLD);
    if (rank == 0) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (global_B[i][j] == INF) printf("INF ");
                else printf("%3d ", global_B[i][j]);
            }
            printf("\n");
        }
        free(global_B);// 釋放全域記憶體 (先 free 指標陣列，再 free 資料區)
        free(global_Bstorage);
    }
    free(local_B);// 釋放本地記憶體與暫存區
    free(local_Bstorage);
    free(pivot_row);
    MPI_Finalize();
    return 0;
}