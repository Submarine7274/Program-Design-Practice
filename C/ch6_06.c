#include<stdio.h>
int main (void){
    int n;
    float b = 0.0, c, d;
    printf("\n*** ACME checkbook-balancing program ***\nCommands: 0=clear, 1=credit, 2=debit, 3=balance, 4=exit\n\n");
for(n = 0;n != 4;){
    printf("Enter command: \n");
    scanf("%d", &n);
    switch(n){
        case 0:{
            b = 0.0f;
        printf("\n");
        } break;
        case 1:{printf("Enter amount of credit: ");
        scanf("%f", &c);
        b +=c;
        printf("\n");
        } break;
        case 2:{printf("Enter amount of debit: ");
        scanf("%f", &d);
        b -=d;
        printf("\n");
        } break;
        case 3:{printf("Current balance: $%.2f\n",b);
        } break;
        case 4:break;
        return 0;
    }
}
return 0;
}