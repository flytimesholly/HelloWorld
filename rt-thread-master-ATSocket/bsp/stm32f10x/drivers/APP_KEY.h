#ifndef __APP_KEY_H__
#define __APP_KEY_H__

#include <rthw.h>
#include <rtthread.h>

void key_thread_entry(void* parameter);//函数声明，供主函数调用
void irq_thread_entry(void* parameter);//函数声明，供主函数调用

void hdr_callback(void *args);

#endif
