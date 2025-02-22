#include <stdio.h>
int main (void){
    short A = 32769;           //超過short的容量
    unsigned short B = 32769;  //改用大容器
    unsigned short C = 65539;  //溢位之後會從最小值開始算

    printf("A:%hd\n", A);      //%hd是short 的格式符號
    printf("B:%hu\n", B);      //%hu是unsigned short 的格式符號
    printf("C:%hu\n", C);

    int D = 2.13E9;            //2.13X10的九次方
    long long E = (long long)D * 100ll;         //雖然沒有溢位，但是兩個整數運算後，還是整數，所以會造成溢位，至少一個要改成長整數，做法是在數字後加上格式字元
    printf("E:%lld\n", E);
    
    int G = 3;
    G += G += G -=2;           //+=是右至左，從最右邊開始算(2+(1+(3-2)))
    printf("G:%d\n", G); 

    int H=1, I=2, J=3;
    J *= H++ + ++I/2;          //前置++先算，J X (1 + 1) = 6
    printf("J:%d\n", J);
    return 0;
}