/*
 * File:   Exp5.c
 * Author: Tanish
 *
 * Created on 11 February, 2025, 2:16 PM
 */


#include <xc.h>
#include <pic18f4550.h>

void delay(unsigned int time) {
    unsigned int i, j;
    for (i = 0; i < time; i++) {
        for (j = 0; j < 1000; j++) {
            asm("NOP");
        }
    }
}

void main(void) {
    TRISD=0x00;
    LATD=0xFF;
    TRISB = 0x00;
    LATB = 0x00;

    while(1){
        LATD=~LATD;
        delay(200);
    }
    return;
}
