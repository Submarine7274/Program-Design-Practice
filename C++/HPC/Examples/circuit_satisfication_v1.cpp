#include <mpi.h>
#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

#define MAX_VALUE 65536

int isTrue(int input[16]){
    int temp = (input['a'-97] || input['b'-97]) & (!input['b'-97] || !input['d'-97]) & (input['c'-97] || input['d'-97]) &
                (!input['d'-97] || !input['e'-97]) & (input['e'-97] || !input['f'-97]) & (input['f'-97] || input['g'-97]) &
                (input['f'-97] || !input['g'-97]) & (input['h'-97] || !input['i'-97]) & (input['i'-97] || input['j'-97]) &
                (input['i'-97] || !input['j'-97]) & (!input['j'-97] || !input['k'-97]) & (input['k'-97] || input['l'-97]) &
                (input['l'-97] || input['j'-97]) & (input['m'-97] || input['n'-97]) & (!input['h'-97] || !input['n'-97]) &
                (input['n'-97] || !input['o'-97]) & (input['o'-97] || input['p'-97]) & (!input['p'-97] || input['g'-97]);

    return temp;
}

int main(int argc, char** argv){
    //此處須自行進行MPI初始化

    int world_size;

    int world_rank;

    int local_count = 0;
    int input[16];
    vector<bitset<16>> local_answer;
    double start, end;

    start = MPI_Wtime();
    //此處須寫一個正確的資料切割 for 迴圈{
        for(int j = 0; j < 16; j++){
            input[j] = (i >> j) & 1;    //取i的第j個bit放進input
        }

        if(isTrue(input)){
            bitset<16> binary(i);
            local_answer.push_back(binary);
            local_count++;
        }
    }

    for(bitset<16> temp: local_answer){
        cout << temp << endl;
    }
    end = MPI_Wtime();

    double total_time = end - start;
    int global_count = 0;
    double global_time = 0;

    //此處須利用MPI functions 彙整所有讓circuit 輸出為true的input組數

    MPI_Reduce(&total_time, &global_time, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);

    if (world_rank == 0) {
        cout << endl << "Total count: " << global_count << endl;
        cout << "Execution time: " << global_time << "s";
    }

    MPI_Finalize();
}