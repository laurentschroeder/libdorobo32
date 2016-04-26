/**
 * DoroboLib32 Digital IO (DD)
 *
 * Functions to read and set digitial IO pins.
 *
 * Copyright (c) 2016 Laurent Schröder, Claus Fühner
 */

#ifndef DOROBO32_INC_DIGITAL_H_
#define DOROBO32_INC_DIGITAL_H_

#include "stdint.h"

/**
 * Dorobo32 pins available for digital i/o
 */
enum DD_PINS_E
{
    DD_PIN_PD14,  //< digital i/o pin D14
    DD_PIN_PD15,  //< digital i/o pin PD15
    DD_PIN_PC8,   //< digital i/o pin PC8
    DD_PIN_PC9,   //< digital i/o pin PC9
    DD_PIN_PA8,   //< digital i/o pin PA8
    DD_PIN_PC13,  //< digital i/o pin PC13
    DD_PIN_PB11,  //< digital i/o pin PB11
    DD_PIN_PB10,  //< digital i/o pin PB10
    DD_PIN_PE14,  //< digital i/o pin PE14
    DD_PIN_PE11,  //< digital i/o pin PE11
    DD_PIN_PE9,   //< digital i/o pin PE9
    DD_PIN_PB1    //< digital i/o pin PB1
};

/**
 * Dorobo32 DIP switches
 */
enum DD_DIPS_E
{
    DD_DIP1,    //< dip switch 1
    DD_DIP2,    //< dip switch 2
    DD_DIP3,    //< dip switch 3
    DD_DIP4     //< dip switch 4
};

/**
 * Pin signal levels
 */
enum DD_PINLEVEL_E
{
    DD_LEVEL_LOW,     //< digital low
    DD_LEVEL_HIGH     //< digital high
};

/**
 * pin configuration
 */
enum DD_PINCONFIG_E
{
    DD_CFG_OUTPUT,      //< pin output
    DD_CFG_INPUT_PULLUP, //< pin input with pullup
    DD_CFG_INPUT_PULLDOWN,
    DD_CFG_INPUT_NOPULL
};

void digital_init();

/**
 * @brief Configure digital pin direction and pullup/pulldown
 *
 * @param   pin_no
 *          pin to configure
 *
 * @param   direction
 *          predefined configuration as defined in DD_PINCONFIG_E
 */
void digital_config_pin(enum DD_PINS_E pin_no, enum DD_PINCONFIG_E direction);

/**
 * @brief   Set pin level of pin pin_no
 *
 * @param   pin_no
 *          digitial pin that is to be set
 *
 * @param   level
 *          The desired pin level. Values can be DD_LEVEL_LOW or DD_LEVEL_HIGH
 */
void digital_set_pin(enum DD_PINS_E pin_no, enum DD_PINLEVEL_E level);

/**
 * @brief   Get signal level from given pin.
 *
 * @param   pin_no
 *          Pin to read from
 *
 * @return  pin signal level as defined in DD_PINLEVEL_E
 */
enum DD_PINLEVEL_E digital_get_pin(enum DD_PINS_E pin_no);

/**
 * @brief   Get signal level from given dip switch.
 *
 * @param   dip_no
 *          dip to read from
 *
 * @return  dip signal level as defined in DD_PINLEVEL_E
 */
enum DD_PINLEVEL_E digital_get_dip(enum DD_DIPS_E dip_no);

#endif /* DOROBO32_INC_DIGITAL_H_ */
