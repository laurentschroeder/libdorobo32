/**
 * DoroboLib32 UART (DUART)
 *
 * Functions for UART communication.
 *
 * Copyright (c) 2016 Laurent Schröder, Claus Fühner
 */

#ifndef DOROBO32_INC_UART_H_
#define DOROBO32_INC_UART_H_

enum DUART_UART_E
{
    UART1,    //< UART1 instance
    UART2     //< UART2 instance
};

/**
 * UART initialization
 */
void uart_init();

/**
 * @brief   send string via UART
 *
 * @param   uart
 *          The UART instance to be used as defined in DUART_UART_E
 *
 * @param   string
 *          char* string to be transmitted
 */
void uart_send(enum DUART_UART_E uart, char* string);

/**
 * @brief   send buffer via UART
 *
 * @param   uart
 *          The UART instance to be used as defined in DUART_UART_E
 *
 * @param   *pbuffer
 *          pointer to buffer
 *
 * @param   size
 *          number of character to be sent
 */
void uart_send_buffer(enum DUART_UART_E uart, uint8_t *pbuffer, uint16_t size);

/**
 * @brief   Receive messages from UART
 *
 * @param   uart
 *          UART instance to be used as defined in DUART_UART_E
 *
 * @param   *pbuffer
 *          buffer to store received data
 *
 * @param   size
 *          number of bytes to be received
 */
void uart_receive(enum DUART_UART_E uart, uint8_t* pbuffer, uint16_t size);

#endif /* DOROBO32_INC_UART_H_ */
