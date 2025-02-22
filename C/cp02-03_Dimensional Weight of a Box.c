#include <stdio.h>
int main (void){
    int height, length, width, volume, weight;

    height = 12;
    length = 14;
    width= 11;
    volume = height * length * width;
    weight = (volume +99) /100;
    printf("%d", weight);
    return 0;
}