#include "./BSP/WDG/wdg.h"
#include "./BSP/LED/led.h"

IWDG_HandleTypeDef g_iwdg_handle;
void iwdg_init(uint8_t prer, uint16_t rlr)
{
    g_iwdg_handle.Instance=IWDG;
    g_iwdg_handle.Init.Prescaler=prer; /* 设置IWDG分频系数 */
    g_iwdg_handle.Init.Reload=rlr;
    HAL_IWDG_Init(&g_iwdg_handle);
}

void iwdg_feed(void)
{
    HAL_IWDG_Refresh(&g_iwdg_handle); /* 喂狗 */
}
WWDG_HandleTypeDef g_wwdg_handle;  /* WWDG句柄 */




void wwdg_init(uint8_t tr, uint8_t wr, uint32_t fprer)
{
    g_wwdg_handle.Instance = WWDG;
    g_wwdg_handle.Init.Prescaler = fprer;                      /* 预分频 */
    g_wwdg_handle.Init.Window = wr;
    g_wwdg_handle.Init.Counter = tr;
    g_wwdg_handle.Init.EWIMode = WWDG_EWI_ENABLE;            /* 启用早期唤醒中断 */
    HAL_WWDG_Init(&g_wwdg_handle);
}

 

void HAL_WWDG_MspInit(WWDG_HandleTypeDef *hwwdg)
{
    __HAL_RCC_WWDG_CLK_ENABLE();
    HAL_NVIC_SetPriority(WWDG_IRQn,2,3);
    HAL_NVIC_EnableIRQ(WWDG_IRQn);
}

void WWDG_IRQHandler(void)
{
    HAL_WWDG_IRQHandler(&g_wwdg_handle);
}

void HAL_WWDG_EarlyWakeupCallback(WWDG_HandleTypeDef *hwwdg)
{
    /* 早期唤醒回调函数 */
    /* 可以在这里添加代码来处理早期唤醒事件 */
    HAL_WWDG_Refresh(&g_wwdg_handle); /* 刷新窗口看门狗 */
    LED1_TOGGLE(); /* 切换LED1状态 */
}

