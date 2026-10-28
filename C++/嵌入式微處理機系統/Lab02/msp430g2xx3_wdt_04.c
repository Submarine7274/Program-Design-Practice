#include <msp430.h>

#define RedLED BIT0
#define Button BIT3

void main(void)
{
 WDTCTL = WDTPW|WDTHOLD;

 P1DIR |= RedLED;
 P1OUT &= ~RedLED;
 // Configure button on P1.3
 P1DIR &= ~Button; // Set P1.3 as input
 P1REN |= Button; // Enable pull-up/down resistor
 P1OUT |= Button; // Select pull-up
 // Configure interrupt on P1.3
 P1IE |= Button;
 P1IES |= Button;
 P1IFG &= ~Button; // Clear interrupt flag

 _enable_interrupts();

 LPM3;
}

#pragma vector=PORT1_VECTOR
__interrupt void PORT1_ISR(void){
 P1OUT = RedLED;
 BCSCTL3 |= LFXT1S_2; // ACLK = VLO
 WDTCTL = WDT_ARST_1000;
 P1IFG &= ~Button;
}

