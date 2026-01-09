#include<iostream>
#include<mpi.h>
#include <cstring>
#ifndef SIZEOFNUMBER
#define SIZEOFNUMBER 100000000 // 設為一億
#endif
#ifndef BLOCK_LOW//這是第id個process負責的index的起始位置(包含)
#define BLOCK_LOW(id, p, n)  ((unsigned long long)(id) * (n) / (p))
#endif
#ifndef BLOCK_HIGH//這是第id個process負責的index的結束位置(包含)
#define BLOCK_HIGH(id, p, n) (BLOCK_LOW((id) + 1, p, n) - 1)
#endif
#ifndef BLOCK_SIZE//回傳第 id 個 process 負責的元素數量
#define BLOCK_SIZE(id, p, n) (BLOCK_LOW((id) + 1, p, n) - BLOCK_LOW((id), p, n))
#endif
//找質數 除了2以外的偶數都不會是質數 所以可以少找一半 所以array的index值對應到新的數 像是index0 對應到3, index1 對應到5 對應函式是value = index*2 +3 
//版本更新
//第一次是由rank0廣播給其他人下一個k值，但如果CPU數量超級多的時候，會產生新的k值其實在rank1的情況
//第二次是每個rank都要找到自己最小的k值 廣播給其他人
//第三次是先建立一個根號N以內的質數vector 每次要用新的k值時直接去vector裡面找
int main(){
    using namespace std;
    ios::sync_with_stdio(false);//解綁定C語言
    cin.tie(nullptr);//讓cin不用等cout.flush()
    MPI_Init(NULL,NULL);//這不是MPI的標準寫法 但我不喜歡在CLI中輸入參數
    int rank,size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    unsigned long long global_elements = (SIZEOFNUMBER - 3) / 2 + 1;//只處理奇數 不包含偶數 所以減掉0 1 2這三個數 加1是3這個數也要算進去

    unsigned long long local_low_index = BLOCK_LOW(rank, size, global_elements);//自己負責的起點
    unsigned long long local_high_index = BLOCK_HIGH(rank, size, global_elements);//自己負責的終點
    unsigned long long local_size = BLOCK_SIZE(rank, size, global_elements);//負責多少元素
    bool* local_prime_array = new bool[local_size];//宣告自己負責的陣列
    memset(local_prime_array, 0, local_size * sizeof(bool));//把整個自己負責的array全部設成false false是質數 true是合數
    unsigned long long upper  = sqrt(SIZEOFNUMBER);//根號N
    vector<unsigned long long> sqrtSIZEOFNUMBERprime;//存質數的vector
    vector<bool> is_prime(upper + 1, true);//判斷下一個質數的bool vector
    for (unsigned long long p = 2; p <= upper; p++) {//從2找到根號N
        if (is_prime[p]) {//如果是質數
            if (p > 2) sqrtSIZEOFNUMBERprime.push_back(p); // 只存奇質數
            for (unsigned long long i = p * p; i <= upper; i += p)//一樣從p的次方開始標記 把p倍數的都標記成非質數
                is_prime[i] = false;//標記
        }
    }
    MPI_Barrier(MPI_COMM_WORLD);// 同步並開始計時
    double start_time = MPI_Wtime();
    for (unsigned long long k : sqrtSIZEOFNUMBERprime) {
    unsigned long long local_start_value = local_low_index * 2 + 3;
    unsigned long long first_multiple_value;
    
    if (local_start_value % k == 0) {//如果起點剛好是k的倍數 就可以用
            first_multiple_value = local_start_value;
    } 
    else {
        first_multiple_value = (local_start_value / k + 1) * k;//因為除法會無條件捨去 所以得到前一個的倍數 ＋1就是下一個的倍數 *k之後就會得到大於local_start_value且能被k整除的最小數
    }
    if(first_multiple_value %2 == 0){//如果起始的數字是偶數 陣列中所有的數值都是奇數 要變成奇數
        first_multiple_value +=k;//加上k就是奇數了
    }
    if (first_multiple_value < k * k) {//從k*k開始篩選 因為小於k*k的數已經被更小的質數篩選了
        first_multiple_value = k * k;
    }
    // 標記合數
    unsigned long long global_index_start = (first_multiple_value - 3) / 2;
    if (global_index_start <= local_high_index) {
        unsigned long long local_index = global_index_start - local_low_index;
        for (unsigned long long i = local_index; i < local_size; i += k) {
            local_prime_array[i] = true;
        }
    }
}
    unsigned long long local_count = 0;//自己找到的質數
    for (unsigned long long i = 0; i < local_size; i++) {//看一次自己負責的數量
        if (!local_prime_array[i]) {//這個array中 false的代表是質數
            local_count++;//計算自己產出多少質數
        }
    }
    unsigned long long global_count = 0;//等等要接收的全部質數數量
    //MPI_Reduce(傳出去的地方,接收的地方,接收的數量,型別,reduce的操作,結果放到哪個rank,用哪個通訊器)
    MPI_Reduce(&local_count, &global_count, 1, MPI_UNSIGNED_LONG_LONG, MPI_SUM, 0, MPI_COMM_WORLD);
    double end_time = MPI_Wtime();//計時結束
    double local_spent_time = end_time-start_time;//記錄這個processor花多久
    double most_spent_time = 0;//只看花最久的process
    MPI_Reduce(&local_spent_time,&most_spent_time,1,MPI_DOUBLE,MPI_MAX,0,MPI_COMM_WORLD);//收集一次時間
    if(rank ==0){
        global_count++;//一開始只算奇數 要加上2這個質數
        cout << "Total primes: " << global_count << endl;//輸出全部找到的質數數量
        cout<<"Spent "<<most_spent_time<<"seconds."<<endl;//花最久的processor
    }
    delete[] local_prime_array;//釋放每個動態配置的空間
    MPI_Finalize();//MPI結束
    return 0;
}

