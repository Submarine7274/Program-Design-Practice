#include <stdio.h>
int main (void){
    float a, b, e = 0.0;
    char o;
    printf("Enter an expression (example: 1+2.5*3): \n");
    scanf("%f", &a);
    while((o = getchar()) != '\n'){
        if(o == '+'){
            scanf("%f", &b);
            e = a + b;
        }
        else if(o == '-'){
            scanf("%f", &b);
            e = a - b;
        }
        else if(o == '*'){
            scanf("%f", &b);
            e = a * b;
        }
        else if(o == '/'){
            if (b != 0){
            scanf("%f", &b);
            e = a / b;
            }
        }
        a = e; 
    }
    printf("Value of expression: %.1f", e);
return 0;
}