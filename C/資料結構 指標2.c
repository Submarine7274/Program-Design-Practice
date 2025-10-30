#include <stdio.h>
#include <stdlib.h>
int main(void){
    int i, *pi; //i是整數變數 pi是整數的pointer 但i沒有被使用到
    float f, *pf;   // f是浮點數變數，*pf 是浮點數的pointer; 但f沒有被使用到
    pi = (int *) malloc(sizeof(int));   //malloc()可以動態配置記憶體,然後把整個轉型成整數的pointer
    pf = (float *) malloc (sizeof(float));  //malloc()可以動態配置記憶體,然後把整個轉型成浮點數的pointer
    *pi =1024; //解指標之後就可以改變數內容 把該位址的變數賦值為1024
    *pf =3.14;  //解指標之後就可以改變數內容 把該位址的變數賦值為3.14
    printf("an integer = %d, a float = %f\n", *pi, *pf);    //解指標之後就可以取得該位址的變數內容
    free(pi); //釋放記憶體
    free(pf);
    return 0;
}