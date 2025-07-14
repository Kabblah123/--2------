/**
 ****************************************************************************************************
 * @file        main.c
 * @author      ����ԭ���Ŷ�(ALIENTEK)
 * @version     V1.0
 * @date        2020-04-18
 * @brief       ������ ʵ��
 * @license     Copyright (c) 2020-2032, ������������ӿƼ����޹�˾
 ****************************************************************************************************
 * @attention
 *
 * ʵ��ƽ̨:����ԭ�� STM32������
 * ������Ƶ:www.yuanzige.com
 * ������̳:www.openedv.com
 * ��˾��ַ:www.alientek.com
 * �����ַ:openedv.taobao.com
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

    HAL_Init();                         /* ��ʼ��HAL�� */
    sys_stm32_clock_init(RCC_PLL_MUL9); /* ����ʱ��,72M */
    delay_init(72);                     /* ��ʼ����ʱ���� */
    usart_init(115200);                /* ��ʼ������ */
    led_init();                         /* ��ʼ��LED */
    beep_init();                        /* ��ʼ�������� */
    key_init();                         /* ��ʼ������ */
    exit_init();                        /* ��ʼ���ⲿ�ж� */

    while(1)
    {
        if (g_usart_rx_sta & 0x8000)
    {
        len=g_usart_rx_sta & 0x3FFF;
        printf("\r\n�����͵���ϢΪ:\r\n "); /* ��ӡ���յ������� */

        HAL_UART_Transmit(&g_uart1_handle,(uint8_t*)g_usart_rx_buf,len,1000);
        while(__HAL_UART_GET_FLAG(&g_uart1_handle,UART_FLAG_TC)!=SET); /* �ȴ�������� */
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
            printf("Hello, STM32!\r\n"); /* ÿ��5���ӡһ�� */
        }
        if(times%200==0)
        {
            printf("enter data,enter to send!\r\n");
        }
        if(times%30==0)
        {
            LED0_TOGGLE(); /* ÿ��30ms�л�һ��LED1״̬ */
        }
        delay_ms(10);
    }
    }
}
