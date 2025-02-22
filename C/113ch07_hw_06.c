#include <stdio.h>

int main(void) {
    float num = 0.0f, result = 0.0f;
    char operator;

    printf("Enter an expression (example: 1+2.5*3): ");
    scanf("%f", &result);
    while ((operator = getchar()) != '\n'){
        switch (operator) {
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
                result /= num;
                break;
            default:
                printf("Invalid operator: %c. Stopping calculations.\n", operator);
                return 0;
        }
    }
    printf("Value of expression: %.1f\n", result);
    return 0;
}
