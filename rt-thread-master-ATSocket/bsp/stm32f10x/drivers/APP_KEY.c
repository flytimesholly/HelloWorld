
#include <rthw.h>
#include <rtdevice.h>
#include "APP_KEY.h"

#define KEY0    53   //PC12--53，在 gpio.c 文件 pin_index pins[] 中查到 PC12 编号为 53
#define KEY1    54   //PD2--2，在 drv_gpio.c 文件 pin_index pins[] 中查到 PD2 编号为 54

//#define KEY2    1   //PE2--1，在 drv_gpio.c 文件 pin_index pins[] 中查到 PE2 编号为 1
//#define WK_UP   34  //PA0--34，在 drv_gpio.c 文件 pin_index pins[] 中查到 PA0 编号为 34


//int main(void)
//{
//	rt_thread_t key;// KEY线程句柄
//	rt_thread_t irq;// irq线程句柄
//	
//  /* 创建 key 线程 */
//    key = rt_thread_create("key",
//                    key_thread_entry,
//                    RT_NULL,
//                    512,
//                    2,
//                    20);
//    /* 创建成功则启动线程 */
//    if (key != RT_NULL)
//	{
//        rt_thread_startup(key);
//	}
//	
//    /* 创建 irq 线程 */
//    irq = rt_thread_create("exirq",
//                    irq_thread_entry,
//                    RT_NULL,
//                    512,
//                    4,
//                    10);
//    /* 创建成功则启动线程 */
//    if (irq != RT_NULL)
//	{
//        rt_thread_startup(irq);
//	}
//}

void key_thread_entry(void* parameter)
{
    //PE2、PE3 设置上拉输入
    rt_pin_mode(KEY1, PIN_MODE_INPUT_PULLUP);
	
//    rt_pin_mode(KEY2, PIN_MODE_INPUT_PULLUP);
//    //PA0 设置为下拉输入
//    rt_pin_mode(WK_UP, PIN_MODE_INPUT_PULLDOWN);

    while (1)
    {
        // 检测到低电平，即按键 1 按下了
        if (rt_pin_read(KEY1) == PIN_LOW)
        {
            rt_kprintf("key1 pressed!\n");
        }
		
//        // 检测到低电平，即按键 2 按下了
//        if (rt_pin_read(KEY2) == PIN_LOW)
//        {
//            rt_kprintf("key2 pressed!\n");
//        }		
//        // 检测到高电平，即按键 wp 按下了
//        if (rt_pin_read(WK_UP) == PIN_HIGH)
//        {
//            rt_kprintf("WK_UP pressed!\n");
//        }
		
        // 挂起 10ms
        rt_thread_delay(rt_tick_from_millisecond(20));
    }
}

void irq_thread_entry(void* parameter)
{
    // 上拉输入
    rt_pin_mode(KEY0, PIN_MODE_INPUT_PULLUP);
    // 绑定中断，下降沿模式，回调函数名为 hdr_callback
    rt_pin_attach_irq(KEY0, PIN_IRQ_MODE_FALLING, hdr_callback, (void*)"callbackargs");
    // 使能中断
    rt_pin_irq_enable(KEY0, PIN_IRQ_ENABLE);

}

void hdr_callback(void *args)// 回调函数
{
    char *a = args;// 获取参数
    rt_kprintf("key0 down! %s\n",a);
}
