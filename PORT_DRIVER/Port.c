/*
 * Port.c
 *
 *  Created on: Oct 7, 2023
 *      Author: ERoshdy
 */

#include "Port.h"

// Calculate the base address of the GPIO port based on the port number
#define ADDRESS_PORTN(port) (0x40004000 + ((port % 4) << 12) + (port / 4) * (2 << 16))

// Register definitions for clock control and port readiness
#define SYSCTL_RCGCGPIO_R (*((volatile unsigned long *)0x400FE608))
#define SYSCTL_PRGPIO_R   (*((volatile unsigned long *)0x400FEA08))

void Port_Init(void)
{
    uint8_t inputPins  = 0x00;          // Variable to specify input pins
    uint8_t outputPins = 0x0E;          // Variable to specify output pins (pins 1, 2, and 3)
    uint8_t port = 5;                   // The GPIO port number being configured (port 5 in this case)

    // Enable the clock for the specified GPIO port
    SYSCTL_RCGCGPIO_R |= (1 << port);

    // Wait until the GPIO port is ready for access
    while ((SYSCTL_PRGPIO_R & (1 << port)) == 0);

    // Calculate the base address of the GPIO port
    unsigned int base_address = ADDRESS_PORTN(port);

    // Unlock the GPIO port using the magic number (LOCK_R)
    (*((volatile unsigned long *)(base_address + 0x520))) = 0x4c4f434b;

    // Configure the pins as both input and output as specified (CR_R)
    (*((volatile unsigned long *)(base_address + 0x524))) =  (inputPins | outputPins);

    // Set the pins as input by clearing their corresponding output bits (DIR_R)
    (*((volatile unsigned long *)(base_address + 0x400))) = ~(inputPins & ~outputPins);

    // Set the pins as output by setting their corresponding output bits (PUR_R)
    (*((volatile unsigned long *)(base_address + 0x510))) |= (inputPins | outputPins);

    // Enable digitalization of input and output pins (DEN_R)
    (*((volatile unsigned long *)(base_address + 0x51C))) |= (inputPins | outputPins);
}
