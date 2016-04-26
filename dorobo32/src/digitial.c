/**
 * DoroboLib32 Digital IO
 *
 * Funktionen für die Manipulation der digitalen IO Pins.
 *
 * Copyright (c) 2016 Laurent Schröder, Claus Fühner
 */

#include "stm32f0xx_hal.h"
#include "mxconstants.h"
#include "digital.h"

typedef struct
{
    GPIO_TypeDef* port;
    uint16_t pin;
} pin_t;

static void selectPin(enum DD_PINS_E pin_no, pin_t* currentPin);

void digital_init()
{

}

void digital_config_pin(enum DD_PINS_E pin_no, enum DD_PINCONFIG_E direction)
{

}

void digital_set_pin(enum DD_PINS_E pin_no, enum DD_PINLEVEL_E level)
{
    pin_t selectedPin;
    selectPin(pin_no, &selectedPin);
    HAL_GPIO_WritePin(selectedPin.port, selectedPin.pin, level);
}

enum DD_PINLEVEL_E digital_get_pin(enum DD_PINS_E pin_no)
{
    pin_t selectedPin;
    selectPin(pin_no, &selectedPin);
    return HAL_GPIO_ReadPin(selectedPin.port, selectedPin.pin);
}

enum DD_PINLEVEL_E digital_get_dip(enum DD_DIPS_E dip_no)
{
    enum DD_PINLEVEL_E level;
    switch (dip_no)
    {
    case DD_DIP1:
    {
        level = HAL_GPIO_ReadPin(DIP1_GPIO_Port, DIP1_Pin);
        break;
    }
    case DD_DIP2:
    {
        level = HAL_GPIO_ReadPin(DIP2_GPIO_Port, DIP2_Pin);
        break;
    }
    case DD_DIP3:
    {
        level = HAL_GPIO_ReadPin(DIP3_GPIO_Port, DIP3_Pin);
        break;
    }
    case DD_DIP4:
    {
        level = HAL_GPIO_ReadPin(DIP4_GPIO_Port, DIP4_Pin);
        break;
    }
    }
    return level;
}

static void selectPin(enum DD_PINS_E pin_no, pin_t* currentPin)
{
    switch (pin_no)
    {
    case DD_PIN_PD14:
    {
        currentPin->port = DIGITAL0_GPIO_Port;
        currentPin->pin = DIGITAL0_Pin;
        break;
    }
    case DD_PIN_PD15:
    {
        currentPin->port = DIGITAL1_GPIO_Port;
        currentPin->pin = DIGITAL1_Pin;
        break;
    }
    case DD_PIN_PC8:
    {
        currentPin->port = DIGITAL2_GPIO_Port;
        currentPin->pin = DIGITAL2_Pin;
        break;
    }
    case DD_PIN_PC9:
    {
        currentPin->port = DIGITAL3_GPIO_Port;
        currentPin->pin = DIGITAL3_Pin;
        break;
    }
    case DD_PIN_PA8:
    {
        currentPin->port = DIGITAL4_GPIO_Port;
        currentPin->pin = DIGITAL4_Pin;
        break;
    }
    case DD_PIN_PC13:
    {
        currentPin->port = DIGITAL5_GPIO_Port;
        currentPin->pin = DIGITAL5_Pin;
        break;
    }
    case DD_PIN_PB11:
    {
        currentPin->port = SERVO0_GPIO_Port;
        currentPin->pin = SERVO0_Pin;
        break;
    }
    case DD_PIN_PB10:
    {
        currentPin->port = SERVO1_GPIO_Port;
        currentPin->pin = SERVO1_Pin;
        break;
    }
    case DD_PIN_PE14:
    {
        currentPin->port = SERVO2_GPIO_Port;
        currentPin->pin = SERVO2_Pin;
        break;
    }
    case DD_PIN_PE11:
    {
        currentPin->port = SERVO3_GPIO_Port;
        currentPin->pin = SERVO3_Pin;
        break;
    }
    case DD_PIN_PE9:
    {
        currentPin->port = SERVO4_GPIO_Port;
        currentPin->pin = SERVO4_Pin;
        break;
    }
    case DD_PIN_PB1:
    {
        currentPin->port = SERVO5_GPIO_Port;
        currentPin->pin = SERVO5_Pin;
        break;
    }
    default:
    {
        currentPin->port = LED_GREEN_GPIO_Port;
        currentPin->pin = LED_GREEN_Pin;
        break;
    }
        ;
    }
}
