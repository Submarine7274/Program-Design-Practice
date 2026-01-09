#include <iostream>
#include <vector>
#include <mpi.h>
#ifndef BIT_signalValue
#define BIT_signalValue(n, i) (((n) & (1 << (i))) ? 1 : 0)
#endif

bool check_circuit(int id){
    using namespace std;
    bool signal[16];
    for (int i = 0; i < 16; i++){
        signal[i] = BIT_signalValue(id, i);
    }    
     if ((!signal[0] && !signal[1])||(signal[1] && signal[3])
    ||(!signal[2] && !signal[3])||(signal[3] && signal[4])
    ||(!signal[4] && signal[5])||(!signal[5] && signal[6])
    ||(!signal[5] && !signal[6])||(!signal[6] && signal[15])
    ||(!signal[7] && signal[8])||(signal[7] && signal[13])
    ||(!signal[8] && !signal[9])||(!signal[8] && signal[9])
    ||(signal[9] && signal[10])||(!signal[9] && !signal[11])
    ||(!signal[10] && !signal[11])||(!signal[12] && !signal[13])
    ||(!signal[13] && signal[14])||(!signal[14] && !signal[15])
    ){
        return 0;// 有一個條件不通過return 0
    } 
    /*if (
    !(
	(signal[0] || signal[1]) && ( !signal[1] || !signal[3] ) && 
    ( signal[2] || signal[3] ) &&(!signal[3] || !signal[4]) && 
    (signal[4] || !signal[5]) &&(signal[5] || !signal[6] ) && 
    (signal[5] || signal[6]) &&(signal[6] || !signal[15]) && 
    (signal[7] || !signal[8]) &&(!signal[7] || !signal[13]) && 
    (signal[8] || signal[9]) &&(signal[8] || !signal[9]) && 
    (!signal[9] || !signal[10]) &&(signal[9] || signal[11]) && 
    (signal[10] || signal[11]) &&(signal[12] || signal[13]) && 
    (signal[13] || !signal[14]) &&(signal[14] || signal[15])
    )
	){
        return 0;//early return的省時
    }*/
    //這邊不輸出結果的原因是 平行時會搶著輸出各自的結果 會很花時間 搶著輸出也會變亂碼
    /* cout << id << ") ";//原先的格式
    for (int i = 0; i < input_digits; i++){
        cout << signal[i];//輸出目前signal的boolean值 會是一整串01
    }
    cout << endl;//換行 */
    return 1;//boolean值是正的 主程式的count會++
}

int main() {
    using namespace std;//良好寫程式習慣 by 傑哥
    ios::sync_with_stdio(false);//跟原生C語言解除綁定
    cin.tie(nullptr);//因為輸入cin時 會先執行cout.flush()來清除buffer 所以會降低時間
    MPI_Init(NULL, NULL);//初始化 可以為NULL沒關係
    
    int rank, size;//這時再把rank跟size初始
    int local_solution_counts=0;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int runs = 0;
    if(rank == 0){
        cout<<"輸入要跑幾次(建議1萬次以上)"<<endl;
        cin>>runs;
    }
    // MPI_Bcast(資料位址, 數量, 型態, 來源Rank, 通訊器)
    MPI_Bcast(&runs, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Barrier(MPI_COMM_WORLD);//確保大家都收到了 才開始
    double start_time = MPI_Wtime();//MPI的計時 秒為單位
    for(int i =0; i <runs; i++){//執行runs次
        for (int id = rank; id < 65536; id += size) {//將任務平均分配給各個processor 所以每次會加上size(有幾個processor在執行)
            if (check_circuit(id)) {//傳進去id的值
                local_solution_counts++;//在目前的CPU找到幾次解
            }
        }
    }
    double end_time = MPI_Wtime();//結束計時
    double local_time = end_time - start_time;

    int total_solution_counts = 0;
    double most_spent_time = 0;
    /* int MPI_Reduce(
    const void* sendbuf,   // 傳送緩衝區：每個處理器要提供的資料位址
    void* recvbuf,         // 接收緩衝區：歸約後的結果存放位址（僅 Root 處理器有效）
    int count,             // 資料數量：緩衝區中有多少個元素
    MPI_Datatype datatype, // 資料類型：例如 MPI_INT, MPI_DOUBLE
    MPI_Op op,             // 歸約操作：例如 MPI_SUM加總所有處理器的數值, MPI_MAX / MPI_MIN	找出所有處理器中的最大或最小值, MPI_PROD相乘所有數值,MPI_LAND / MPI_LOR	邏輯與 (AND) / 邏輯或 (OR)
    int root,              // 目標處理器：哪一個處理器負責接收最終結果
    MPI_Comm comm          // 通訊器：通常使用 MPI_COMM_WORLD
    ); */
    MPI_Reduce(&local_solution_counts, &total_solution_counts, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    //把local的count 全部存到total的count裡 只傳一個資料 傳MPI_INT 用MPI_SUM加總 存到rank 0 用MPI_COMM_WORLD通訊器
    MPI_Reduce(&local_time, &most_spent_time,1,MPI_DOUBLE,MPI_MAX,0,MPI_COMM_WORLD);
    //把local的時間 找最大的放到全部時間 只傳一個資料 傳MPI_DOUBLE 用MPI_MAX取最大 存到rank 0 用MPI_COMM_WORLD通訊器
    if(rank ==0){
        cout << "Total: " << total_solution_counts << " solutions." <<endl;//理論上有runs*9次
        cout << "Spent " << most_spent_time<< " seconds." << endl;//輸出時間
    }
    
    MPI_Finalize();//MPI結束
    return 0;
}
