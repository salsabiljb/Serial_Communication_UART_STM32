#ifndef UART_H
#define UART_H

#include "stm32f4xx.h"

void Uart2Config(void);
void UART2_SendChar(uint8_t c);
void UART2_SendString(USART_TypeDef *USARTx, uint8_t *string, uint32_t length, uint32_t timeout);
uint8_t UART2_GetChar(void);


#endif /* UART_H */
