/*
 * uart.h
 *
 *  Created on: 7 Oct 2026
 *      Author: ouadd
 */

#ifndef UART_H_
#define UART_H_


#include "stm32f4xx.h"


void UART2_TX_Init(void);
void uart_write(int ch);
#endif /* UART_H_ */
