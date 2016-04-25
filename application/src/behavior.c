/*
 * behavior.c
 *
 *  Created on: 25.04.2016
 *      Author: Laurent
 */

#include <libdorobo32.h>
#include "environment.h"

#define TARGET_FREQ 100

void handle_distance(void);
void handle_infrared(void);
void control_motors(void);

void behavior()
{
    handle_bumpers();
}

void control_motors()
{
  switch(motorflag)
  {
    case geradeaus:
      motorcontrol(MOTOR0,100);
      motorcontrol(MOTOR1,-100);
      motorcontrol(MOTOR2,0);
      break;

    case rechts:
      motorcontrol(MOTOR0,0);
      motorcontrol(MOTOR1,0);
      motorcontrol(MOTOR2,-100);
      break;

    case links:
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
}

void handle_distance()
{
  if(distance_left > distance_threshold && distance_right > distance_threshold)
    {
      motorflag = drehen;
      control_motors();
    }
  else if(distance_left > distance_threshold)
    {
      motorflag = rechts;
      control_motors();
    }
  else if(distance_right > distance_threshold)
    {
      motorflag = links;
      control_motors();
    }
  else
    {
      handle_infrared();
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
        motorflag = geradeaus;
    }
    else if(*ir_left < infrared_threshold && *ir_right < infrared_threshold)
    {
        //Kein Signal auf beiden Empfängern
        motorflag = drehen;
    }
    else if(*ir_left > infrared_threshold)
    {
        //Signal nur links detektiert
        motorflag = links;
    }
    else
    {
        //Signal nur rechts detektiert
        motorflag = rechts;
    }
    control_motors();
}

void handle_bumpers()
{
    if(!bumper_left || !bumper_right)
    {
        motorflag = rueckwaerts;
        control_motors();
    }
    else
    {
        handle_distance();
    }
}

