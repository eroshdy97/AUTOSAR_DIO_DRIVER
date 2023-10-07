#include "Std_Types.h"  // Include standard data types (Assumed to be defined elsewhere)
#include "Dio.h"        // Include Dio data types and macros (Assumed to be defined elsewhere)

// Calculate the base address of the GPIO port based on the port number
#define ADDRESS_PORTN(port) (0x40004000 + ((port % 4) << 12) + (port / 4) * (2 << 16))

// Function to read and return the value of a specific digital input channel
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    // Read and return the value of the specified pins on the GPIO port
    return (((volatile unsigned long *)(ADDRESS_PORTN(ChannelId / 8)))[1 << (ChannelId % 8)] >> (ChannelId % 8));
}

// Function to write a value to a specific digital output channel
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    // Clear the specified pins' values by writing 0
    ((volatile unsigned long *)(ADDRESS_PORTN(ChannelId / 8)))[1 << (ChannelId % 8)] = 0;

    // Write the specified value to the pins on the GPIO port
    ((volatile unsigned long *)(ADDRESS_PORTN(ChannelId / 8)))[1 << (ChannelId % 8)] = (Level << (ChannelId % 8));
}

// Function to read and return the value of all pins on a specific digital input port
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
    // Read and return the value of the specified pins on the GPIO port
    return ((volatile unsigned long *)(ADDRESS_PORTN(PortId)))[0xFF];
}

// Function to write a value to all pins on a specific digital output port
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
    // Clear the specified pins' values by writing 0
    ((volatile unsigned long *)(ADDRESS_PORTN(PortId)))[0xFF] = 0;

    // Write the specified value to the pins on the GPIO port
    ((volatile unsigned long *)(ADDRESS_PORTN(PortId)))[0xFF] = Level;
}
