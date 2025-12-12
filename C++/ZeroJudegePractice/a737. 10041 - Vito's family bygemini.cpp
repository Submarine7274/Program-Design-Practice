/*世界聞名的黑社會老大Vito Deadstone要搬到紐約來了。在那裡他有一個大家族，並且他們都住在Lamafia大道上。因為Vito時常要拜訪所有的親戚，他想要找一間離他們最近的房子，也就是說他希望從他的家到所有的親戚的家的距離的和為最小。

他恐嚇你寫一個程式來幫助幫助他解決這個問題。

輸入說明
輸入的第一列有一個整數代表以下有多少組測試資料。

每組測試資料一列，第一個整數 r（0 < r < 500），代表他親戚的數目。接下來的r個整數s1,s2,......sr為這些親戚房子的門牌號碼（0 < si <30000）。注意：有些親戚的門牌號碼會相同。

輸出說明
對每一組測試資料，輸出從他的新家到所有的親戚的家的距離的和為最小為多少。2個門牌號碼si、sj的距離為si-sj的絕對值。
範例輸入 #1
3
2 2 4
3 2 4 6
4 2 1 999 5
範例輸出 #1
2
4
1001*/
#include <iostream>
#include <algorithm> // 用於 sort 排序函式
#include <cmath>     // 用於 abs 絕對值函式
#include <vector>    // 用於 vector 動態陣列

using namespace std;

int main() {
    // 1. I/O 加速優化
    // 這是 CPE/UVa 必備的起手式，避免因輸入輸出太慢導致 TLE (Time Limit Exceeded)
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases;
    cin >> cases; // 讀取總共有幾組測資
    
    // 處理每一組測資
    for (int i = 0; i < cases; i++) {
        int r; // 親戚的數量
        cin >> r;
        
        // 宣告一個大小為 r 的 vector 來存街號
        vector<int> streets(r);
        for (int j = 0; j < r; j++) {
            cin >> streets[j];
        }

        // 2. 核心演算法：中位數 (Median)
        // 數學定理：要讓「到各點距離的絕對值總和」最小，該點必須選在中位數。
        // 因此，我們先將街號進行排序。
        sort(streets.begin(), streets.end());

        // 3. 取中位數
        // 如果 r 是奇數 (如 5)，r/2 = 2，剛好取到中間的 index (0,1,[2],3,4)。
        // 如果 r 是偶數 (如 4)，r/2 = 2，取中間偏右的那個 (0,1,[2],3)。
        // 在「距離總和最小化」的問題中，偶數個點時，中間兩個點之間的任何位置距離和都一樣，
        // 所以直接取 streets[r/2] 是正確且方便的寫法。
        int median = streets[r / 2];

        int totalDistance = 0;
        
        // 4. 計算距離總和
        // 使用 range-based for loop 遍歷所有親戚的家
        for (int s : streets) {
            // abs() 計算絕對值，確保距離為正數
            totalDistance += abs(median - s);
        }

        cout << totalDistance << endl;
    }
    
    return 0;
}