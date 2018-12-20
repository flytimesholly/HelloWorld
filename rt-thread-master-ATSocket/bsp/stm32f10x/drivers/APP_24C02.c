#include <rtthread.h>
#include <rtdevice.h>
#include "APP_24C02.h"

static const char * i2c_bus_device_name = "i2c1";
static const rt_uint8_t eeprom_addr = 0x50; /* 1010A2A1A0 - R/W */


void i2c_test(void* parameter)
{
    struct rt_i2c_bus_device * i2c_device;
    struct rt_i2c_msg msgs[2];
	
    rt_uint8_t buffer1[2];
    rt_uint8_t buffer2[2];
    rt_size_t i;
	
    i2c_device = rt_i2c_bus_device_find(i2c_bus_device_name);
    if(i2c_device == RT_NULL)
    {
        rt_kprintf("i2c bus device %s not found!", i2c_bus_device_name);
//        return -RT_ENOSYS;
    }
    //step 1: read out.
    buffer1[0] = 0;
    msgs[0].addr = eeprom_addr;
    msgs[0].flags = RT_I2C_WR; /* Write to slave */
    msgs[0].buf = buffer1; /* eeprom offset. */
    msgs[0].len = 1;
    msgs[1].addr  = eeprom_addr;
    msgs[1].flags = RT_I2C_RD; /* Read from slave */
    msgs[1].buf   = buffer2;
    msgs[1].len   = sizeof(buffer2);
    if( rt_i2c_transfer(i2c_device, msgs, 2) != 2 )
    {
        rt_kprintf("read EEPROM fail!");
    }
    rt_kprintf("read EEPROM at I2C address: 0x%02X", eeprom_addr);
    rt_kprintf("0x0000: ");
    for(i=0; i<sizeof(buffer2); i++)
    {
        rt_kprintf("%02X ", buffer2[i]);
    }
    rt_kprintf("");
	
    //step 2: write back.
    for(i=0; i<sizeof(buffer2); i++)
    {
        buffer2[i] = ~buffer2[i];
    }
    msgs[0].addr = eeprom_addr;
    msgs[0].flags = RT_I2C_WR;
    msgs[0].buf = buffer1; /* eeprom offset. */
    msgs[0].len = 1;
    msgs[1].addr  = eeprom_addr;
    msgs[1].flags = RT_I2C_WR | RT_I2C_NO_START;
    msgs[1].buf   = buffer2;
    msgs[1].len   = sizeof(buffer2);
    if( rt_i2c_transfer(i2c_device, msgs, 2) != 2 )
    {
        rt_kprintf("write EEPROM fail!");
    }
    rt_thread_delay(rt_tick_from_millisecond(50)); // FRAM no need.
	
    //step 3: re-read out.
    buffer1[0] = 0;
    msgs[0].addr = eeprom_addr;
    msgs[0].flags = RT_I2C_WR; /* Write to slave */
    msgs[0].buf = buffer1; /* eeprom offset. */
    msgs[0].len = 1;
    msgs[1].addr  = eeprom_addr;
    msgs[1].flags = RT_I2C_RD; /* Read from slave */
    msgs[1].buf   = buffer2;
    msgs[1].len   = sizeof(buffer2);
    if( rt_i2c_transfer(i2c_device, msgs, 2) != 2 )
    {
        rt_kprintf("re-read EEPROM fail!");
    }
    rt_kprintf("re-read EEPROM at I2C address: 0x%02X", eeprom_addr);
    rt_kprintf("0x0000: ");
    for(i=0; i<sizeof(buffer2); i++)
    {
        rt_kprintf("%02X ", buffer2[i]);
    }
    rt_kprintf("");
//    return RT_EOK;
}

#ifdef RT_USING_FINSH
#include <finsh.h>
FINSH_FUNCTION_EXPORT(i2c_test, i2c_test);
#endif // RT_USING_FINSH
