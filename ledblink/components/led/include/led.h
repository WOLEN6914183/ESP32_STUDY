#pragma once

#include "sdkconfig.h"
#include "driver/gpio.h"

/* Can use project configuration menu (idf.py menuconfig) to choose the GPIO to blink,
   or you can edit the following line and set a number here.
*/
#define LED_GPIO GPIO_NUM_3

class Ledonoff
{   
public:
    void led_init(void);
    void led_on(void);
    void led_off(void);

};




