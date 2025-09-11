#include <stdio.h>
int main (void){
    int numbers[16],rowsum[4], colsum[4], diagsum[2];   //宣告4個整數數列
    for(int i =0; i<16; i++){
        scanf("%2d", &numbers[i]);  //依指定格式輸入16個整數
    }
    for(int i =0;i<16; i++){
        printf("%2d ", numbers[i]); //依指定格式輸出16個整數
        if((i+1)%4==0) printf("\n"); //每輸出4個整數換行
    }
    printf("\n");   //換行
    //計算列、行、對角和
    rowsum[0] = numbers[0] + numbers[1] + numbers[2] + numbers[3];  //第一列的和
    rowsum[1] = numbers[4] + numbers[5] + numbers[6] + numbers[7];  //第二列的和
    rowsum[2] = numbers[8] + numbers[9] + numbers[10] + numbers[11];    //第三列的和
    rowsum[3] = numbers[12] + numbers[13] + numbers[14] + numbers[15];  //第四列的和
    colsum[0] = numbers[0] + numbers[4] + numbers[8] + numbers[12]; //第一行的和
    colsum[1] = numbers[1] + numbers[5] + numbers[9] + numbers[13]; //第二行的和
    colsum[2] = numbers[2] + numbers[6] + numbers[10] + numbers[14];    //第三行的和
    colsum[3] = numbers[3] + numbers[7] + numbers[11] + numbers[15];    //第四行的和
    diagsum[0] = numbers[0] + numbers[5] + numbers[10] + numbers[15];   //第一對角線的和
    diagsum[1] = numbers[3] + numbers[6] + numbers[9] + numbers[12];    //第二對角線的和
    //輸出列、行、對角和
    printf("Row sums: %d %d %d %d\n", rowsum[0], rowsum[1], rowsum[2], rowsum[3]);
    printf("Column sums: %d %d %d %d\n", colsum[0], colsum[1], colsum[2], colsum[3]);
    printf("Diagonal sums: %d %d", diagsum[0], diagsum[1]);
    return 0;   //程式結束

}