/*
 * main.c
 *
 *  Created on: 24.04.2016
 *      Author: Laurent
 */

#include <libdorobo32.h>
#include "FreeRTOS.h"
#include "task.h"

//init() is defined in libsthal
extern void init();

void job_blink_led(void * pvParameters)
{
   for(;;)
   {
       set_pin(LED0, HIGH);
       vTaskDelay(250);
       set_pin(LED0, LOW);
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
