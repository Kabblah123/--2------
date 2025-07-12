#include "./BSP/EXIT/exit.h"
#include "./BSP/KEY/key.h"
#include "./BSP/LED/led.h"
#include "./BSP/BEEP/beep.h"
void exit_init(void)
{
    GPIO_InitTypeDef GPIO_init_struct;
    GPIO_init_struct.Pin=KEY0_INT_GPIO_PIN;
    GPIO_init_struct.Mode=GPIO_MODE_IT_FALLING;
    GPIO_init_struct.Pull=GPIO_PULLUP;
    HAL_GPIO_Init(KEY0_INT_GPIO_PORT,&GPIO_init_struct);

    GPIO_init_struct.Pin=KEY1_INT_GPIO_PIN;
    GPIO_init_struct.Mode=GPIO_MODE_IT_FALLING;
    GPIO_init_struct.Pull=GPIO_PULLUP;
    HAL_GPIO_Init(KEY1_INT_GPIO_PORT,&GPIO_init_struct);

    GPIO_init_struct.Pin=KEY2_INT_GPIO_PIN;
    GPIO_init_struct.Mode=GPIO_MODE_IT_RISING;
    GPIO_init_struct.Pull=GPIO_PULLDOWN;
    HAL_GPIO_Init(KEY2_INT_GPIO_PORT,&GPIO_init_struct);

    HAL_NVIC_SetPriority(KEY0_INT_IRQn,0,2);
    HAL_NVIC_EnableIRQ(KEY0_INT_IRQn);
    HAL_NVIC_SetPriority(KEY1_INT_IRQn,1,2);
    HAL_NVIC_EnableIRQ(KEY1_INT_IRQn);
    HAL_NVIC_SetPriority(KEY2_INT_IRQn,3,2);
    HAL_NVIC_EnableIRQ(KEY2_INT_IRQn);
}

void KEY0_INT_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(KEY0_INT_GPIO_PIN);
    __HAL_GPIO_EXTI_CLEAR_IT(KEY0_INT_GPIO_PIN);
}

void KEY1_INT_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(KEY1_INT_GPIO_PIN);
    __HAL_GPIO_EXTI_CLEAR_IT(KEY1_INT_GPIO_PIN);
}

void KEY2_INT_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(KEY2_INT_GPIO_PIN);
    __HAL_GPIO_EXTI_CLEAR_IT(KEY2_INT_GPIO_PIN);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    delay_ms(20);
    switch(GPIO_Pin)
    {
        case KEY0_INT_GPIO_PIN:
        if (KEY0==0)
        {
            LED0_TOGGLE();
            LED1_TOGGLE();
        }
        break;

        case KEY1_INT_GPIO_PIN:
        if (KEY1==0)
        {
            LED0_TOGGLE();
        }
        break;

       case KEY2_INT_GPIO_PIN:
        if (KEY2==1)
        {
            BEEP_TOGGLE();
        }
        break; 
    }
}
