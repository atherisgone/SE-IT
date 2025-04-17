/*
 * File:   Lab 2.c
 * Author: Tanish
 *
 * Created on 14 January, 2025, 2:02 PM
 */

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <pic18f4550.h>

void main(void) {
    int src[] = {0x02, 0x03, 0x05, 0x08};
    int dest[] = {0x00, 0x00, 0x00, 0x00};
    
    for (int i = 0; i <= 3; i++) {
        dest[i] = src[i];
    }
    
    TRISD = 0x00; 
    
    for (int i = 0; i <= 3; i++) {
        PORTD = dest[i];
        for(int n=0;n<1000;n++){
            for(int j=0;j<500;j++){
        }
    }
    }
    
    return;
}
