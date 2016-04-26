/**
 * DoroboLib32 Sammel-Header
 *
 * Initialisierung für die DoroboLib32 und die gebrächlichsten Module.
 *
 * Copyright (c) 2016 Laurent Schröder, Claus Fühner
 */

#ifndef DOROBO32_INC_DOROBO32_H_
#define DOROBO32_INC_DOROBO32_H_

#include "stdint.h"

#include "adc.h"
#include "digital.h"
#include "uart.h"

/**
 * Board-Grundinitialisierung und Initialisierung der Module adc, digital, pwm und uart
 */
void dorobo_init();

/*
 * @brief   set green led on or off
 *
 * @param   level as defined in DD_PINLEVEL_E
 */
void led_green(enum DD_PINLEVEL_E level);

/*
 * @brief   set red led on or off
 *
 * @param   level as defined in DD_PINLEVEL_E
 */
void led_red(enum DD_PINLEVEL_E level);

#endif /* DOROBO32_INC_DOROBO32_H_ */
