#include<stdio.h>
int main (void)
{
    int g, g1;
    printf("Enter a numerical grade: ");
    scanf("%d", &g);
    g1 = g / 10;
    switch(g1){
        case 6: printf("Letter grade: D"); break;
        case 7: printf("Letter grade: C"); break;
        case 8: printf("Letter grade: B"); break;
        case 9: case 10: printf("Letter grade: A"); break;
        default: printf("Letter grade: F"); break;
    }
return 0;
}