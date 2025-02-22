#include<stdio.h>
#include<math.h>
int main(void){
    double x, y = 1.0, z, za;
    printf("Enter a positive number: \n");
    scanf("%lf", &x); 
    
    do {
        z = x / y;
        za = (z + y) /2;
        if (fabs(za - y )<= 0.00001){
            y = za;
            break;
        }
        y = za;
    } while (1);
    printf("Square root: %.5lf", y);

    return 0;
}