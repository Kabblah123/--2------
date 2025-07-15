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
#include "./BSP/WDG/wdg.h"


int main(void)
{


    HAL_Init();                         /* 初始化HAL库 */
    sys_stm32_clock_init(RCC_PLL_MUL9); /* 设置时钟,72M */
    delay_init(72);                     /* 初始化延时函数 */
    usart_init(115200);                /* 初始化串口 */
    led_init();                         /* 初始化LED */
    key_init();                         /* 初始化按键 */
    delay_ms(100);
    iwdg_init(IWDG_PRESCALER_64, 625); /* 初始化看门狗,分频系数64,计数值625 */
    LED0(0);                            /* 开启LED0 */
    while(1)
    {
       if(key_scan(1) == KEY2_PRES) /* 按下按键0 */
       {
           iwdg_feed();
       }
       delay_ms(10);
    }
}
