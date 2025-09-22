#include<stdio.h>
int main (void){
    int command=0;  // 宣告變數 指令
    float balance = 0.0, credit, debit; // 宣告變數 餘額、存款、提款
    printf("\n*** ACME checkbook-balancing program ***\nCommands: 0=clear, 1=credit, 2=debit, 3=balance, 4=exit\n\n");  // 印出程式標題與指令說明
    for(;command != 4;){    // 當指令不等於4時持續執行
        printf("Enter command: \n");
        scanf("%d", &command);
        switch(command){
            case 0:{    // 清除餘額
                balance = 0.0f;
                printf("\n");
            } 
            break;
            case 1:{    // 存款
                printf("Enter amount of credit: ");
                scanf("%f", &credit);
                balance +=credit;
                printf("\n");
            } 
            break;
            case 2:{    // 提款
                printf("Enter amount of debit: ");
                scanf("%f", &debit);
                balance -=debit;
                printf("\n");
            } 
            break;
            case 3:{    // 查詢餘額
                printf("Current balance: $%.2f\n",balance);
            } 
            break;
            case 4:break;   // 離開程式
        }
    }
    return 0;
}