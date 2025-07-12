#ifndef __EXIT_H__
#define __EXIT_H__
#include "./SYSTEM/sys/sys.h"

/**
 * @brief 定义按键 KEY0 相关的 GPIO 端口、引脚、时钟使能、中断号和中断处理函数。
 * 
 * 此部分代码定义了与按键 KEY0 相关的硬件资源，包括 GPIO 端口、引脚、时钟使能操作，
 * 以及对应的中断号和中断处理函数名，方便在后续代码中使用。
 */

// 定义 KEY0 所连接的 GPIO 端口为 GPIOE
#define KEY0_INT_GPIO_PORT GPIOE
// 定义 KEY0 所连接的 GPIO 引脚为 GPIO_PIN_4
#define KEY0_INT_GPIO_PIN GPIO_PIN_4
// 定义 KEY0 对应的 GPIO 时钟使能操作，使用 do-while(0) 结构确保宏作为单条语句执行
#define KEY0_INT_GPIO_CLK_ENABLE()  do{__HAL_RCC_GPIOE_CLK_ENABLE();}while(0)
// 定义 KEY0 对应的外部中断号为 EXIT4_IRQn
#define KEY0_INT_IRQn EXTI4_IRQn
// 定义 KEY0 对应的外部中断处理函数名为 EXIT4_IRQHandler
#define KEY0_INT_IRQHandler EXTI4_IRQHandler

#define KEY1_INT_GPIO_PORT GPIOE
#define KEY1_INT_GPIO_PIN GPIO_PIN_3
#define KEY1_INT_GPIO_CLK_ENABLE()  do{__HAL_RCC_GPIOE_CLK_ENABLE();}while(0)
#define KEY1_INT_IRQn EXTI3_IRQn
#define KEY1_INT_IRQHandler EXTI3_IRQHandler

#define KEY2_INT_GPIO_PORT GPIOA
#define KEY2_INT_GPIO_PIN GPIO_PIN_0
#define KEY2_INT_GPIO_CLK_ENABLE()  do{__HAL_RCC_GPIOA_CLK_ENABLE();}while(0)
#define KEY2_INT_IRQn EXTI0_IRQn
#define KEY2_INT_IRQHandler EXTI0_IRQHandler

void exit_init(void);
void KEY0_INT_IRQHandler(void);
void KEY1_INT_IRQHandler(void);
void KEY2_INT_IRQHandler(void);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
void delay_ms(uint16_t nms);

#endif




