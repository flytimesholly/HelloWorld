#ifndef __APP_KEY_H__
#define __APP_KEY_H__

#include <rthw.h>
#include <rtthread.h>

void key_thread_entry(void* parameter);//����������������������
void irq_thread_entry(void* parameter);//����������������������

void hdr_callback(void *args);

#endif
