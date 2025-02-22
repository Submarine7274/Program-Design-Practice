#include <stdio.h>

int main (void){
    int a, b, c;//整數宣告
    float d, e, f;//浮點數宣告
    char g, h, i;//字元宣告
    a = 6;//把6指派給a
    b = 3;//把3指派給b
    c = a + b;//把a+b指派給c
    printf("%d\n", c);//列印出c的結果
    c = a - b;//a減b
    printf("%d\n", c);
    c = a * b;//a乘b
    printf("%d\n", c);
    c = a / b;//a除b
    printf("%d\n", c);
    c = a % b;//a除以b取餘數
    printf("%d\n", c);
    d = 6.0;
    e = 3.0;
    f = d + e;
    printf("%.2f\n", f);//浮點數要用%f，前面可以加.數字來讓它顯示多少位數
    f = d - e;
    printf("%.2f\n", f);
    f = d * e;
    printf("%.2f\n", f);
    f = d / e;
    printf("%.2f\n", f);
    g = 'a';//字元用單引號
    h = 'b'; 
    i = 'c';
    printf("%c\n%c\n%c\n",g, h, i);
    return 0;
}