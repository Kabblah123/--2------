#include "./BSP/TIMER/btim.h"
#include "./BSP/LED/led.h"

TIM_HandleTypeDef g_timx_handle;

void btim_int_init(uint16_t arr, uint16_t psc)
{
    g_timx_handle.Instance = BTIM_TIMX_INT;
    g_timx_handle.Init.Prescaler=psc;
    g_timx_handle.Init.CounterMode=TIM_COUNTERMODE_UP;
    g_timx_handle.Init.Period=arr;
    HAL_TIM_Base_Init(&g_timx_handle);
    HAL_TIM_Base_Start_IT(&g_timx_handle);
}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
    if(htim->Instance ==BTIM_TIMX_INT)
    {
        BTIM_TIMX_INT_CLK_ENABLE();
        HAL_NVIC_SetPriority(BTIM_TIMX_INT_IRQn,1,3);
        HAL_NVIC_EnableIRQ(BTIM_TIMX_INT_IRQn);
    }
}

void BTIM_TIMX_INT_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&g_timx_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim->Instance == BTIM_TIMX_INT)
    {
        LED1_TOGGLE();
    }
}

