/**
 * DoroboLib32 FFT (DFFT)
 *
 * function for simple fft to detect 100Hz or 125Hz modulated signals
 *
 * Copyright (c) 2016 Laurent Schröder, Claus Fühner
 */

#ifndef DOROBO32_INC_FFT_H_
#define DOROBO32_INC_FFT_H_

/*
 * The signals that can be detected by the function fft_simple()
 */
enum DFFT_FFT_FREQ_E
{
    FFT_FREQ100,    //< 100Hz
    FFT_FREQ125     //< 125Hz
};

/**
 * FFT initialization.
 */
void fft_init();

/**
 * @brief   Start sampling from digital pin_no and perform fft over the samples.
 *
 * @param   fft_freq
 *          The frequency that needs to be detected
 *
 * @param   pin_no
 *          digital pin that is used for sampling
 *
 * @return  the compliance of the measured signal with the signal that is to be
 * detected. A value above 1200 indicates compliance.
 */
uint16_t fft_simple(enum DFFT_FFT_FREQ_E fft_freq, enum DD_PINS_E pin_no);

#endif /* DOROBO32_INC_FFT_H_ */
