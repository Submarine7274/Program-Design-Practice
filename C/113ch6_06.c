#include<stdio.h>
int main (void){
    int commands = 0;   // 宣告變數 指令
    float balance = 0.0f, credit = 0.0f, debit = 0.0f;  // 宣告變數 指令、餘額、存款、提款
     // 說明程式功能及指令
    printf("*** ACME checkbook-balancing program ***\nCommands: 0=clear, 1=credit, 2=debit, 3=balance, 4=exit\n\n");    
     // 無限迴圈直到使用者選擇離開
    for(; ;){
        printf("Enter command: ");  // 提示使用者輸入指令
         // 讀取指令    
        scanf("%d", &commands);
        switch(commands){   
            case 0: // 清除餘額
            balance = 0.0f;
            break;
            case 1: // 存款
            printf("Enter amount of credit: ");
            scanf("%f", &credit);
            balance +=credit;
            credit = 0;
            break;
            case 2: // 提款
            printf("Enter amount of debit: ");
            scanf("%f", &debit);
            balance -= debit;
            debit = 0;
            break;
            case 3: // 顯示餘額
            printf("Current balance: $%.2f\n", balance);
            break;
            case 4: // 離開程式
            return 0;
            break;
            default:    // 無效指令，重新顯示指令說明
            printf("Commands: 0=clear, 1=credit, 2=debit, ");
            printf("3=balance, 4=exit\n\n");
            break;
        }
    }
    return 0;
}