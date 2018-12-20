
#include <rthw.h>
#include <rtdevice.h>
#include "APP_KEY.h"

#define KEY0    53   //PC12--53���� gpio.c �ļ� pin_index pins[] �в鵽 PC12 ���Ϊ 53
#define KEY1    54   //PD2--2���� drv_gpio.c �ļ� pin_index pins[] �в鵽 PD2 ���Ϊ 54

//#define KEY2    1   //PE2--1���� drv_gpio.c �ļ� pin_index pins[] �в鵽 PE2 ���Ϊ 1
//#define WK_UP   34  //PA0--34���� drv_gpio.c �ļ� pin_index pins[] �в鵽 PA0 ���Ϊ 34


//int main(void)
//{
//	rt_thread_t key;// KEY�߳̾��
//	rt_thread_t irq;// irq�߳̾��
//	
//  /* ���� key �߳� */
//    key = rt_thread_create("key",
//                    key_thread_entry,
//                    RT_NULL,
//                    512,
//                    2,
//                    20);
//    /* �����ɹ��������߳� */
//    if (key != RT_NULL)
//	{
//        rt_thread_startup(key);
//	}
//	
//    /* ���� irq �߳� */
//    irq = rt_thread_create("exirq",
//                    irq_thread_entry,
//                    RT_NULL,
//                    512,
//                    4,
//                    10);
//    /* �����ɹ��������߳� */
//    if (irq != RT_NULL)
//	{
//        rt_thread_startup(irq);
//	}
//}

void key_thread_entry(void* parameter)
{
    //PE2��PE3 ������������
    rt_pin_mode(KEY1, PIN_MODE_INPUT_PULLUP);
	
//    rt_pin_mode(KEY2, PIN_MODE_INPUT_PULLUP);
//    //PA0 ����Ϊ��������
//    rt_pin_mode(WK_UP, PIN_MODE_INPUT_PULLDOWN);

    while (1)
    {
        // ��⵽�͵�ƽ�������� 1 ������
        if (rt_pin_read(KEY1) == PIN_LOW)
        {
            rt_kprintf("key1 pressed!\n");
        }
		
//        // ��⵽�͵�ƽ�������� 2 ������
//        if (rt_pin_read(KEY2) == PIN_LOW)
//        {
//            rt_kprintf("key2 pressed!\n");
//        }		
//        // ��⵽�ߵ�ƽ�������� wp ������
//        if (rt_pin_read(WK_UP) == PIN_HIGH)
//        {
//            rt_kprintf("WK_UP pressed!\n");
//        }
		
        // ���� 10ms
        rt_thread_delay(rt_tick_from_millisecond(20));
    }
}

void irq_thread_entry(void* parameter)
{
    // ��������
    rt_pin_mode(KEY0, PIN_MODE_INPUT_PULLUP);
    // ���жϣ��½���ģʽ���ص�������Ϊ hdr_callback
    rt_pin_attach_irq(KEY0, PIN_IRQ_MODE_FALLING, hdr_callback, (void*)"callbackargs");
    // ʹ���ж�
    rt_pin_irq_enable(KEY0, PIN_IRQ_ENABLE);

}

void hdr_callback(void *args)// �ص�����
{
    char *a = args;// ��ȡ����
    rt_kprintf("key0 down! %s\n",a);
}
