#include <iostream>
#include <mpi.h>
using namespace std;

#define NUMBER 100000000

bool list[NUMBER + 1] = {false};


int main(int argc, char** argv){

    int world_size;

    int world_rank;
    
    //此處須進行MPI 初始化

    int k = 2;
    double start, end;

    start = MPI_Wtime();
    // MPI_Barrier(MPI_COMM_WORLD);

    //此處須計算出每個 process 所負責的資料區塊起點及終點: start_idx,  end_idx
 
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

     //此處須利用MPI functions找出下一個k, 並廣播給所有的processes
   
    }

    int local_count = 0;
    for(int i = max(2, start_idx); i < end_idx; i++){
        if(!list[i])  local_count++;
    }
    
    int global_count = 0;
    
    //此處須利用MPI function 得到所有質數的總數

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