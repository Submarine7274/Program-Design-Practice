#include <stdio.h>
int main(void)
{
int height, length, width, volume, weight, ipb;
//printf("Enter height of box: ");
scanf("%d", &height);
//printf("Enter length of box: ");
scanf("%d", &length);
//printf("Enter width of box: ");
scanf("%d", &width);
scanf("%d", &ipb);
volume = height * length * width;
weight = (volume + ipb-1) / ipb;
//printf("%d\n", volume);
printf("%d", weight);
return 0;
}