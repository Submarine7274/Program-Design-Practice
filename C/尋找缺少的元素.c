//尋找整數數列缺少的元素 這題原本要用array解 但其實用不到array
#include <stdio.h>
int main(void) {
    int number=0,sum=0,missing=0; //宣告總數字 個位數總和 缺少的數字
    scanf("%d",&number);    //輸入總數字
    for(int i=0;i<number-1;i++){
        int n;  //宣告輸入的數字
        scanf("%d",&n); 
        sum+=n; //計算輸入數字的總和
    }
    int expected_sum=number*(number+1)/2;   //計算1到n的總和
    missing=expected_sum-sum;   //計算缺少的數字
    printf("%d",missing);   //輸出缺少的數字
    return 0;
}