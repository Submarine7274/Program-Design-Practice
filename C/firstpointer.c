#include <stdio.h>
int main (void){
    int* ptr;
    int i =10;
    ptr = &i;//將ptr指向i的位置
    printf("解ptr之後的值：%d\n", *ptr); //解pointer 並印出來10
    printf("i變數的位置：%p\n", &i);
    printf("ptr指向的位置：%p\n", ptr);
    printf("可以發現ptr指向的位置跟i變數儲存的位置一樣\n");
    return 0;
}