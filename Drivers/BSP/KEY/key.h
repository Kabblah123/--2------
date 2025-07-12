#ifndef __KEY_H__
#define __KEY_H__
#include "./SYSTEM/sys/sys.h"

#define KEY0_GPIO_PORT GPIOE
#define KEY0_GPIO_PIN GPIO_PIN_4
#define KEY0_GPIO_CLK_ENABLE()  do{__HAL_RCC_GPIOE_CLK_ENABLE();}while(0)

#define KEY1_GPIO_PORT GPIOE
#define KEY1_GPIO_PIN GPIO_PIN_3
#define KEY1_GPIO_CLK_ENABLE()  do{__HAL_RCC_GPIOE_CLK_ENABLE();}while(0)

#define KEY2_GPIO_PORT GPIOA
#define KEY2_GPIO_PIN GPIO_PIN_0
#define KEY2_GPIO_CLK_ENABLE()  do{__HAL_RCC_GPIOA_CLK_ENABLE();}while(0)

#define KEY0  HAL_GPIO_ReadPin(KEY0_GPIO_PORT,KEY0_GPIO_PIN)
#define KEY1  HAL_GPIO_ReadPin(KEY1_GPIO_PORT,KEY1_GPIO_PIN)
#define KEY2  HAL_GPIO_ReadPin(KEY2_GPIO_PORT,KEY2_GPIO_PIN)

#define KEY0_PRES 1
#define KEY1_PRES 2
#define KEY2_PRES 3

void key_init(void);
uint8_t key_scan(uint8_t mode);
#endif
