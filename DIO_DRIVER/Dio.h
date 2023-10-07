/*
 * Dio.h
 *
 *  Created on: Oct 7, 2023
 *      Author: ERoshdy
 */

#ifndef DIO_DRIVER_DIO_H_
#define DIO_DRIVER_DIO_H_

#include "stdint.h"  // Include the standard integer types for portability

// Define data types for DIO channels, ports, levels, and port levels.
// These typedefs make the code more readable and portable.
typedef uint8_t                 Dio_ChannelType;
typedef uint8_t                 Dio_PortType;
typedef uint8_t                 Dio_LevelType;
typedef uint8_t                 Dio_PortLevelType;

// Function prototypes for reading and writing DIO channels and ports.
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);

#endif /* DIO_DRIVER_DIO_H_ */
