#include <stdio.h>
#include <math.h>
int main (void){
    float x =0, y =1, new_y;
    scanf("%f", &x);
    do{
        new_y=((x/y) + y) /2.0f;
        if(fabs(new_y - y) <= (0.00001*y)){
            break;
        }
        y = new_y;
    }while(1);
    printf("%.5f", y);
    return 0;
}