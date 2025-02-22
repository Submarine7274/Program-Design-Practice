#include<stdio.h>
float avg (float w, float x, float y, float z);
int main(void){
    float w, x, y, z;
    scanf("%f", &w);
    scanf("%f", &x);
    scanf("%f", &y);
    scanf("%f", &z);
    printf("%.2f",avg (w, x, y, z));
    return 0;
}
float avg (float w, float x, float y, float z){
    float i = 0.00;
    i += w;
    i += x;
    i += y;
    i += z;
    i /= 4;
    return i;
}