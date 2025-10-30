#include <stdio.h>
#include <stdlib.h>
int main(void){
    int p = 10; //p是10
    int *ptr1 = &p; // ptr1指標指向p的位址
    int **ptr2 = &ptr1; //ptr2 指標指向另一個pointer ptr1 的位址
    printf("p value:%d\n",p); //印出p的值
    printf("p memory address:%p\n\n",&p); //印出p的位址
    printf("%d", *ptr1); // ptr1 指到 p，印出 p 的值
    printf("%p", ptr1);  // ptr1 的內容 指標變數裡存的是位址（p 的位址）
    printf("%p", &ptr1); // 印出存ptr1指標自己的位址
    printf("**ptr2 = %d\n", **ptr2); //ptr2 → ptr1 → p 印出ptr2指到ptr1指到p的內容  會印出p的值
    printf("*ptr2 = %p\n", *ptr2);   //ptr2解reference 會得到ptr1的內容 就是p的記憶體位址
    printf("ptr2 = %p\n\n", ptr2);   //ptr2本身的內容 就是ptr1的記憶體位址
    return 0;
}
/*這段比較難理解 多做一些說明
    變數有兩種型態 一種是一般變數 另一種是指標變數
    一般變數存的是值 指標變數存的是位址
    p是一般變數 存的是10 他的記憶體位址可以用&p取得
    ptr1是指標變數 存的是p的位址 也就是&p 而ptr1本身的記憶體位址可以用&ptr1取得
    ptr2是指標變數 存的是ptr1的位址 也就是&ptr1 而ptr2本身的記憶體位址可以用&ptr2取得
    ptr1是int pointer 指向int變數 p 
    ptr2是int pointer的pointer 指向int pointer變數 ptr1
    *ptr1是解reference ptr1 會得到ptr1指到的內容 也就是p的值 10
    &ptr1是ptr1本身的位址
    **ptr2是解reference ptr2兩次 會得到ptr2指到的內容 ptr1 然後再解reference ptr1 會得到p的值 10
    *ptr2是解reference ptr2 會得到ptr2指到的內容 ptr1存的東西 也就是p的位址
    ptr2是ptr2本身存的內容 也就是ptr1的位址
    &ptr2是ptr2本身的位址
*/