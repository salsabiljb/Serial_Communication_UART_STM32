#include "RccConfig.h"
#include "Delay.h"
#include "ADC.h"
#include "UART.h"
#include "ASCII.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    /* Configure the system clock */
    SysClockConfig();

    /* Initialize all configured peripherals */
    // UART configuration
		TIM6Config ();
    Uart2Config();

    // ADC initialization
    ADC_Init();
    ADC_Enable();

    while (1) {
        // ADC code
        ADC_Start(1); // Start ADC conversion for channel 1
        ADC_WaitForConv();
        uint16_t raw = ADC_GetVal();

        // Calculate voltage
        float vin = raw * (3.3 / 4096);

        // Convert raw value to ASCII string
        char* msg2 = shift_digits(raw);

        // Create message string
        char msg[50];
        sprintf(msg, "ASCII Code: %s, Voltage: %.2f V\r\n", msg2, vin);

        // Send message via UART
        UART2_SendString(USART2, (uint8_t*)msg, strlen(msg), 300);

        // Delay for 1 second
        Delay_ms(1000);
			
        // Free memory allocated for ASCII string
        free(msg2);

    }

}
