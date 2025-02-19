#include<stdio.h>
int main (void){
    int grade;
    printf("Enter a numerical grade: ");
    scanf("%d", &grade);
    if(grade <0){
        printf("error");
    }
    else{
        grade /= 10;
        switch(grade){
            case 10: 
            printf("Letter grade: A");
            break;
            case 9:
            printf("Letter grade: A");
            break;
            case 8:
            printf("Letter grade: B");
            break;
            case 7:
            printf("Letter grade: C");
            break;
            case 6:
            printf("Letter grade: D");
            break;
            default:
            printf("Letter grade: F");
            break;
    }
    return 0;
}
}