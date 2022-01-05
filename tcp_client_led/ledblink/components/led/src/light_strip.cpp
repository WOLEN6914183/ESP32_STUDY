#include "light_strip.h"
#include "led_strip.h"
#include "driver/rmt.h"
#include "esp_log.h"
#include "esp_system.h"
#include "esp_timer.h"
#include "led_strip.h"

#include "driver/ledc.h"
#include "hal/ledc_types.h"
#include <unistd.h>

#define RMT_TX_DEFAULT_GPIO GPIO_NUM_3
#define RMT_TX_DEFAULT_CHANNEL RMT_CHANNEL_0

static  led_strip_t * strip = NULL;
LEDWidget Light;

/*
*  Function  : Light_Strip_Init
*  Return    : 0
*  Parameter : LED_OUTPUT_NUM
*/
/********************************************Special-Node************************************************
* RMT配置是通过配置rmt_config_t结构体实现的，rmt_config_t可以分为公共配置部分和特有配置部分，该结构体定义为
* typedef struct {
*  rmt_mode_t rmt_mode;     // 配置RMT模块是发射或接收
*  rmt_channel_t channel;   // 使用第几个通道       
*  uint8_t clk_div;         // 对时钟源进行多少分频，可以配置0-255，其中0表示256分频             
*  gpio_num_t gpio_num;     // 使用第几个gpio完成该工作        
*  uint8_t mem_block_num;   // 使用多少个block的RAM进行收发数据
*  union{
*      rmt_tx_config_t tx_config;     // 如果模式是接收，就配置这部分
*      rmt_rx_config_t rx_config;     // 如果模式是发送，就配置这部分
*     };
*}rmt_config_t;
*********************************************************************************************************/

void LEDWidget::Light_Strip_Init()
{

    rmt_config_t config = RMT_DEFAULT_CONFIG_TX(RMT_TX_DEFAULT_GPIO, RMT_TX_DEFAULT_CHANNEL);    //配置rmt,使用gpio3,第0个通道
    config.clk_div      = 2; //对时钟源进行2分频
    rmt_config(&config);
    rmt_driver_install(config.channel, 0, 0); //rmt_driver_install()函数的功能是，为特定通道配置环形缓冲区。该缓冲区只在配置红外接收的时候有用。
    led_strip_config_t strip_config = LED_STRIP_DEFAULT_CONFIG(31, (led_strip_dev_t) config.channel); //LED带的默认配置
    strip                           = led_strip_new_rmt_ws2812(&strip_config);
}

void LEDWidget::Light_Strip_RGB(uint8_t red,uint8_t green,uint8_t blue)
{
    for(int i=0;i<=29;i++)
    {
        strip->set_pixel(strip, i, red, green, blue);
        strip->refresh(strip, 100);
        usleep(1000); 
    }
}
