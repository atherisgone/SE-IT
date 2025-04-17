/*
 * File:   Exp1.c
 * Author: Tanish
 *
 * Created on 11 February, 2025, 10:11 PM
 */


#include <xc.h>
#include <pic18f4550.h>

void main(void) {
    TRISD = 0x00; 
    LATD = 0x00;   

    unsigned char result = 3 + 6;

    LATD = result; 

    while (1);  
}
