#ifndef __WDG_H
#define __WDG_H

#include "./SYSTEM/sys/sys.h"


void iwdg_init(uint8_t prer, uint16_t rlr);
void iwdg_feed(void);

void wwdg_init(uint8_t tr, uint8_t wr, uint32_t fprer);
void HAL_WWDG_MSInit(WWDG_HandleTypeDef *hwwdg);
void WWDG_IRQHandler(void);
void HAL_WWDG_EarlyWakeupCallback(WWDG_HandleTypeDef *hwwdg);

#endif
