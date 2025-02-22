#include<stdio.h>
#define PI 3.14159f
#define FRACTION (4.0f/3.0f)

void f (float);

int main (void){
    float r;
    scanf("%f", &r);
    f(r);
    return 0;
}

void f (float r){
    float volume=0.0f;
    volume = r * r * r * FRACTION * PI;
    printf("%.2f", volume);
}