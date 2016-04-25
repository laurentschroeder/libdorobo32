/*
 * main.c
 *
 *  Created on: 24.04.2016
 *      Author: Laurent
 */

#include <libdorobo32.h>
#include "FreeRTOS.h"
#include "task.h"
#include "environment.h"
#include "behavior.h"
#include "stdio.h"

//init() is defined in libsthal
extern void init();

void job_blink_led(void * pvParameters)
{
   for(;;)
   {
       set_pin(LED0, ON);
       vTaskDelay(250);
       set_pin(LED0, OFF);
       vTaskDelay(250);
   }
}

void job_fft(void * pvParameters)
{
    for(;;)
    {
        ir0_amplitude_100 = fft_simple(FFT_FREQ100, DIGITAL0);
        ir0_amplitude_125 = fft_simple(FFT_FREQ125, DIGITAL0);
        ir1_amplitude_100 = fft_simple(FFT_FREQ100, DIGITAL1);
        ir1_amplitude_125 = fft_simple(FFT_FREQ125, DIGITAL1);
        taskYIELD();
    }
}

void job_sense(void * pvParameters)
{
    for(;;)
    {
        bumper_left = get_pin(DIGITAL2);
        bumper_right = get_pin(DIGITAL3);
        distance_left = adc_get_value(ADC_CHANNEL0);
        distance_right = adc_get_value(ADC_CHANNEL1);
        dip0 = get_pin(DIP0);
        dip1 = get_pin(DIP1);
        dip2 = get_pin(DIP2);
        dip3 = get_pin(DIP3);
        if(dip1)
        {
            handle_bumpers();
        }
        taskYIELD();
    }
}

void add_tasks()
{
    BaseType_t xReturned;
    TaskHandle_t blink_handle = NULL;
    TaskHandle_t fft_handle = NULL;
    TaskHandle_t sense_handle = NULL;


    xReturned = xTaskCreate(
                    job_blink_led,
                    "blink_task",
                    256,
                    ((void*)1),
                    1,
                    &blink_handle);

    xReturned = xTaskCreate(
                    job_fft,
                    "fft_task",
                    256,
                    ((void*)1),
                    1,
                    &fft_handle);

    xReturned = xTaskCreate(
                    job_sense,
                    "sense_task",
                    256,
                    ((void*)1),
                    1,
                    &sense_handle);

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
