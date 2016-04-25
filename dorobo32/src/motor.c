/*
 * motor.c
 *
 *  Created on: Mar 3, 2016
 *      Author: laurent
 */

#include "stm32f0xx_hal.h"
#include "mxconstants.h"
#include "stdlib.h"
#include "motor.h"
#include "cmsis_os.h"

extern TIM_HandleTypeDef htim3;
TIM_OC_InitTypeDef sConfigOC;

typedef struct
{
  GPIO_TypeDef *controlPORT1;
  uint16_t controlPIN1;
  GPIO_TypeDef *controlPORT2;
  uint16_t controlPIN2;
  uint32_t timerChannel;
  int8_t speed;
} motor_t;

static motor_t motor0 =
  {
    M0A1_GPIO_Port,
    M0A1_Pin,
    M0A2_GPIO_Port,
    M0A2_Pin,
    TIM_CHANNEL_1,
    0
  };

static motor_t motor1 =
  {
    M1B1_GPIO_Port,
    M1B1_Pin,
    M1B2_GPIO_Port,
    M1B2_Pin,
    TIM_CHANNEL_2,
    0
  };

static motor_t motor2 =
  {
    M2A1_GPIO_Port,
    M2A1_Pin,
    M2A2_GPIO_Port,
    M2A2_Pin,
	TIM_CHANNEL_3,
    0
  };

static motor_t motor3 =
  {
    M3B1_GPIO_Port,
    M3B1_Pin,
    GPIOC,
    GPIO_PIN_12,
    TIM_CHANNEL_4,
    0
  };

static void set_speed(motor_t *, int8_t);
static motor_t* select_motor (enum EMOTOR);
static void pwm_ramp(motor_t *motorptr, uint8_t old_value, uint8_t new_value);

static void set_speed(motor_t *motorptr, int8_t new_speed)
{
  if (new_speed < -100)
    {
      new_speed = -100;
    }
  else if (new_speed > 100)
    {
      new_speed = 100;
    }

  if((motorptr->speed < 0) && (new_speed < 0))
    {
      pwm_ramp(motorptr, abs(motorptr->speed), abs(new_speed));
    }
  else if((motorptr->speed < 0) && (new_speed > 0))
    {
      pwm_ramp(motorptr, abs(motorptr->speed), 0);
      motorptr->controlPORT1->BSRR = motorptr->controlPIN1;
      motorptr->controlPORT2->BRR = motorptr->controlPIN2;
      pwm_ramp(motorptr, abs(motorptr->speed), abs(new_speed));
    }
  else if((motorptr->speed >= 0) && (new_speed < 0))
    {
      pwm_ramp(motorptr, abs(motorptr->speed), 0);
      motorptr->controlPORT1->BRR = motorptr->controlPIN1;
      motorptr->controlPORT2->BSRR = motorptr->controlPIN2;
      pwm_ramp(motorptr, abs(motorptr->speed), abs(new_speed));
    }
  else
    {
	  motorptr->controlPORT1->BSRR = motorptr->controlPIN1;
	  motorptr->controlPORT2->BRR = motorptr->controlPIN2;
      pwm_ramp(motorptr, abs(motorptr->speed), abs(new_speed));
    }

  motorptr->speed = new_speed;
}

static motor_t* select_motor (enum EMOTOR motoren)
{
  motor_t *motorptr = NULL;
  switch (motoren)
    {
    case MOTOR0:
      motorptr = &motor0;
      break;
    case MOTOR1:
      motorptr = &motor1;
      break;
    case MOTOR2:
      motorptr = &motor2;
      break;
    case MOTOR3:
      motorptr = &motor3;
      break;
    }
  return motorptr;
}

void motorcontrol(enum EMOTOR motoren, int8_t speed)
{
  motor_t *motorptr = select_motor (motoren);
  set_speed(motorptr, speed);
}

static void pwm_ramp(motor_t *motorptr, uint8_t old_value, uint8_t new_value)
{
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  uint8_t i;

  if(old_value < new_value)
    {
      for(i = old_value; i <= new_value; i++)
        {
          sConfigOC.Pulse = old_value + i;
          HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, motorptr->timerChannel);
          HAL_TIM_PWM_Start(&htim3, motorptr->timerChannel);
          vTaskDelay(1);
        }
    }
  else if(old_value > new_value)
    {
      for(i = new_value; i <= old_value; i++)
        {
          sConfigOC.Pulse = old_value - i;
          HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, motorptr->timerChannel);
          HAL_TIM_PWM_Start(&htim3, motorptr->timerChannel);
          vTaskDelay(1);
        }
    }

  motorptr->speed = new_value;
}
