#include <stdio.h>
int main (void){
    int a=0,b=0,c=0;                    //宣告整數 a=0, b=0, c=0
    if((a==0)|| (b+1) >0 || (c-1) <0){  //如果a等於0, 或 b+1 大於0, 或 c-1<0 
	    printf("a=%d b=%d c=%d", a, b, c);    //就印出 a b c 的值
    }
    return 0;
}