/*
 * fft.h
 *
 *  Created on: Mar 6, 2016
 *      Author: laurent
 */

#ifndef DOROBO32_INC_FFT_H_
#define DOROBO32_INC_FFT_H_

enum EFFT_FREQ
{
	FFT_FREQ100,
	FFT_FREQ125
};

uint16_t fft_simple(enum EFFT_FREQ efft_freq, enum EDIGITAL epin);

#endif /* DOROBO32_INC_FFT_H_ */
