/*
 * motor.h
 *
 *  Created on: Mar 3, 2016
 *      Author: laurent
 */

#ifndef DOROBO32_INC_MOTOR_H_
#define DOROBO32_INC_MOTOR_H_

enum EMOTOR
{
  MOTOR0, MOTOR1, MOTOR2, MOTOR3
};

typedef enum {
  geradeaus,
  links,
  rechts,
  stop,
  rueckwaerts,
  drehen
}motorflag_t;

extern motorflag_t motorflag;

extern void motorcontrol(enum EMOTOR, int8_t speed);

#endif /* DOROBO32_INC_MOTOR_H_ */
