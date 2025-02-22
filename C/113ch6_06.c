#include<stdio.h>
int main (void){
    int commands = 0;
    float balance = 0.0f, credit = 0.0f, debit = 0.0f;
    printf("*** ACME checkbook-balancing program ***\nCommands: 0=clear, 1=credit, 2=debit, 3=balance, 4=exit\n\n");
    for(; ;){
        printf("Enter command: ");
        scanf("%d", &commands);
        switch(commands){
            case 0:
            balance = 0.0f;
            break;
            case 1:
            printf("Enter amount of credit: ");
            scanf("%f", &credit);
            balance +=credit;
            credit = 0;
            break;
            case 2:
            printf("Enter amount of debit: ");
            scanf("%f", &debit);
            balance -= debit;
            debit = 0;
            break;
            case 3:
            printf("Current balance: $%.2f\n", balance);
            break;
            case 4:
            return 0;
            break;
            default:
            printf("Commands: 0=clear, 1=credit, 2=debit, ");
            printf("3=balance, 4=exit\n\n");
            break;
        }
    }
}