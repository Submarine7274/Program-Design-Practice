#include<iostream>
#include <chrono>
#ifndef BIT_signalValue
#define BIT_signalValue(n, i) ( ( n & ( 1 << i ) ) ? 1 : 0 )
#endif
//chcp 65001 終端機轉UTF-8
bool check_circuit(int id, int input_digits){
    using namespace std;
    bool signal[input_digits];
    for (int i = 0; i < input_digits; i++){
        signal[i] = BIT_signalValue(id, i);
    }    
    /* if ((!signal[0] && !signal[1])||(signal[1] && signal[3])
    ||(!signal[2] && !signal[3])||(signal[3] && signal[4])
    ||(!signal[4] && signal[5])||(!signal[5] && signal[6])
    ||(!signal[5] && !signal[6])||(!signal[6] && signal[15])
    ||(!signal[7] && signal[8])||(signal[7] && signal[13])
    ||(!signal[8] && !signal[9])||(!signal[8] && signal[9])
    ||(signal[9] && signal[10])||(!signal[9] && !signal[11])
    ||(!signal[10] && !signal[11])||(!signal[12] && !signal[13])
    ||(signal[13] && signal[14])||(!signal[14] && !signal[15])
    ){
        return 0;// 有一個條件不通過return 0
    } */
    if (
        !(
	(signal[0] || signal[1]) && ( !signal[1] || !signal[3] ) && ( signal[2] || signal[3] ) &&
	(!signal[3] || !signal[4]) && (signal[4] || !signal[5]) &&
	(signal[5] || !signal[6] ) && (signal[5] || signal[6]) &&
	(signal[6] || !signal[15]) && (signal[7] || !signal[8]) &&
	(!signal[7] || !signal[13]) && (signal[8] || signal[9]) &&
	(signal[8] || !signal[9]) && (!signal[9] || !signal[10]) &&
	(signal[9] || signal[11]) && (signal[10] || signal[11]) &&
	(signal[12] || signal[13]) && (signal[13] || !signal[14]) &&
	(signal[14] || signal[15])
        )
	){
        return 0;//early return的省時
    }
    cout << id << ") ";//原先的格式
    for (int i = 0; i < input_digits; i++){
        cout << signal[i];//輸出目前signal的boolean值 會是一整串01
    }
    cout << endl;//換行
    return 1;//boolean值是正的 主程式的count會++
}

int main(){
    using namespace std;//良好習慣
    unsigned int count=0;//計算次數
    ios::sync_with_stdio(false);//跟原生C語言解除綁定
    cin.tie(nullptr);//因為輸入cin時 會先執行cout.flush()來清除buffer 所以會降低時間
    unsigned int runs = 0;
    cout<<"輸入要跑幾次(建議1萬次以上)"<<endl;
    cin>>runs;
    auto start = std::chrono::high_resolution_clock::now();//計時開始
    for(int i =0; i<runs;i++){    //執行runs次來計算時間
            for (int id = 0; id < 65536; id++){//理論上會有9000次的count
            if (check_circuit(id, 16)){//給出目前的id以及輸入16個bit大小
                count++;
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();//計時結束
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);//輸出時間
    cout << "Total: " << count << " solutions." <<  endl;//理論上有runs*9次
    cout << "Spent " << duration.count() * 1e-9 << " seconds." << endl;//輸出時間
    return 0;
}