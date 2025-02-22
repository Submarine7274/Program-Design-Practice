#include <stdio.h>
#define FREEZING_PT 32.0f
#define SCALE_FACTOR (9.0f / 5.0f)
int main (void){
    float fahrenheit, celsius;
    scanf("%f", &celsius);
    fahrenheit = (celsius * SCALE_FACTOR) + FREEZING_PT;
    printf("%.2f", fahrenheit);
    return 0;
}