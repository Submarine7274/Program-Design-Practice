#include<stdio.h>
int main (void){
    int matrix[5][5];
    int rowsum = 0, columnsum =0;
    for(int i = 0; i<=4; i++){
        printf("Enter row %d: ",i+1);
        for(int j =0; j<=4; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("Row totals:");
    for(int i = 0; i<=4; i++){
        rowsum = 0;
        for(int j =0; j<=4; j++){
            rowsum +=matrix[i][j];
        }
        printf(" %d", rowsum);
    }
    printf("Column totals:");
    for(int i = 0; i<=4; i++){
        columnsum = 0;
        for(int j =0; j<=4; j++){
            columnsum +=matrix[j][i];
        }
        printf(" %d", columnsum);
    }
    return 0;
}