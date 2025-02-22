#include <stdio.h>

double average(double a, double b,double c, double d);

int main(void){
    double x, y, z, w;
    scanf("%lf %lf %lf %lf", &x, &y, &z, &w);
    printf("%.2lf",average(x, y, z, w));
}

double average(double a, double b,double c, double d){
    double average;
    average = (a + b+ c +d)/4;
    return average;
}