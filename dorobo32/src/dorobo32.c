/**
 * DoroboLib32 Sammel-Initialisierung
 *
 * Initialisierung für die DoroboLib32 und die gebrächlichsten Module.
 *
 * Copyright (c) 2016 Laurent Schröder, Claus Fühner
 */


#include <dorobo32.h>
#include "stm32f0xx_hal.h"

// Die main()-Funktion aus der CubeMX-generierten main() muss in
// init() abgespeichert und hinzugelinkt werden.
extern void init();

void dorobo_init()
{
    init();
    digital_init();
}

void led_green(enum DD_PINLEVEL_E level)
{
    HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin,  level);
}

void led_red(enum DD_PINLEVEL_E level)
{
    HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin,  level);
}
