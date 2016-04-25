/*
 * adc.h
 *
 *  Created on: Mar 3, 2016
 *      Author: laurent
 */

#ifndef DOROBO32_INC_ADC_H_
#define DOROBO32_INC_ADC_H_

#include "stdint.h"

enum EADC_CHANNEL
{
  ADC_CHANNEL0,
  ADC_CHANNEL1,
  ADC_CHANNEL2,
  ADC_CHANNEL3,
  ADC_CHANNEL4,
  ADC_CHANNEL5,
  ADC_CHANNEL6,
  ADC_CHANNEL7,
  ADC_CHANNEL8,
  ADC_CHANNEL9
};

uint32_t adc_get_value(enum EADC_CHANNEL);

#endif /* DOROBO32_INC_ADC_H_ */
