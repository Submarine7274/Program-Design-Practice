#include<stdio.h>
int main (void){
    int n=0;                       //宣告一個整數n為0
    scanf("%d", &n);               //得到使用者輸入的整數
    for(int i = 1; i<=n; i++){     //負責目前第幾行，以及換行的外部for迴圈
	    for(int j = 1; j<=i; j++){ //負責印*的內部迴圈
	    printf("*");
    }
	printf("\n");                  // \n就是換行 
    }
    return 0;
}