//*****************************************************************************
// Surveyor's Wheel Project for ECE 202
// Code by Kai Brennan
//*****************************************************************************
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h> // Included the string.h library for strlen
#include "SURVEYORSWHEEL_PIO_util.h"

int main(void) {
    // Initialize the UART.
    UARTsetup(9600);

    // Hello!
	UARTprintf("Surveyor's Wheel Initialized\n\n");
	
	// Your code goes here....

    // We are finished. Since this is an embedded system, hang around
    while(1) {
    }
}

