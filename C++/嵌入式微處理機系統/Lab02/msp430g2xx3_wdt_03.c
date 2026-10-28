#include <msp430.h>

#define RedLED BIT0
#define GreenLED BIT6
#define ToggleLeds (P1OUT ^= RedLED|GreenLED)

void main(void)
{
 BCSCTL2 |= DIVS_3;
 WDTCTL = WDT_MDLY_32;
 IE1 |= WDTIE;
 
 P1DIR = RedLED|GreenLED;
 P1OUT = RedLED;

 _enable_interrupts();
 
 LPM1;
}

#pragma vector=WDT_VECTOR
__interrupt void WDT(void){
 ToggleLeds;
}
