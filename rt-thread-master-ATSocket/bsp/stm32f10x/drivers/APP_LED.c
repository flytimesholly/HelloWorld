#include <rthw.h>
#include <rtdevice.h>
#include "APP_LED.h"

#define LED0 15 //PA1--15，在 drv_gpio.c 文件 pin_index pins[] 中查到 PA1 编号为 15
#define LED1 2 //PC13--2，在 drv_gpio.c 文件 pin_index pins[] 中查到 PC13 编号为 2

 void led_thread_entry(void* parameter)
{
    // 设置管脚为输出模式
    rt_pin_mode(LED0, PIN_MODE_OUTPUT);
    // 设置管脚为输出模式
    rt_pin_mode(LED1, PIN_MODE_OUTPUT);
    while (1)
    {
        // 输出低电平，LED0 亮
        rt_pin_write(LED0, PIN_LOW);
        // 输出低电平，LED1 亮
        rt_pin_write(LED1, PIN_LOW);
        // 挂起 500ms
        rt_thread_delay(rt_tick_from_millisecond(500));

        // 输出高电平，LED0 灭
        rt_pin_write(LED0, PIN_HIGH);
        // 输出高电平，LED1 灭
        rt_pin_write(LED1, PIN_HIGH);
        // 挂起 500ms
        rt_thread_delay(rt_tick_from_millisecond(500));
    }
}

