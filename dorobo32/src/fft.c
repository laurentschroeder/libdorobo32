/*
 * fft_simple.c
 *
 *  Created on: Apr 20, 2016
 *      Author: laurent
 */

#include "digital.h"
#include "stm32f0xx_hal.h"
#include "cmsis_os.h"
#include <stdlib.h>
#include "fft.h"

extern TIM_HandleTypeDef htim6;

#define SAMPLES 40
uint8_t fft_sample_index = 0;
uint8_t fft_samples_ready = 0;
enum EDIGITAL sample_pin;



const static int8_t STEUERVEKTOR_RE8_[] = {
  100,71,0,-71,-100,-71,0,71,100,71,0,-71,-100,-71,0,71,100,71,0,-71,-100,
  -71,0,71,100,71,0,-71,-100,-71,0,71,100,71,0,-71,-100,-71,0,71};
const static int8_t STEUERVEKTOR_IM8_[] = {
  0,-71,-100,-71,0,71,100,71,0,-71,-100,-71,0,71,100,71,0,-71,-100,-71,0,
  71,100,71,0,-71,-100,-71,0,71,100,71,0,-71,-100,-71,0,71,100,71};
const static int8_t STEUERVEKTOR_RE10_[] = {
  100,81,31,-31,-81,-100,-81,-31,31,81,100,81,31,-31,-81,-100,-81,-31,31,81,
  100,81,31,-31,-81,-100,-81,-31,31,81,100,81,31,-31,-81,-100,-81,-31,31,81};
const static int8_t STEUERVEKTOR_IM10_[] = {
  0,-59,-95,-95,-59,0,59,95,95,59,0,-59,-95,-95,-59,0,59,95,95,59,0,-59,
  -95,-95,-59,0,59,95,95,59,0,-59,-95,-95,-59,0,59,95,95,59};

static uint8_t signal1_[SAMPLES];

uint16_t fft_simple(enum EFFT_FREQ efft_freq, enum EDIGITAL epin)
{
	sample_pin = epin;
	fft_samples_ready = 0;
	HAL_TIM_Base_Start_IT(&htim6);
	int16_t real = 0;
	int16_t imag = 0;
	while(fft_samples_ready == 0)
	{
	    taskYIELD();
	}
	int8_t *steuervektor_re;
	int8_t *steuervektor_im;
	switch(efft_freq)
	{
		case FFT_FREQ100:
		{
			steuervektor_re = STEUERVEKTOR_RE10_;
			steuervektor_im = STEUERVEKTOR_IM10_;
			break;
		}
		case FFT_FREQ125:
		{
			steuervektor_re = STEUERVEKTOR_RE8_;
			steuervektor_im = STEUERVEKTOR_IM8_;
			break;
		}
	}
	uint8_t i;
	for(i = 0; i < SAMPLES; i++)
	{
		if(signal1_[i])
		{
			real += steuervektor_re[i];
			imag += steuervektor_im[i];
		}
	}
	return abs(real) + abs(imag);
}

void fft_get_samples()
{
	if(fft_sample_index == SAMPLES)
	{
		HAL_TIM_Base_Stop_IT(&htim6);
		fft_sample_index = 0;
		fft_samples_ready = 1;
	}
	else
	{
		signal1_[fft_sample_index] = get_pin(sample_pin);
		fft_sample_index++;
	}
}

/**
* @brief This function handles TIM6 global and DAC channel underrun error interrupts.
*/
void TIM6_DAC_IRQHandler(void)
{
    /* TIM Update event */
    if(__HAL_TIM_GET_FLAG(&htim6, TIM_FLAG_UPDATE) != RESET)
    {
        if(__HAL_TIM_GET_IT_SOURCE(&htim6, TIM_IT_UPDATE) !=RESET)
        {
            __HAL_TIM_CLEAR_IT(&htim6, TIM_IT_UPDATE);
            fft_get_samples();
        }
    }
}
