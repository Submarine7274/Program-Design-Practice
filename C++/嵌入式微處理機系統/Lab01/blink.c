#include <msp430.h>

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer

    P1DIR |= BIT0;              // Set P1.0 as output (LED)
    P1OUT &= ~BIT0;             // Initialize LED off

    while (1) {
        P1OUT ^= BIT0;          // Toggle LED
        __delay_cycles(100000); // Delay ~100ms at 1MHz clock
    }
}