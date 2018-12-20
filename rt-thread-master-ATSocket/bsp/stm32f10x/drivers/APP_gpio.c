#include <rthw.h>
#include <rtdevice.h>
#include <board.h>

#define LED0 21 //PF9--21���� drv_gpio.c �ļ� pin_index pins[] �в鵽 PF9 ���Ϊ 21
#define LED1 22 //PF10--22���� drv_gpio.c �ļ� pin_index pins[] �в鵽 PF10 ���Ϊ 22

void led_thread_entry(void* parameter);

 void led_thread_entry(void* parameter)
{
    // ���ùܽ�Ϊ���ģʽ
    rt_pin_mode(LED0, PIN_MODE_OUTPUT);
    // ���ùܽ�Ϊ���ģʽ
    rt_pin_mode(LED1, PIN_MODE_OUTPUT);
    while (1)
    {
        // ����͵�ƽ��LED0 ��
        rt_pin_write(LED0, PIN_LOW);
        // ����͵�ƽ��LED1 ��
        rt_pin_write(LED1, PIN_LOW);
        // ���� 500ms
        rt_thread_delay(rt_tick_from_millisecond(500));

        // ����ߵ�ƽ��LED0 ��
        rt_pin_write(LED0, PIN_HIGH);
        // ����ߵ�ƽ��LED1 ��
        rt_pin_write(LED1, PIN_HIGH);
        // ���� 500ms
        rt_thread_delay(rt_tick_from_millisecond(500));
    }
}

