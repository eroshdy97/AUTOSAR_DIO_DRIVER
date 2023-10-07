#include "PORT_DRIVER/Port.h"
#include "DIO_DRIVER/Dio.h"
#include "Std_Types.h"

#define LED_RED_PIN_ID         41
#define LED_BLUE_PIN_ID        42
#define LED_GREEN_PIN_ID       43


void delay_ms(uint32_t d)
{
    uint32_t i, j;
    for (i = 0; i < d; ++i) {
        for (j = 0; j < 3180; ++j) {

        }
    }
}

int main(void)
{

    Port_Init();
    while(1)
    {
        Dio_WriteChannel(LED_GREEN_PIN_ID, STD_LOW);
        Dio_WriteChannel(LED_RED_PIN_ID, STD_HIGH);
        delay_ms(500);
        Dio_WriteChannel(LED_RED_PIN_ID, STD_LOW);
        Dio_WriteChannel(LED_BLUE_PIN_ID, STD_HIGH);
        delay_ms(500);
        Dio_WriteChannel(LED_BLUE_PIN_ID, STD_LOW);
        Dio_WriteChannel(LED_GREEN_PIN_ID, STD_HIGH);
        delay_ms(500);

    }

    return 0;
}
