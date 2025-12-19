#include<iostream>
#include<mpi.h>
#include <cmath>
#include <cstring>
#include <algorithm>

#ifndef SIZEOFNUMBER,BLOCK_LOW,BLOCK_HIGH,BLOCK_SIZE
#define BLOCK_LOW(id, p, n)  ((unsigned long long)(id) * (n) / (p))
#define BLOCK_HIGH(id, p, n) (BLOCK_LOW((id) + 1, p, n) - 1)
#define BLOCK_SIZE(id, p, n) (BLOCK_LOW((id) + 1, p, n) - BLOCK_LOW((id), p, n))
#define SIZEOFNUMBER 1000000 // 設為一百萬
#endif

int main(){
    using namespace std;
    MPI_Init(NULL,NULL);
    int rank,size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unsigned long long global_elements = (SIZEOFNUMBER - 3) / 2 + 1;//只處理奇數 不包含偶數
    unsigned long long local_low_idx = BLOCK_LOW(rank, size, global_elements);//起點
    unsigned long long local_high_idx = BLOCK_HIGH(rank, size, global_elements);//終點
    unsigned long long local_size = BLOCK_SIZE(rank, size, global_elements);//負責多少元素
    bool* local_prime_array = new bool[local_size];
    memset(local_prime_array, 0, local_size * sizeof(bool));
    MPI_Barrier(MPI_COMM_WORLD);// 同步並開始計時
    double start_time = MPI_Wtime();
    unsigned long long k = 3;
}