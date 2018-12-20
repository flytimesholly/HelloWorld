#ifndef RT_CONFIG_H__
#define RT_CONFIG_H__

/* Automatically generated file; DO NOT EDIT. */
/* RT-Thread Project Configuration */

/* RT-Thread Kernel */

#define RT_NAME_MAX 8
#define RT_ALIGN_SIZE 4
#define RT_THREAD_PRIORITY_32
#define RT_THREAD_PRIORITY_MAX 32
#define RT_TICK_PER_SECOND 1000
#define RT_USING_OVERFLOW_CHECK
#define RT_USING_HOOK
#define RT_IDEL_HOOK_LIST_SIZE 4
#define IDLE_THREAD_STACK_SIZE 256

/* Inter-Thread communication */

#define RT_USING_SEMAPHORE
#define RT_USING_MUTEX
#define RT_USING_EVENT
#define RT_USING_MAILBOX
#define RT_USING_MESSAGEQUEUE

/* Memory Management */

#define RT_USING_MEMPOOL
#define RT_USING_SMALL_MEM
#define RT_USING_HEAP

/* Kernel Device Object */

#define RT_USING_DEVICE
#define RT_USING_CONSOLE
#define RT_CONSOLEBUF_SIZE 512
#define RT_CONSOLE_DEVICE_NAME "uart1"
#define ARCH_ARM
#define ARCH_ARM_CORTEX_M
#define ARCH_ARM_CORTEX_M3

/* RT-Thread Components */

#define RT_USING_COMPONENTS_INIT

/* C++ features */

#define RT_USING_CPLUSPLUS

/* Command shell */

#define RT_USING_FINSH
#define FINSH_THREAD_NAME "tshell"
#define FINSH_USING_HISTORY
#define FINSH_HISTORY_LINES 5
#define FINSH_USING_SYMTAB
#define FINSH_USING_DESCRIPTION
#define FINSH_THREAD_PRIORITY 20
#define FINSH_THREAD_STACK_SIZE 4096
#define FINSH_CMD_SIZE 80
#define FINSH_USING_MSH
#define FINSH_USING_MSH_DEFAULT
#define FINSH_ARG_MAX 10

/* Device virtual file system */


/* Device Drivers */

#define RT_USING_DEVICE_IPC
#define RT_PIPE_BUFSZ 512
#define RT_USING_SERIAL
#define RT_USING_I2C
#define RT_USING_I2C_BITOPS
#define RT_USING_PIN
#define RT_USING_SPI

/* Using WiFi */


/* Using USB */


/* POSIX layer and C standard library */

#define RT_USING_LIBC

/* Network */

/* Socket abstraction layer */

#define RT_USING_SAL

/* protocol stack implement */

#define SAL_USING_AT
#define SAL_SOCKETS_NUM 16
#define SAL_PROTO_FAMILIES_NUM 4

/* light weight TCP/IP stack */


/* Modbus master and slave stack */


/* AT commands */

#define RT_USING_AT
#define AT_DEBUG
#define AT_USING_CLIENT
#define AT_CLIENT_NUM_MAX 1
#define AT_USING_SOCKET
#define AT_USING_CLI
#define AT_SW_VERSION_NUM 0x10200

/* VBUS(Virtual Software BUS) */


/* Utilities */


/* ARM CMSIS */

#define RT_USING_RTT_CMSIS

/* RT-Thread online packages */

/* IoT - internet of things */


/* Wi-Fi */

/* Marvell WiFi */


/* Wiced WiFi */

#define PKG_USING_AT_DEVICE
#define PKG_AT_INIT_BY_THREAD
#define AT_DEVICE_ESP8266
#define AT_DEVICE_SOCKETS_NUM 5
#define AT_DEVICE_NAME "uart4"
#define AT_DEVICE_RECV_BUFF_LEN 512
#define AT_DEVICE_WIFI_SSID "1801a"
#define AT_DEVICE_WIFI_PASSWORD "88888888"
#define PKG_USING_AT_DEVICE_LATEST_VERSION

/* IoT Cloud */


/* security packages */


/* language packages */


/* multimedia packages */


/* tools packages */


/* system packages */


/* peripheral libraries and drivers */

#define PKG_USING_SHT2X
#define PKG_USING_SHT2X_LATEST_VERSION
#define PKG_USING_MPU6XXX
#define PKG_USING_MPU6XXX_SAMPLE
#define PKG_USING_MPU6XXX_LATEST_VERSION

/* miscellaneous packages */


/* sample package */

/* samples: kernel and components samples */

#define PKG_USING_PERIPHERAL_SAMPLES
#define PKG_USING_PERIPHERAL_SAMPLES_LATEST_VERSION
#define PERIPHERAL_SAMPLES_USING_I2C
#define PERIPHERAL_SAMPLES_USING_PIN
#define PERIPHERAL_SAMPLES_USING_SERIAL
#define PERIPHERAL_SAMPLES_USING_SPI

/* example package: hello */

#define SOC_STM32F1
#define BSP_USING_I2C
#define RT_USING_UART1
#define RT_USING_UART2
#define RT_USING_UART3
#define RT_USING_UART4

#endif
