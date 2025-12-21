#include<iostream>
#include<cstring>//等等設定一整塊記憶體要用的
#include<chrono>

#ifndef SIZEOFNUMBER 
#define SIZEOFNUMBER 1000000//目前先設一百萬
#endif

void printPrimes(const bool* notPrime, int arraySize) {
    using namespace std;//良好習慣by傑哥
    long long counts = 1; //先算入唯一的偶數質數 2
    cout<<"2 ";
    for (int i = 0; i < arraySize; i++) {
        if (!notPrime[i]) {//是質數
            counts++;
            long long prime =(long long) i*2+3;//把index還原成實際數值
            cout << prime << " ";
        }
    }
    cout << "Total primes: " << counts << endl;
}
int main(){
    using namespace std;//良好習慣by傑哥
    ios::sync_with_stdio(false);//解綁定提升效能
    cin.tie(nullptr);//可以不用等cout.flush()
    int arraySize = ((SIZEOFNUMBER-3)/2)+1;//不考慮偶數
    bool* notPrime = new bool[arraySize +1];//這不是指標的陣列 是動態的記憶體分配 會放在Heap裡面 避免stack overflow
    memset(notPrime,0,(arraySize+1) *sizeof(bool));//參數：指標, 設定的值(0=false, 1=true), 大小(Bytes)
    long long k =2;
    auto start = chrono::high_resolution_clock::now();
    for(int i =0; ; i++){
        long long k = (long long)i * 2 + 3;//index 0對應到3 1對應到5 這樣只考慮奇數
        if (k * k > SIZEOFNUMBER) break;//只需要找到根號k就可以停了
        if(!notPrime[i]){//是質數的話
            for (long long multiple = k * k; multiple <= SIZEOFNUMBER; multiple += 2*k) {//把質數的倍數全部標記為非質數
                int index = (multiple -3)/2;//multiple是實際數值 存進去array要轉換成index
                notPrime[index] = true; 
            }
        }
        
    }
    auto end = std::chrono::high_resolution_clock::now();
    printPrimes(notPrime,arraySize);
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);//輸出時間
    cout<<"We spent " << duration.count() *1e-9<<" seconds."<<endl;
    delete[] notPrime;//動態記憶體釋放
    return 0;
}