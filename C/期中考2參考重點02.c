#include<stdio.h>
int main (void){
    const int r = 5;
    const int c = 5;
    int m[5][5];
    for(int i = 0; i < r ; i++){
        printf("Enter row %d: \n", i + 1);
        for(int j = 0; j < c; j++){
            scanf("%d", &m[i][j]);
        }
    }
    printf("Row totals:");
    for(int i = 0; i < r; i++){
        int rs = 0;
        for(int j = 0; j < c; j++){
            rs += m[i][j];
        }
        printf(" %d", rs);
    }
    printf("\n");
    printf("Column totals:");
    for(int j = 0; j < c; j++){
        int cs = 0;
        for(int i = 0; i < r; i++){
            cs += m[i][j];
        }
        printf(" %d", cs);
    }
    return 0;
}