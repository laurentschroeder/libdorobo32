/*
 * behavior.c
 *
 *  Created on: 25.04.2016
 *      Author: Laurent
 */

#include <libdorobo32.h>
#include "environment.h"
#include "behavior.h"
#include "FreeRTOS.h"
#include "task.h"

#define TARGET_FREQ 100

void handle_distance(void);
void handle_infrared(void);
void control_motors(motorflag_t, uint32_t);

void control_motors(motorflag_t motorflag, uint32_t ticks)
{
  switch(motorflag)
  {
    case geradeaus:
      motorcontrol(MOTOR0,100);
      motorcontrol(MOTOR1,-100);
      motorcontrol(MOTOR2,0);
      break;

    case links:
      motorcontrol(MOTOR0,0);
      motorcontrol(MOTOR1,0);
      motorcontrol(MOTOR2,-100);
      break;

    case rechts:
      motorcontrol(MOTOR0,0);
      motorcontrol(MOTOR1,0);
      motorcontrol(MOTOR2,100);
      break;

    case rueckwaerts:
      motorcontrol(MOTOR0,-100);
      motorcontrol(MOTOR1,100);
      motorcontrol(MOTOR2,0);
      break;

    case stop:
      motorcontrol(MOTOR0,0);
      motorcontrol(MOTOR1,0);
      motorcontrol(MOTOR2,0);
      break;

    case drehen:
      motorcontrol(MOTOR0,100);
      motorcontrol(MOTOR1,100);
      motorcontrol(MOTOR2,100);
      break;

    default:
      motorcontrol(MOTOR0,100);
      motorcontrol(MOTOR1,-100);
      motorcontrol(MOTOR2,0);
      break;
  }
  vTaskDelay(ticks);
}

void handle_distance()
{
  if(distance_left > distance_threshold && distance_right > distance_threshold)
    {
      control_motors(rueckwaerts, 100);
    }
  else if(distance_left > distance_threshold)
    {
      control_motors(stop, 500);
      control_motors(rueckwaerts, 250);
      control_motors(rechts, 250);
    }
  else if(distance_right > distance_threshold)
    {
      control_motors(stop, 500);
      control_motors(rueckwaerts, 250);
      control_motors(links, 250);
    }
  else
    {
      if(get_pin(DIP0))
      {
          handle_infrared();
      }
      else
      {
          control_motors(geradeaus, 10);
      }
    }
}

void handle_infrared()
{
    uint16_t *ir_left;
    uint16_t *ir_right;
    if(TARGET_FREQ == 100)
    {
        ir_left = &ir0_amplitude_100;
        ir_right = &ir1_amplitude_100;
    }
    else
    {
        ir_left = &ir0_amplitude_125;
        ir_right = &ir1_amplitude_125;
    }

    if(*ir_left > infrared_threshold && *ir_right > infrared_threshold)
    {
        //IR Signal auf beiden Empfängern vorhanden
        control_motors(geradeaus, 100);
    }
    else if(*ir_left < infrared_threshold && *ir_right < infrared_threshold)
    {
        //Kein Signal auf beiden Empfängern
        control_motors(drehen, 100);
    }
    else if(*ir_left > infrared_threshold)
    {
        //Signal nur links detektiert
        control_motors(links, 100);
    }
    else
    {
        //Signal nur rechts detektiert
        control_motors(rechts, 100);
    }

}

void handle_bumpers()
{
    if(!bumper_left || !bumper_right)
    {
        control_motors(stop, 1);
    }
    else
    {
        handle_distance();
    }
}

