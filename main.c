// Program Name: Gray Code Incrementer
// Author: Fayyaz Nisar Shaikh
// Date: 24th August 2025


#include <msp430.h>

void main(void){
    
    WDTCTL = WDTPW | WDTHOLD;
    // to hold watchdog timer (not needed in this code)

    P4OUT &= ~(BIT6); // sets P4.6 to 0
    P4DIR |= BIT6;    // sets P4.6 to output
    P1OUT &= ~(BIT0); // sets P1.0 to 0
    P1DIR |= BIT0;    // sets P1.0 to output

    PM5CTL0 &= ~LOCKLPM5; // unlock the gpio pins from power saving mode


    while(1){

        P4OUT ^= ~(BIT6);
        P1OUT ^= ~(BIT0);
        __delay_cycles(1000000);
        P1OUT ^= BIT0;
        __delay_cycles(1000000);
        P4OUT ^= BIT6;
        __delay_cycles(1000000);
        P1OUT ^= ~(BIT0);
        __delay_cycles(1000000);
        P4OUT ^= ~(BIT6);

        // toggling- gray code incrementer 

    }


}