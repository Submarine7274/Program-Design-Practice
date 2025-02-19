#include<stdio.h>
int main(void){
    const int r = 5;
    const int c = 5;
    int m[r][c];
    for(int i = 0; i < r; i++){
        printf("Enter row %d: \n", i + 1);
        for(int j = 0; j < c; j++){
            scanf("%d", &m[i][j]);
        }
    }
    printf("Row totals:");
    for(int i = 0; i < r; i++){
        int rowsum = 0;
        for(int j = 0; j < c; j++){
            rowsum += m[i][j];
        } 
        printf(" %d", rowsum);
    }
    printf("\n");
    printf("Column totals:");
    for(int j = 0; j < c; j++){
        int colsum = 0;
        for(int i = 0; i < r; i++){
            colsum += m[i][j];
        }
        printf(" %d", colsum);
    }
    

    return 0;
}