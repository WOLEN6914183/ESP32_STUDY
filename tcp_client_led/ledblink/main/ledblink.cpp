/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
/*#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "led_strip.h"
#include "sdkconfig.h"
#include "led.h"

#include "light_strip.h"
#include <iostream>

extern LEDWidget Light;
extern Ledonoff  Led;


extern "C" void app_main()
{
    Led.led_init();
    Light.Light_Strip_Init();
    while (1) {
        Led.led_on();
        Light.Light_Strip_RGB(255,255,255);
        vTaskDelay(5000);
        Led.led_off();
    }
}

*/
#include <stdio.h>
#include <iostream>
#include "sdkconfig.h"
#include "tcp_client.h"

Client Clientconnect;

extern "C" void app_main()
{
    Clientconnect.tcp_client_apptask();
}
