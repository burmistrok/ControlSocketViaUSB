/*
 * Init.c
 *
 *  Created on: 13 апр. 2020 г.
 *      Author: ok
 */

#include "Init.h"
#include "Sys.h"
#include "SchM.h"
#include "Led.h"
#include "core_cm3.h"
#include "gpio.h"
#include "TheApp.h"
#include "VirtualComPort.h"

/****************************************************************************************
 * Funtion:
 * @brief:
 * Parameters:
 * Return:
 */
void vInit(void)
{

#ifdef USE_SYS
	//LL_RCC_ClocksTypeDef rcc_clocks;
	//LL_RCC_GetSystemClocksFreq(&rcc_clocks);
	//vSys_Init((void*)SysTick_Config(rcc_clocks.SYSCLK_Frequency/1000));
#endif

#ifdef USE_LED
	vLed_Init(NULL_PTR);
#else
	MX_GPIO_Init();
#endif

#ifdef USE_VCP
	vVirtualComPort_Init(NULL_PTR);
#endif

#ifdef USE_THEAPP
	vTheApp_Init(NULL_PTR);
#endif

#ifdef USE_SCHM
	vSchM_Init(NULL_PTR);
	vSchM_MainFunction();
#elif
	while (1)
		;
#endif


}
