#include <stdio.h>
int main (void){
    int a1, a2, a3, a4, b1, b2, b3, b4, c1, c2, c3, c4, d1, d2, d3, d4, rs1, rs2, rs3, rs4, cs1, cs2, cs3, cs4, ds1, ds2;
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &a1, &a2, &a3, &a4, &b1, &b2, &b3, &b4, &c1, &c2, &c3, &c4, &d1, &d2, &d3, &d4);
    printf("%2d %2d %2d %2d\n", a1, a2, a3, a4);
    printf("%2d %2d %2d %2d\n", b1, b2, b3, b4);
    printf("%2d %2d %2d %2d\n", c1, c2, c3, c4);
    printf("%2d %2d %2d %2d\n", d1, d2, d3, d4);
    printf("\n");
    rs1 = a1 +a2 +a3 +a4;
    rs2 = b1 +b2 +b3 +b4;
    rs3 = c1 +c2 +c3 +c4;
    rs4 = d1 +d2 +d3 +d4;

    cs1 = a1 +b1 +c1 +d1;
    cs2 = a2 +b2 +c2 +d2;
    cs3 = a3 +b3 +c3 +d3;
    cs4 = a4 +b4 +c4 +d4;

    ds1 = a1 +b2 +c3 +d4;
    ds2 = a4 +b3 +c2 +d1;
    
    printf("Row sums: %d %d %d %d\n", rs1, rs2, rs3, rs4);
    printf("Column sums: %d %d %d %d\n", cs1, cs2, cs3, cs4);
    printf("Diagonal sums: %d %d", ds1, ds2);
    return 0;

}