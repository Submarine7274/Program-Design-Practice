#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int i , *pi; //i是整數變數 pi是整數的pointer
    float f, *pf; // f是浮點數變數，*pf 是浮點數的pointer;
    pi = &i; //這樣指標的變數才可以正常使用
    //指標變數存的是位址 不是整數變數的內容 也可以改變數 但指標就是指到那個位址
    pi= (int *)malloc(sizeof(int)); 
    //sizeof(int)是4byte,malloc()可以動態配置記憶體,然後把整個轉型成整數的pointer
    pf=(float *) pi; //把pi轉型成float pointer 這有可能出錯 但是是課本示範
    free(pi); //釋放記憶體
    return 0;
}