#include <stdio.h>
int main (void)
{
    int i1, i2, i3, i4, j1, j2, j3, j4, k1, k2, k3, k4, l1, l2, l3, l4;
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &i1, &i2, &i3, &i4, &j1, &j2, &j3, &j4, &k1, &k2, &k3, &k4, &l1, &l2, &l3, &l4);
    printf("%2d %2d %2d %2d\n%2d %2d %2d %2d\n%2d %2d %2d %2d\n%2d %2d %2d %2d\n\nRow sums: %d %d %d %d\nColumn sums: %d %d %d %d\nDiagonal sums: %d %d",i1, i2, i3, i4, j1, j2, j3, j4, k1, k2, k3, k4, l1, l2, l3, l4, i1 + i2 + i3 + i4, j1 + j2 + j3 + j4, k1 + k2 + k3 + k4, l1 + l2 + l3 + l4, i1 + j1 + k1 + l1, i2 + j2 + k2 + l2, i3 + j3 + k3 + l3, i4 + j4 + k4 + l4, i1 + j2 + k3 + l4, i4 + j3 + k2 + l1);
    return 0;
}