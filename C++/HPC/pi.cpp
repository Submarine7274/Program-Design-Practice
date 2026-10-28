#include <iostream>
#include <mpi.h>
#include <cstdlib>
#include <ctime>
#include <iomanip> // 用於控制輸出格式 (如取消科學記號)

using namespace std;

int main(int argc, char** argv) {
    using namespace std;//良好寫程式習慣 by 傑哥
    ios::sync_with_stdio(false);//跟原生C語言解除綁定
    cin.tie(nullptr);//因為輸入cin時 會先執行cout.flush()來清除buffer 所以會降低時間
    int rank, size;
    long long int num_tosses = 100000000; // 總投擲次數 N，數字越大越精準，但運算越久
    long long int local_tosses, local_hits = 0;
    long long int total_hits;
    double pi_estimate;

    // 宣告計時變數 (MPI_Wtime 回傳秒數，型別為 double)
    double start_time, end_time, time_spent;

    // 初始化 MPI 環境並取得節點資訊
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // 強制所有節點在此同步，確保大家從同一時間點開始計時，避免誤差
    MPI_Barrier(MPI_COMM_WORLD);
    
    // 由 Master 節點 (rank 0) 紀錄起始時間
    if (rank == 0) {
        start_time = MPI_Wtime(); 
    }

    // 將總運算量平均分配給叢集中的每個進程
    local_tosses = num_tosses / size;
    
    // 依據各節點的 rank 給予不同的亂數種子，確保產生的隨機點不會重複
    srand(time(NULL) + rank);

    // 蒙地卡羅法核心計算：判斷隨機座標是否落在單位圓內
    for (long long int i = 0; i < local_tosses; i++) {
        double x = (double)rand() / RAND_MAX * 2.0 - 1.0;
        double y = (double)rand() / RAND_MAX * 2.0 - 1.0;
        if (x * x + y * y <= 1.0) {
            local_hits++;
        }
    }

    // 將各個節點的 local_hits 加總 (MPI_SUM)，並將結果收集至 Master 節點的 total_hits 中
    MPI_Reduce(&local_hits, &total_hits, 1, MPI_LONG_LONG_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // 由 Master 節點處理最終結果與輸出
    if (rank == 0) {
        end_time = MPI_Wtime(); // 紀錄結束時間
        time_spent = end_time - start_time; // 計算總耗時(秒)

        // 計算 Pi 值：圓面積(Pi*r^2) / 正方形面積(2r*2r) = 命中數 / 總數
        pi_estimate = 4.0 * ((double)total_hits / (double)num_tosses);
        
        cout << "估算出的 Pi 值為: " << pi_estimate << endl;
        // 將秒數乘以 1000000 轉換為微秒，並使用 fixed 避免科學記號
        cout << "執行時間: " << fixed << setprecision(0) << (time_spent * 1000000.0) << " 微秒" << endl;
    }

    MPI_Finalize(); // 關閉 MPI 環境
    return 0;
}