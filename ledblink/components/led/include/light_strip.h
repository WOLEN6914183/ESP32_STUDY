#pragma once

#include "driver/gpio.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"



class LEDWidget
{

public:

    void Light_Strip_Init();

    void Light_Strip_RGB(uint8_t red,uint8_t green,uint8_t blue);

    void Light_Strip_HSBtoRGB(uint8_t Saturation ,uint16_t Hue,uint8_t Brightness);

    void Light_Color_Temperature(uint8_t Temperature);

private:

    uint8_t Red,Green,Blue,temperature,brightness,satureation;

    uint16_t hue;

};
