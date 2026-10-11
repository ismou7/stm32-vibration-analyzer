/*
 * adc.h
 *
 *  Created on: 8 Oct 2026
 *      Author: ouadd
 */

#ifndef ADC_H_
#define ADC_H_

#include "stm32f4xx.h"

#define SR_UIF  (1U<<0)

void ADC1_Init(void);
void start_conversion(void);
uint32_t read_ADC1(void);

#endif /* ADC_H_ */
