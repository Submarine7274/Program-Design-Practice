#include <mpi.h>
#include <stdio.h>
#include <iostream>

#define BLOCK_LOW(id, p, n) ((id) * (n) / (p))
#define BLOCK_SIZE(id, p, n) (BLOCK_LOW((id) + 1, p, n) - BLOCK_LOW((id), p, n))
#define BLOCK_OWNER(index, p, n) (((p) * ((index) + 1) - 1) / (n))

#define N 1000

using namespace std;

int main(int argc, char **argv)
{

    int world_size, world_rank;
    //此處須進行 MPI 初始化

    int **D;
    // int D[N][N] = {
    //     {0, 2, 5, 100, 100, 100},
    //     {100, 0, 7, 1, 100, 8},
    //     {100, 100, 0, 4, 100, 100},
    //     {100, 100, 100, 0, 3, 100},
    //     {100, 100, 2, 100, 0, 3},
    //     {100, 5, 100, 2, 4, 0}};
    MPI_Status status;

    D = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++)
    {
        D[i] = (int *)malloc(N * sizeof(int));
    }

    double start = MPI_Wtime();

    if (world_rank == 0)
    {
        // adjacent matrix
        // 100代表無限大
        srand(36);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == j)
                    D[i][j] = 0;
                else
                    D[i][j] = rand() % 100 + 1;
            }
        }

        // send data (row)
        for (int i = 1; i < world_size; i++)
        {
            for (int k = 0; k < BLOCK_SIZE(i, world_size, N); k++)
            {
                
             //進行row-wise 資料切割及派送
            }
        }
    }
    else
    {
        // receive data
        for (int k = 0; k < BLOCK_SIZE(world_rank, world_size, N); k++)
        {
            
          //每個process 接收自己所需計算的資料
        }
    }

    int first_row = BLOCK_LOW(world_rank, world_size, N);
    for (int k = 0; k < N; k++)
    {
        // 第 k 行可能並不屬於當前進程的範圍
        MPI_Bcast(D[k], N, MPI_INT, BLOCK_OWNER(k, world_size, N), MPI_COMM_WORLD);

        for (int i = 0; i < BLOCK_SIZE(world_rank, world_size, N); i++)
        {
            for (int j = 0; j < N; j++)
            {
                D[first_row + i][j] = min(D[first_row + i][j], (D[first_row + i][k] + D[k][j]));
            }
        }
    }

    double end = MPI_Wtime();

    // if (world_rank == 0)
    // {
    //     // printf("%d \n", world_rank);
    //     for (int i = 0; i < 6; i++)
    //     {
    //         for (int j = 0; j < 6; j++)
    //         {
    //             printf("%3d ", D[i][j]);
    //         }
    //         printf("\n");
    //     }

    //     printf("\033[42;37m execution time: %.5f s \033[0m", end - start);
    // }

    if (world_rank == 0)
    {
        // 接收其他進程的結果
        for (int i = 1; i < world_size; i++)
        {
            for (int k = 0; k < BLOCK_SIZE(i, world_size, N); k++)
            {
                
              //process 0 接收所有計算結果
            }
        }

        // printf("Processor %d results:\n", world_rank);
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                printf("%3d ", D[i][j]);
            }
            printf("\n");
        }
        printf("\033[42;37m execution time: %.5f s \033[0m", end - start);
    }
    else
    {
        // 傳送本地計算結果給 processor 0
        for (int k = 0; k < BLOCK_SIZE(world_rank, world_size, N); k++)
        {
            
         //其他 processes 傳送計算結果給 process 0
        }
    }

    MPI_Finalize();

    return 0;
}