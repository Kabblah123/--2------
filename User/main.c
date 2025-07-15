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
#include "./BSP/WDG/wdg.h"


int main(void)
{


    HAL_Init();                         /* ��ʼ��HAL�� */
    sys_stm32_clock_init(RCC_PLL_MUL9); /* ����ʱ��,72M */
    delay_init(72);                     /* ��ʼ����ʱ���� */
    usart_init(115200);                /* ��ʼ������ */
    led_init();                         /* ��ʼ��LED */
    key_init();                         /* ��ʼ������ */
    delay_ms(100);
    iwdg_init(IWDG_PRESCALER_64, 625); /* ��ʼ�����Ź�,��Ƶϵ��64,����ֵ625 */
    LED0(0);                            /* ����LED0 */
    while(1)
    {
       if(key_scan(1) == KEY2_PRES) /* ���°���0 */
       {
           iwdg_feed();
       }
       delay_ms(10);
    }
}
