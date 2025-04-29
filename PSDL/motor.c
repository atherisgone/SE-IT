#include <xc.h>
#include <pic18f4550.h>

#define _XTAL_FREQ 8000000  // Define oscillator frequency for __delay_ms() if needed

void timer2Init(void) {
    T2CON = 0b00000010; // Timer2 ON, prescaler = 16
    PR2 = 0x95;         // Set period register
    TMR2ON = 1;         // Start Timer2
}

void delay(unsigned int time) {
    while(time--) {
        __delay_ms(1);  // Using built-in delay (assuming _XTAL_FREQ defined)
    }
}

void main(void) {
    TRISCbits.TRISC1 = 0; // Set RC1 as output
    TRISCbits.TRISC2 = 0; // Set RC2 as output
    LATCbits.LATC1 = 0;   // Clear RC1

    CCP1CON = 0b00111100; // PWM mode
    CCPR1L = 0x0F;        // Initial duty cycle

    timer2Init();         // Initialize Timer2

    while(1) {
        for(unsigned int i = 15; i <= 150; i++) {
            CCPR1L = i;
            delay(1);
        }
        for(unsigned int i = 150; i >= 15; i--) {
            CCPR1L = i;
            delay(1);
        }
    }
}
