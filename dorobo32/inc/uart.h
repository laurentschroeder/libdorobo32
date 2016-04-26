/*
 * uart.h
 *
 *  Created on: Mar 3, 2016
 *      Author: laurent
 */

#ifndef DOROBO32_INC_UART_H_
#define DOROBO32_INC_UART_H_

enum EUART
{
  UART1, UART2
};

void uart_send(enum EUART, char*);
void uart_receive(enum EUART euart, uint8_t* pbuffer, uint16_t size);

#endif /* DOROBO32_INC_UART_H_ */
