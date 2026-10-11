#include "adc.h"



/*ADC 1-Channel1*/
void ADC1_Init(void)
{
	/*Enable GPIOA Clock*/
	RCC->AHB1ENR |= (1U<<0);

	/*Set Port mode */
	GPIOA->MODER |= (1U<<2);
	GPIOA->MODER |= (1U<<3);

	/*Enable ADC1 clock*/
	RCC->APB2ENR |= (1U << 8);

	/*Enbale ADC1 */
	ADC1->CR2 |= (1U<<0);

	/*Set sequence length*/
	ADC1->SQR3  = 0x00;

	/*Set sequence channel 1 */
	ADC1->SQR3 |= (1U<<0);

}

void start_conversion(void)
{
	/*Set continuous conversion*/
	ADC1->CR2 |= (1U<<1);

	/*Enable conversion */
	ADC1->CR2 |= (1U<<30);
}

uint32_t read_ADC1(void)
{
	/*Wait until conversion is complete*/
	while(!(ADC1->SR & (1U<<1))){}

	return ADC1->DR;
}
