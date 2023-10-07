/*
 * Port.h
 *
 *  Created on: Oct 7, 2023
 *      Author: ERoshdy
 */

#ifndef PORT_DRIVER_PORT_H_
#define PORT_DRIVER_PORT_H_

#include "stdint.h"  // Include the standard integer types for portability

// Define a structure (Port_ConfigType), which is currently empty.
// This structure might be used for configuration settings for the port driver.
// However, it's currently not defined with any members.

typedef struct
{
    // Add configuration members here.
} Port_ConfigType;

// Function prototype for Port_Init.
// This function is likely responsible for initializing and configuring the GPIO port.
void Port_Init(void);

#endif /* PORT_DRIVER_PORT_H_ */
