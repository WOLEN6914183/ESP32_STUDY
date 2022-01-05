#include "led.h"

Ledonoff Led ;

void Ledonoff::led_init(void)
{
    /* Configure the IOMUX register for pad BLINK_GPIO (some pads are
       muxed to GPIO on reset already, but some default to other
       functions and need to be switched to GPIO. Consult the
       Technical Reference for a list of pads and their default
       functions.)
    */
    gpio_pad_select_gpio(LED_GPIO);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);
}

void Ledonoff::led_on(void)
{
    gpio_set_level(LED_GPIO, 1);
}

void Ledonoff::led_off(void)
{
    gpio_set_level(LED_GPIO, 0);
}
