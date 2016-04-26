/**
 * DoroboLib32 Motor (DM)
 *
 * Functions to set motor speed.
 *
 * Copyright (c) 2016 Laurent Schröder, Claus Fühner
 */

#ifndef DOROBO32_INC_MOTOR_H_
#define DOROBO32_INC_MOTOR_H_

enum DM_MOTORS_E
{
    DM_MOTOR0, //< MOTOR0
    DM_MOTOR1, //< MOTOR0
    DM_MOTOR2, //< MOTOR0
    DM_MOTOR3  //< MOTOR0
};

/**
 * Motor initialization.
 */
void motor_init();

/**
 * Set the speed for the given motor
 *
 * Waring: The user of this function is responsible for
 * limiting the motor current by controlling the slope of
 * speed changes.
 *
 * @param   motor
 *          motor to control
 *
 * @param   speed
 *          new motor speed and direction in percent (-100-100)
 */
void motor_set(enum DM_MOTORS_E motor, int8_t speed);

#endif /* DOROBO32_INC_MOTOR_H_ */
