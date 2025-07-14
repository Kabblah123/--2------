/**
 ****************************************************************************************************
 * @file        main.c
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2020-04-18
 * @brief       蜂鸣器 实验
 * @license     Copyright (c) 2020-2032, 广州市星翼电子科技有限公司
 ****************************************************************************************************
 * @attention
 *
 * 实验平台:正点原子 STM32开发板
 * 在线视频:www.yuanzige.com
 * 技术论坛:www.openedv.com
 * 公司网址:www.alientek.com
 * 购买地址:openedv.taobao.com
 *
 ****************************************************************************************************
 */

#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"
#include "./BSP/BEEP/beep.h"
#include "./BSP/KEY/key.h"
#include "./BSP/EXIT/exit.h"


int main(void)
{
    uint8_t len;
    uint16_t times=0;

    HAL_Init();                         /* 初始化HAL库 */
    sys_stm32_clock_init(RCC_PLL_MUL9); /* 设置时钟,72M */
    delay_init(72);                     /* 初始化延时函数 */
    usart_init(115200);                /* 初始化串口 */
    led_init();                         /* 初始化LED */
    beep_init();                        /* 初始化蜂鸣器 */
    key_init();                         /* 初始化按键 */
    exit_init();                        /* 初始化外部中断 */

    while(1)
    {
        if (g_usart_rx_sta & 0x8000)
    {
        len=g_usart_rx_sta & 0x3FFF;
        printf("\r\n您发送的消息为:\r\n "); /* 打印接收到的数据 */

        HAL_UART_Transmit(&g_uart1_handle,(uint8_t*)g_usart_rx_buf,len,1000);
        while(__HAL_UART_GET_FLAG(&g_uart1_handle,UART_FLAG_TC)!=SET); /* 等待发送完成 */
         LED1_TOGGLE();
        delay_ms(50);
         LED1_TOGGLE();

        printf("\r\n\r\n");
        g_usart_rx_sta=0;
    }
    else{
        times++;
        if (times%5000==0)
        {
            printf("Hello, STM32!\r\n"); /* 每隔5秒打印一次 */
        }
        if(times%200==0)
        {
            printf("enter data,enter to send!\r\n");
        }
        if(times%30==0)
        {
            LED0_TOGGLE(); /* 每隔30ms切换一次LED1状态 */
        }
        delay_ms(10);
    }
    }
}
