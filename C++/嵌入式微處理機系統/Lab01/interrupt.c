#include <msp430.h> 
void main(void) { 
	WDTCTL = WDTPW | WDTHOLD; // Stop watchdog timer 
	// Configure LED on P1.0 
	P1DIR |= BIT0; // Set P1.0 as output 
	P1OUT &= ~BIT0; // LED off initially 
	// Configure button on P1.3 
	P1DIR &= ~BIT3; // Set P1.3 as input 
	P1REN |= BIT3; // Enable pull-up/down resistor 
	P1OUT |= BIT3; // Select pull-up 
	// Configure interrupt on P1.3 
	P1IE |= BIT3; // Enable interrupt for P1.3 
	P1IES |= BIT3; // Trigger on high-to-low (button press) 
	P1IFG &= ~BIT3; // Clear interrupt flag 
	__bis_SR_register(GIE); // Enable global interrupts 
	while (1) { 
		__low_power_mode_3(); // Enter low power mode until interrupt } 
	} // Port 1 interrupt service routine 
}
	#pragma vector=PORT1_VECTOR 
	__interrupt void Port_1(void) { 
		P1OUT ^= BIT0; // Toggle LED 
		P1IFG &= ~BIT3; // Clear interrupt flag 
	}
