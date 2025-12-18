#include <mpi.h>
#include <stdio.h>
#include <iostream>

#define ROW 30000
#define COL 20000

#define BLOCK_LOW(id, p, n) ((id) * (n) / (p))
#define BLOCK_SIZE(id, p, n) (BLOCK_LOW((id) + 1, p, n) - BLOCK_LOW((id), p, n))

using namespace std;

int main(int argc, char **argv)
{
    int world_size, world_rank;
    //此處須進行MPI初始化    

    int **A;
    int *B;
    int *C;
    int *localC;
    int recv_cnt[world_size], recv_disp[world_size];

    C = (int *)malloc(ROW * sizeof(int));

    int size = BLOCK_SIZE(world_rank, world_size, ROW);
    MPI_Status status;

    double startTime = MPI_Wtime();

    for (int i = 0; i < world_size; i++)
    {
        //此處須計算每個process 所分配到的資料區塊: recv_cnt[i], recv_disp[i]
    }

    if (world_rank == 0)
    {
        A = (int **)malloc(ROW * sizeof(int *));
        for (int i = 0; i < ROW; i++)
        {
            A[i] = (int *)malloc(COL * sizeof(int));
        }

        localC = (int *)malloc(size * sizeof(int));

        B = (int *)malloc(COL * sizeof(int));

        srand(36);
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                A[i][j] = rand() % 10;
            }
        }
        for (int i = 0; i < COL; i++)
        {
            B[i] = rand() % 10;
        }

        // decomposition A
        for (int i = 1; i < world_size; i++)
        {
           
          //分派資料給每個 process
        }
    }
    else
    {
        
     //每個process接收自己該計算的資料
    }

    //廣播向量 b 給所有processes

    for (int i = 0; i < size; i++)
    {
        localC[i] = 0;
        for (int j = 0; j < COL; j++)
        {
            localC[i] += A[i][j] * B[j];
        }
    }

    //收集計算結果向量c

    double endTime = MPI_Wtime();

    if (world_rank == 0)
    {
        cout << "A" << endl;
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }

        cout << "B" << endl;
        for (int i = 0; i < 6; i++)
        {
            cout << B[i] << " ";
        }
        cout << endl;

        cout << "C" << endl;
        for (int i = 0; i < 6; i++)
        {
            cout << C[i] << " ";
        }

        printf("\n\033[42;37m execution time: %.5f s \033[0m", endTime - startTime);
    }

    for (int i = 0; i < size; i++)
    {
        free(A[i]);
    }
    free(A);
    free(B);
    free(C);
    free(localC);

    MPI_Finalize();
    return 0;
}