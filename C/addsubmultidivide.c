#include <stdio.h>
int main(void){
    float num =0.0f, result = 0.0f;
    char operator;
    printf("Enter an expression (example: 1+2.5*3): ");
    scanf("%f", &result);
    while((operator = getchar()) != '\n'){
        switch(operator){
            case '+':
            scanf("%f", &num);
            result += num;
            break;
            case '-':
            scanf("%f", &num);
            result -= num;
            break;
            case '*':
            scanf("%f", &num);
            result *= num;
            break;
            case '/':
            scanf("%f", &num);
            if(num != 0){
                result /= num;
            }
            else{
                printf("Can't divide zero");
            }
            break;
            //default:
            //printf("there is something wrong");
            //break;

        }
    }
    printf("%f", result);
    return 0;
}