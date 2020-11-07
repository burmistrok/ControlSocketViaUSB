/*
 * TheApp.c
 *
 *  Created on: May 10, 2020
 *      Author: ok
 */

#include "TheApp.h"
#include "VirtualComPort.h"


#define THEAPP_RECURENCE_TASC (1u)

#define THE_APP_DELAY 	1000u/THEAPP_RECURENCE_TASC

static bool bTheAppInit = false;
static uint16_t lu16_Delay;

void vTheApp_Init			(const void* configPtr)
{
	lu16_Delay = 0u;
	bTheAppInit = true;
	(void)configPtr;
}


void vTheApp_DeInit			(void)
{
	bTheAppInit = false;

}
void vTheApp_MainFunction	(void)
{

	if (bTheAppInit != true)
	{
		return;
	}
	else
	{

		if (0u < lu16_Delay--)
		{
			return;
		}
		else
		{
			//vVirtualComPort_SendBuffer((uint8_t*)"HELLO\n\r", 7u);
			lu16_Delay = THE_APP_DELAY;
		}

	}

}
