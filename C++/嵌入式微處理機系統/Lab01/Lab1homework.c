#include"msp430g2553.h"
volatile int count = 0;
void main(void){
    WDTCTL = WDTPW | WDTHOLD; //關閉WDT Timer
    P1DIR |= (BIT0|BIT6);
    P1OUT |= BIT0;
    P1OUT &= ~BIT6;

    P1DIR &= ~BIT3;//P1.3(按鈕為輸入)
    P1REN |= BIT3; //電阻啟用佔存器
    P1OUT |= BIT3; //上拉電阻(未按下時高電位)
    while(true){
        if(!(P1IN &BIT3)){
            __delay_cycles(20000);
            if(!(P1IN &BIT3)){
                count++;
                if(x%2 ==0){
                    P1OUT |= BIT0;
                    P1OUT &= ~BIT6;
                }
                else{
                    P1OUT &= ~BIT0;
                    P1OUT |= BIT6;
                }
            }
            while(!(P1IN &BIT3));
        }
    }
}
//下面是 Interrupt的寫法
#include
volatile int count = 0;
void main(void){
    WDTCTL = WDTPW | WDTHOLD;
    P1DIR |= (BIT0 | BIT6);
    P1OUT |= BIT0;
    P1OUT &= ~BIT6;
    P1DIR &= ~BIT3;
    P1REN |= BIT3;
    P1OUT |= BIT3;
    P1IE |= BIT3;
    P1IES |= BIT3;
    P1IFG &= ~BIT3;
    __bis_SR_register(GIE);
    while(true){
        __low_power_mode_3();
    }
}
#pragma vector=PORT1_VECTOR 
__interrupt void Port_1(void) {
    count++;
    if(x%2 ==0){
        P1OUT |= BIT0;
        P1OUT &= ~BIT6;
    }
    else{
        P1OUT &= ~BIT0;
        P1OUT |= BIT6;
    }
	P1IFG &= ~BIT3; // Clear interrupt flag 
}
