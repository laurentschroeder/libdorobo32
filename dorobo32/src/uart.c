/*
 * uart.c
 *
 *  Created on: Mar 3, 2016
 *      Author: laurent
 */

#include "stm32f0xx_hal.h"
#include "string.h"

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;

void uart_send(char* msg)
{
  HAL_UART_Transmit_IT(&huart1, msg, strlen(msg));
}

void USART1_IRQHandler(void)
{
  HAL_UART_IRQHandler(&huart1);
}

void USART2_IRQHandler(void)
{
  HAL_UART_IRQHandler(&huart2);
}
