#include "uart.h"

#define UART2ENR (1U<<17)
#define GPIOAENR (1U<<0)
#define TXESR    (1U<<7)
#define UARTBAUDRATE 115200
#define SYSCLK 16000000

void UART2_TX_Init(void)
{

	/*Enable GPIOA clock*/
	RCC->AHB1ENR |= GPIOAENR;

	/*Set PA2  to alternate funktion mode*/

	GPIOA->MODER &= ~(1U<<4);
	GPIOA->MODER |= (1U<<5);

    GPIOA->AFR[0] |= (1U<<8);
    GPIOA->AFR[0] |= (1U<<9);
    GPIOA->AFR[0] |= (1U<<10);
    GPIOA->AFR[0] &= ~(1U<<11);

	/*Enable UART1 Clock*/
    RCC->APB1ENR |= UART2ENR;

    /*Enable TE Transmitter*/
    USART2->CR1 |= (1U<<3);

    /*Set baudrate */

    USART2->BRR = ((SYSCLK + (UARTBAUDRATE/2U))/UARTBAUDRATE);

    /*Enable UART1*/
    USART2->CR1 |= (1U<<13);

}

void uart_write(int ch)
{
	/*Wait until data register is empty*/
	while(!(USART2->SR & TXESR)){}

	/*Write to the transmitter data register*/
	USART2->DR = (ch & 0xFF);
}
