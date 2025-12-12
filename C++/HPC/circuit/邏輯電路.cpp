#include<iostream>
#include <chrono>
#ifndef BIT_signalValue
#define BIT_signalValue(n, i) ( ( n & ( 1 << i ) ) ? 1 : 0 )
#endif

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
        return 0;// 有一個條件不通過 → return 0
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
        )//early return
	){
        return 0;
    }
    cout << id << ") ";
    for (int i = 0; i < input_digits; i++){
        cout << signal[i];
    }
    cout << endl;
    return 1;
}

int main(){
    using namespace std;
    short count=0;
    auto start = std::chrono::high_resolution_clock::now();
    for (int id = 0; id < 65536; id++){
        if (check_circuit(id, 16)){
            count++;
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    cout << "Total: " << count << " solutions." <<  endl;
    cout << "Time taken: " << duration.count() * 1e-9 << " seconds." << endl;
    return 0;
}