/*
 * digitial.c
 *
 *  Created on: Mar 5, 2016
 *      Author: laurent
 */

#include "stm32f0xx_hal.h"
#include "mxconstants.h"
#include "digital.h"

typedef struct
{
	GPIO_TypeDef*	port;
	uint16_t 		pin;
}pin_t;

void set_pin(enum EDIGITAL epin, enum EDIGITAL_STATE estate);
uint8_t get_pin(enum EDIGITAL epin);

static void selectPin(enum EDIGITAL DIGITAL_pins, pin_t* currentPin);

void set_pin(enum EDIGITAL epin, enum EDIGITAL_STATE estate)
{
	pin_t selectedPin;
	selectPin(epin, &selectedPin);
	HAL_GPIO_WritePin(selectedPin.port, selectedPin.pin,  estate);
}

uint8_t get_pin(enum EDIGITAL epin)
{
  pin_t selectedPin;
  selectPin(epin, &selectedPin);
  return HAL_GPIO_ReadPin(selectedPin.port, selectedPin.pin);
}

static void selectPin(enum EDIGITAL DIGITAL_pins, pin_t* currentPin)
{
	switch(DIGITAL_pins)
	{
	  case DIGITAL0:
	  {
		  currentPin->port = DIGITAL0_GPIO_Port;
		  currentPin->pin = DIGITAL0_Pin;
		  break;
	  }
	  case DIGITAL1:
	  {
		  currentPin->port = DIGITAL1_GPIO_Port;
		  currentPin->pin = DIGITAL1_Pin;
		  break;
	  }
	  case DIGITAL2:
	  {
		  currentPin->port = DIGITAL2_GPIO_Port;
		  currentPin->pin = DIGITAL2_Pin;
		  break;
	  }
	  case DIGITAL3:
	  {
		  currentPin->port = DIGITAL3_GPIO_Port;
		  currentPin->pin = DIGITAL3_Pin;
		  break;
	  }
	  case DIGITAL4:
	  {
		  currentPin->port = DIGITAL4_GPIO_Port;
		  currentPin->pin = DIGITAL4_Pin;
		  break;
	  }
	  case DIGITAL5:
	  {
		  currentPin->port = DIGITAL5_GPIO_Port;
		  currentPin->pin = DIGITAL5_Pin;
		  break;
	  }
	  case SERVO0:
	  {
		  currentPin->port = SERVO0_GPIO_Port;
		  currentPin->pin = SERVO0_Pin;
		  break;
	  }
	  case SERVO1:
	  {
		  currentPin->port = SERVO1_GPIO_Port;
		  currentPin->pin = SERVO1_Pin;
		  break;
	  }
	  case SERVO2:
	  {
		  currentPin->port = SERVO2_GPIO_Port;
		  currentPin->pin = SERVO2_Pin;
		  break;
	  }
	  case SERVO3:
	  {
		  currentPin->port = SERVO3_GPIO_Port;
		  currentPin->pin = SERVO3_Pin;
		  break;
	  }
	  case SERVO4:
	  {
		  currentPin->port = SERVO4_GPIO_Port;
		  currentPin->pin = SERVO4_Pin;
		  break;
	  }
	  case SERVO5:
	  {
		  currentPin->port = SERVO5_GPIO_Port;
		  currentPin->pin = SERVO5_Pin;
		  break;
	  }
	  case DIP0:
	  {
		  currentPin->port = DIP0_GPIO_Port;
		  currentPin->pin = DIP0_Pin;
		  break;
	  }
	  case DIP1:
	  {
		  currentPin->port = DIP1_GPIO_Port;
		  currentPin->pin = DIP1_Pin;
		  break;
	  }
	  case DIP2:
	  {
		  currentPin->port = DIP2_GPIO_Port;
		  currentPin->pin = DIP2_Pin;
		  break;
	  }
	  case DIP3:
	  {
		  currentPin->port = DIP3_GPIO_Port;
		  currentPin->pin = DIP3_Pin;
		  break;
	  }
	  case LED0:
	  {
		  currentPin->port = LED0_GPIO_Port;
		  currentPin->pin = LED0_Pin;
		  break;
	  }
	  case LED1:
	  {
		  currentPin->port = LED1_GPIO_Port;
		  currentPin->pin = LED1_Pin;
		  break;
	  }
	  default:
	  {
		  currentPin->port = LED0_GPIO_Port;
		  currentPin->pin = LED0_Pin;
		  break;
	  };
	}
}