/*int main(){//廢案 每次都從自己的範圍內找到最小的k值 並且Allreduce然後拿最小的k當下一個k值

using namespace std;

ios::sync_with_stdio(false);//解綁定C語言

cin.tie(nullptr);//讓cin不用等cout.flush()

MPI_Init(NULL,NULL);//這不是MPI的標準寫法 但我不喜歡在CLI中輸入參數

int rank,size;

MPI_Comm_rank(MPI_COMM_WORLD, &rank);

MPI_Comm_size(MPI_COMM_WORLD, &size);

unsigned long long global_elements = (SIZEOFNUMBER - 3) / 2 + 1;//只處理奇數 不包含偶數 所以減掉0 1 2這三個數 加1是3這個數也要算進去



unsigned long long local_low_index = BLOCK_LOW(rank, size, global_elements);//自己負責的起點

unsigned long long local_high_index = BLOCK_HIGH(rank, size, global_elements);//自己負責的終點

unsigned long long local_size = BLOCK_SIZE(rank, size, global_elements);//負責多少元素

bool* local_prime_array = new bool[local_size];//宣告自己負責的陣列

memset(local_prime_array, 0, local_size * sizeof(bool));//把整個自己負責的array全部設成false false是質數 true是合數

MPI_Barrier(MPI_COMM_WORLD);// 同步並開始計時

double start_time = MPI_Wtime();

unsigned long long k = 3;//從k=3開始找質數

while(k * k <= SIZEOFNUMBER){//持續找下一個質數k 直到k*k比SIZEOFNUMBER大為止 根據演算法若 k平方大於n 則往後的合數已經被之前更小的質數標記完了

unsigned long long local_start_value = local_low_index *2 +3;//把index轉成實際數值 自己負責的起始block實際的數值

unsigned long long first_multiple_value;//第一個倍數 拿來標記成非質數

if (local_start_value % k == 0) {//如果起點剛好是k的倍數 就可以用

first_multiple_value = local_start_value;

} else {

first_multiple_value = (local_start_value / k + 1) * k;//因為除法會無條件捨去 所以得到前一個的倍數 ＋1就是下一個的倍數 *k之後就會得到大於local_start_value且能被k整除的最小數

}

if(first_multiple_value %2 == 0){//如果起始的數字是偶數 陣列中所有的數值都是奇數 要變成奇數

first_multiple_value +=k;//加上k就是奇數了

}

if (first_multiple_value < k * k) {//從k*k開始篩選 因為小於k*k的數已經被更小的質數篩選了

first_multiple_value = k * k;

}

//接下來又要從實際數值轉回去index了

unsigned long long global_index_start = (first_multiple_value-3) /2;//在總陣列中的相應起點位置

if(global_index_start <=local_high_index){//只有當這個起始索引還在自己process 的範圍內，才需要標記

unsigned long long local_index;

local_index = global_index_start-local_low_index;//換成自己local的起始index

for(unsigned long long i = local_index;i<local_size;i+=k){//從自己的local_index開始找 每次找k的index大小

local_prime_array[i] = true;//在自己負責的區間內 標記成true 代表是合數

}

}

// 1. 每個人都先預設自己找不到下一個 k (設為無限大)

unsigned long long my_next_k = SIZEOFNUMBER + 1;


// 2. 計算我們要從哪個 Global Index 開始找

// 目前 k 對應的 index 是 (k-3)/2

// 所以我們要找 (k-3)/2 + 1 之後的第一個 false

unsigned long long current_k_global_idx = (k - 3) / 2;

unsigned long long search_start_global_idx = current_k_global_idx + 1;



// 3. 判斷搜尋範圍是否落在我的區塊內

if (search_start_global_idx <= local_high_index) {

unsigned long long local_search_idx;


// 如果搜尋起點比我的起點還小，代表我要從頭 (index 0) 開始找

if (search_start_global_idx < local_low_index) {

local_search_idx = 0;

} else {

// 否則從搜尋起點對應的位置開始找

local_search_idx = search_start_global_idx - local_low_index;

}



// 4. 在局部陣列中掃描，找第一個 false

for (unsigned long long i = local_search_idx; i < local_size; i++) {

if (!local_prime_array[i]) {

// 找到了！計算對應的數值

my_next_k = (local_low_index + i) * 2 + 3;

break; // 找到最小的就停，不用再找了

}

}

}



//此時：

// Rank 0 可能找到了 5 (my_next_k = 5)

// Rank 1 可能找到了 15 (my_next_k = 15)

// Rank 2 可能找不到 (my_next_k = 1000001)



// 5. 使用 MPI_Allreduce 找出所有人當中「最小」的那個 k

// 這樣大家都會同步拿到正確的下一個質數

unsigned long long global_next_k;

MPI_Allreduce(&my_next_k, &global_next_k, 1, MPI_UNSIGNED_LONG_LONG, MPI_MIN, MPI_COMM_WORLD);


// 更新 k

k = global_next_k;


// 安全檢查：如果找出來的 k 已經超過範圍 (代表沒質數了)，跳出迴圈

if (k > SIZEOFNUMBER) break;

 if(rank == 0){//只有在rank 0執行 要找下一個質數k給大家

unsigned long long current_k_index = (k - 3) / 2;//目前k的數值所對應的array index

unsigned long long next_k_index = current_k_index + 1; //下一個index先預設為目前的+1

while(next_k_index < local_size && local_prime_array[next_k_index] == true){//如果下一個index還在rank 0 負責的大小 而且是合數的話

next_k_index++;//就一直找下一個 直到是質數為止

}

k = next_k_index*2 +3;//把index值轉換成實際的數值

}

MPI_Bcast(&k, 1, MPI_UNSIGNED_LONG_LONG, 0, MPI_COMM_WORLD);//發給全部人

這有邊界值的問題 如果CPU的數量很多 而且要算的範圍很大 會出現下一個k值其實在rank 1負責的區塊 有邊界問題 所以是廢案(只適用於CPU少的)

}

unsigned long long local_count = 0;//自己找到的質數

for (unsigned long long i = 0; i < local_size; i++) {//看一次自己負責的數量

if (!local_prime_array[i]) {//這個array中 false的代表是質數

local_count++;//計算自己產出多少質數

}

}

unsigned long long global_count = 0;//等等要接收的全部質數數量

//MPI_Reduce(傳出去的地方,接收的地方,接收的數量,型別,reduce的操作,結果放到哪個rank,用哪個通訊器)

MPI_Reduce(&local_count, &global_count, 1, MPI_UNSIGNED_LONG_LONG, MPI_SUM, 0, MPI_COMM_WORLD);

double end_time = MPI_Wtime();//計時結束

double local_spent_time = end_time-start_time;//記錄這個processor花多久

double most_spent_time = 0;//只看花最久的process

MPI_Reduce(&local_spent_time,&most_spent_time,1,MPI_DOUBLE,MPI_MAX,0,MPI_COMM_WORLD);//收集一次時間

if(rank ==0){

global_count++;//一開始只算奇數 要加上2這個質數

cout << "Total primes: " << global_count << endl;//輸出全部找到的質數數量

cout<<"Spent "<<most_spent_time<<"seconds."<<endl;//花最久的processor

}

delete[] local_prime_array;//釋放每個動態配置的空間

MPI_Finalize();//MPI結束

return 0;

}
*/