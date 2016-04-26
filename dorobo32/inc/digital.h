/*
 * digital.h
 *
 *  Created on: Mar 5, 2016
 *      Author: laurent
 */

#ifndef DOROBO32_INC_DIGITAL_H_
#define DOROBO32_INC_DIGITAL_H_

#include "stdint.h"

enum EDIGITAL
{
  DIGITAL0,
  DIGITAL1,
  DIGITAL2,
  DIGITAL3,
  DIGITAL4,
  DIGITAL5,
  SERVO0,
  SERVO1,
  SERVO2,
  SERVO3,
  SERVO4,
  SERVO5,
  DIP0,
  DIP1,
  DIP2,
  DIP3,
  LED0,
  LED1
};

enum EDIGITAL_STATE
{
  LOW,
  HIGH
};

void set_pin(enum EDIGITAL digital_pins, enum EDIGITAL_STATE state);
uint8_t get_pin(enum EDIGITAL digital_pins);

#endif /* DOROBO32_INC_DIGITAL_H_ */
