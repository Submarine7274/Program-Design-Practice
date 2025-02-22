/*編寫一個語言程式，實現以下功能：
1. 定義一個函數 transposeMatrix，用於計算並返回一個矩陣的轉置矩陣。
2. 主程式中讀取一個大小為 m×n 的整數矩陣，並呼叫該函數進行轉置操作。
3. 最後在主程式中輸出轉置後的矩陣。
限制:
1. 矩陣最大為 10×10。
2. 輸入矩陣的行數和列數，接著輸入矩陣內容。

範例01Input Output：("--------"為說明用，程式不用輸出) 
-------------------------- 
Input： 
------- 
2 3
1 2 3
4 5 6
-------------------------- 
Output： 
-------- 
1 4
2 5
3 6
--------------------------
範例02Input Output：("--------"為說明用，程式不用輸出) 
-------------------------- 
Input： 
------- 
1 3
8 4 6
-------------------------- 
Output： 
-------- 
8
4
6
--------------------------*/
#include <stdio.h>
void transpose(int m,int n,int array[m][n]);
int main (void){
    int m=0,n=0;
    scanf("%d", &m);
    scanf("%d", &n);
    if(n>10||m >10){
        printf("Out of border");
        return 0;
    }
    int matrix[m][n];
    for(int i =0; i<m;i++){
        for(int j = 0; j<n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    transpose(m,n,matrix);
    return 0;
}
void transpose(int m,int n,int array[m][n]){
    int transposed[n][m];
    for(int i =0; i<n; i++){
        for(int j =0; j<m;j++){
            transposed[i][j] = array[j][i];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", transposed[i][j]);
            if (j < m - 1) {
                printf(" "); 
            }
        }
        printf("\n"); 
    }
}