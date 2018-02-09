/*
 * File:   main.c
 * Author: ColdPod Project Authors
 * 
 * Copyright (C) 2018 ColdPod Project Authors. All rights reserved.
 */
#include <xc.h>
#include "delays.h"

// Define ports to peripherals
// Outputs
#define LED1 PORTDbits.RD0
#define LED2 PORTDbits.RD1 
#define LED3 PORTDbits.RD2 
#define MOS_GT PORTDbits.RD3 
// Inputs
#define ESP1 PORTDbits.RD4 
#define ESP2 PORTDbits.RD5 
#define ESP3 PORTDbits.RD6 

void main(void) {

    // Configure TRISD register
    TRISD = 0b01110000;
    
    // Main loop
    while (1){
        // Check ESP1
        // Coldest
        while (ESP1 == 1){
            // Turn on LED1
            LED1 = 1; LED2 = 0; LED3 = 0;
            // MOSFET gate cycle
            MOS_GT = 1;
            delay_ms(10000);
            MOS_GT = 0;
            delay_ms(2000);
        }
        // Check ESP2
        // Colder
        while (ESP2 == 1){
            // Turn on LED1, 2
            LED1 = 1; LED2 = 1; LED3 = 0;
            // MOSFET gate cycle
            MOS_GT = 1;
            delay_ms(10000);
            MOS_GT = 0;
            delay_ms(4000);
        }
        // Check ESP3
        // Cold
        while (ESP3 == 1){
            // Turn on LED1, 2, 3
            LED1 = 1; LED2 = 1; LED3 = 1;
            // MOSFET gate cycle
            MOS_GT = 1;
            delay_ms(10000);
            MOS_GT = 0;
            delay_ms(6000);
        }       
    }
}
