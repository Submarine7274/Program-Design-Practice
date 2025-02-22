/*編寫一個程式，實現以下功能：
1. 使用二維陣列存儲兩個 n×m 的整數矩陣A 和 矩陣B。(n代表共有n列,m代表每列有m個元素)
2. 讓使用者輸入兩個整數代表矩陣的列數n 和 行數m。
3. 讓使用者輸入兩個矩陣 A 和 B 的元素。
4. 計算並輸出矩陣 A 和 B 的：
- 元素對應相加的結果矩陣 C=A+B
- 元素對應相減的結果矩陣 D=A-B
- 元素對應相乘的結果矩陣 E=A×B（逐元素相乘，而非矩陣乘法）。
5. x等於C陣列每個元素的相加總和
6. y等於D陣列每個元素的相加總和
7. z等於E陣列每個元素的相加總和
8. 輸出 x+y+z

範例Input Output：("--------"為說明用，程式不用輸出) 
-------------------------- 
Input： 
------- 
2 3
1 2 3
4 5 6
6 5 4
3 2 120
-------------------------- 
Output： 
-------- 
812
-------------------------- */
#include<stdio.h>
int main (void){
    int n =0, m =0, result = 0, x =0,y=0,z=0;
    scanf("%d", &n);
    scanf("%d", &m);
    int arrayA[n][m],arrayB[n][m],arrayC[n][m], arrayD[n][m], arrayE[n][m];
    for(int i =0; i<n; i++){
        for(int j = 0; j <m; j++){
            scanf("%d", &arrayA[i][j]);
        }
    }
    for(int i =0; i<n; i++){
        for(int j = 0; j <m; j++){
            scanf("%d", &arrayB[i][j]);
        }
    }
    for(int i =0; i<n; i++){
        for(int j = 0; j <m; j++){
            arrayC[i][j] = arrayA[i][j] + arrayB[i][j];
            arrayD[i][j] = arrayA[i][j] - arrayB[i][j];
            arrayE[i][j] = arrayA[i][j] * arrayB[i][j];
            x += arrayC[i][j];
            y += arrayD[i][j];
            z += arrayE[i][j];
        }
    }
    result = x+y+z;
    printf("%d", result);
    return 0;
}
