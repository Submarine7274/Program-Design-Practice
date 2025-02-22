#include<stdio.h>
int main (void){
    int n;
    float b = 0.0, c, d;
    printf("*** ACME checkbook-balancing program ***\nCommands: 0=clear, 1=credit, 2=debit, 3=balance, 4=exit\n\n");
for(n = 0;n != 4;){
    printf("Enter command: ");
    scanf("%d", &n);
    switch(n){
        case 1:{printf("Enter amount of credit: ");
        scanf("%f", &c);
        b +=c;
        } break;
        case 2:{printf("Enter amount of debit: ");
        scanf("%f", &d);
        b -=d;
        } break;
        case 3:
        printf("Current balance: $%.2f\n",b);
        break;
        case 4:break;
        return 0;
    }
}
return 0;
}