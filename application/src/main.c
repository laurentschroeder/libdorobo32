/*
 * main.c
 *
 *  Created on: 24.04.2016
 *      Author: Laurent
 */

#include <dorobo32.h>
#include "FreeRTOS.h"
#include "task.h"

//init() is defined in libsthal
extern void init();

void job_blink_led(void * pvParameters)
{
   for(;;)
   {
       led_green(DD_LEVEL_HIGH);
       vTaskDelay(250);
       led_green(DD_LEVEL_LOW);
       vTaskDelay(250);
   }
}

void add_tasks()
{
    BaseType_t xReturned;
    TaskHandle_t blink_handle = NULL;

    xReturned = xTaskCreate(
                    job_blink_led,
                    "blink_task",
                    128,
                    ((void*)1),
                    1,
                    &blink_handle);
}

int main()
{
    //Call init() function from libsthal to initialize HAL, Clocks, Timers etc.
    init();

    //Call add_tasks() to make user defined tasks available to the scheduler.
    add_tasks();

    //Start the FreeRTOS scheduler.
    vTaskStartScheduler();
}
