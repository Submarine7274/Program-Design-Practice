#include <stdio.h>

double average(double a, double b,double c);

int main(void){
    double x, y, z;
    scanf("%lf %lf %lf", &x, &y, &z);
    printf("%.2lf",average(x, y, z));
}

double average(double a, double b,double c){
    double average;
    average = (a + b+ c)/3;
    return average;
}