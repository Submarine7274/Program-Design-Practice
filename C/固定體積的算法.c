#include <stdio.h>
int main (void){
    int height, width, lengh, volume;
    height = 8;
    lengh = 12;
    width = 10;
    volume = height*lengh*width;

    printf("Dimensions: %dx%dx%d\n", lengh, width, height);
    printf("Volume(cube inches): %d",volume);
    return 0;
}