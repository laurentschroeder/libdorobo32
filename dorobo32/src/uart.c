/*
 * uart.c
 *
 *  Created on: Mar 3, 2016
 *      Author: laurent
 */

#include "stm32f0xx_hal.h"
#include "string.h"
#include "uart.h"

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;

static UART_HandleTypeDef* select_uart(enum DUART_UART_E euart);

void uart_send(enum DUART_UART_E euart, char* msg)
{
    UART_HandleTypeDef *current_huart = &huart1;
    current_huart = select_uart(euart);
    HAL_UART_Transmit_IT(current_huart, msg, strlen(msg));
}

void uart_send_buffer(enum DUART_UART_E uart, uint8_t *pbuffer, uint16_t size)
{
    UART_HandleTypeDef *current_huart = &huart1;
    current_huart = select_uart(uart);
    HAL_UART_Transmit_IT(current_huart, pbuffer, size);
}

void uart_receive(enum DUART_UART_E euart, uint8_t* pbuffer, uint16_t size)
{
    UART_HandleTypeDef *current_huart = &huart1;
    current_huart = select_uart(euart);
    HAL_UART_Receive_IT(current_huart, pbuffer, size);
}

void USART1_IRQHandler(void)
{
  HAL_UART_IRQHandler(&huart1);
}

void USART2_IRQHandler(void)
{
  HAL_UART_IRQHandler(&huart2);
}

static UART_HandleTypeDef* select_uart(enum DUART_UART_E euart)
{
    UART_HandleTypeDef *current_huart = &huart1;
    switch(euart)
    {
        case UART1:
        {
            current_huart = &huart1;
            break;
        }
        case UART2:
        {
            current_huart = &huart2;
            break;
        }
        default:
            current_huart = &huart1;
            break;
    }
    return current_huart;
}
