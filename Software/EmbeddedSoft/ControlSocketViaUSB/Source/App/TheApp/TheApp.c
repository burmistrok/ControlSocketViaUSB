/*
 * TheApp.c
 *
 *  Created on: May 10, 2020
 *      Author: ok
 */

#include "TheApp.h"
#include "VirtualComPort.h"
#include "TheApp_Type.h"

#define TURNON_OUT1()		HAL_GPIO_WritePin(OUT1_GPIO_Port, OUT1_Pin, GPIO_PIN_SET)
#define TURNON_OUT2()		HAL_GPIO_WritePin(OUT2_GPIO_Port, OUT2_Pin, GPIO_PIN_SET)
#define TURNON_OUT3()		HAL_GPIO_WritePin(OUT3_GPIO_Port, OUT3_Pin, GPIO_PIN_SET)
#define TURNOFF_OUT1()		HAL_GPIO_WritePin(OUT1_GPIO_Port, OUT1_Pin, GPIO_PIN_RESET)
#define TURNOFF_OUT2()		HAL_GPIO_WritePin(OUT2_GPIO_Port, OUT2_Pin, GPIO_PIN_RESET)
#define TURNOFF_OUT3()		HAL_GPIO_WritePin(OUT3_GPIO_Port, OUT3_Pin, GPIO_PIN_RESET)


static void vTheAppProcessingCmd(void);
static void vTheAppExecutionCmd(void);



#define THEAPP_RECURENCE_TASC (1u)

#define THE_APP_DELAY 	5000u/THEAPP_RECURENCE_TASC

static bool bTheAppInit = false;
static TS_Buffer RX_Buffer;
static TS_Buffer TX_Buffer;
static TE_THEAPP_STATE e_theAppState;
static uint16_t u16_TheAppDelay;
static TE_THEAPP_CMD_ID eActualCmd;
static const uint8_t cau8_InitMsg[] = "Soft Ver: 0.1.0\n\rBe careful, Hardware Ver. 0.0.1 and it was assembled using the most modern basement technologies from China.\n\rFor more info please see https://github.com/burmistrok/ControlSocketViaUSB OR\n\rsend Help\\n over communication line\n\r";
static const uint8_t cau8_MsgForNA_cmd[] = "This command is not available, for more information, please send: HELP\\n\n\r";
static const uint8_t cau8_HelpMsg[] = "For more info please see https://github.com/burmistrok/ControlSocketViaUSB\n\rAvailable commands are:\n\r";
void vTheApp_Init			(const void* configPtr)
{
	bTheAppInit = true;
	(void)configPtr;

	e_theAppState = WAIT_FOR_CONNECTING;

	u16_TheAppDelay = THE_APP_DELAY;
	RX_Buffer.u16_BufferSize = 0u;
	vMemsetMv(RX_Buffer.u8_Buffer, 0u, BUFFER_SIZE);
	TX_Buffer.u16_BufferSize = 0u;
	vMemsetMv(TX_Buffer.u8_Buffer, 0u, BUFFER_SIZE);
	eActualCmd = NA_CMD;

}


void vTheApp_DeInit			(void)
{
	bTheAppInit = false;

}
void vTheApp_MainFunction	(void)
{
	uint8_t lu8_data = 0u;

	if (bTheAppInit != true)
	{
		return;
	}
	else
	{
		switch (e_theAppState)
		{

		case WAIT_FOR_CONNECTING:

			if (0 < u16_TheAppDelay--)
			{
				return;
			}
			else
			{
				e_theAppState = SEND_INIT_DAT;
			}
			break;

		case SEND_INIT_DAT:
			vVirtualComPort_SendBuffer((uint8_t*)cau8_InitMsg, (sizeof (cau8_InitMsg) - 1u) );
			e_theAppState = WAIT_CMD;
			break;

		case WAIT_CMD:
			if ( true == bVirtualComPort_GetChar(&lu8_data) )
			{
				if (BUFFER_SIZE > RX_Buffer.u16_BufferSize)
				{
					RX_Buffer.u8_Buffer[RX_Buffer.u16_BufferSize++] = lu8_data;
					if ('\n' == lu8_data)
					{
						e_theAppState = PROCESSING_CMD;
					}
				}
				else
				{
					e_theAppState = PROCESSING_CMD;
				}
			}
			break;

		case PROCESSING_CMD:
			vtoUpperMv(RX_Buffer.u8_Buffer, RX_Buffer.u16_BufferSize);
			vTheAppProcessingCmd();
			vMemsetMv(RX_Buffer.u8_Buffer, 0u, RX_Buffer.u16_BufferSize);
			e_theAppState = EXECUT_OF_CMD;
			break;

		case EXECUT_OF_CMD:
			vTheAppExecutionCmd();
			e_theAppState = WAIT_CMD;
			break;

		default:
#ifdef SUPPORT_RESET_CMD
			NVIC_SystemReset();
#endif
			break;

		}


	}

}

static void vTheAppProcessingCmd(void)
{

	uint8_t lu8_ActPos = 0u;

	for (lu8_ActPos = 0u;lu8_ActPos < cu8_NoOfCmd;lu8_ActPos++)
	{
		if (true == bStrstrMv(RX_Buffer.u8_Buffer, (uint8_t*) cas_CmdList[lu8_ActPos].cpu8_Cmd,RX_Buffer.u16_BufferSize) )
		{
			eActualCmd = cas_CmdList[lu8_ActPos].e_IdOfCmd;
			break;
		}else
		{
			eActualCmd = NA_CMD;
		}
	}
}

static void vTheAppExecutionCmd(void)
{
	uint8_t lu8_ActPos = 0u;
	vMemsetMv(TX_Buffer.u8_Buffer, 0u, TX_Buffer.u16_BufferSize);
	TX_Buffer.u16_BufferSize = 0u;

	switch(eActualCmd)
	{
	case HELP:
		TX_Buffer.u16_BufferSize = u16_strcatMv(TX_Buffer.u8_Buffer, (uint8_t*)cau8_HelpMsg, 0u);
		for (lu8_ActPos = 0u;lu8_ActPos < cu8_NoOfCmd;lu8_ActPos++)
		{
			TX_Buffer.u16_BufferSize = u16_strcatMv(TX_Buffer.u8_Buffer, (uint8_t*)cas_CmdList[lu8_ActPos].cpu8_Cmd, TX_Buffer.u16_BufferSize);
			TX_Buffer.u16_BufferSize = u16_strcatMv(TX_Buffer.u8_Buffer, (uint8_t*)&"\n\r", TX_Buffer.u16_BufferSize);
		}
		vVirtualComPort_SendBuffer(TX_Buffer.u8_Buffer, TX_Buffer.u16_BufferSize );
		break;

	case ON_OUT1:
		TURNON_OUT1();
		break;

	case ON_OUT2:
		TURNON_OUT2();
		break;

	case ON_OUT3:
		TURNON_OUT3();
		break;

	case OFF_OUT1:
		TURNOFF_OUT1();
		break;

	case OFF_OUT2:
		TURNOFF_OUT2();
		break;

	case OFF_OUT3:
		TURNOFF_OUT3();
		break;
#ifdef SUPPORT_RESET_CMD
	case THEAPP_RESET:
		NVIC_SystemReset();
		break;
#endif

	default:
		vVirtualComPort_SendBuffer((uint8_t*)cau8_MsgForNA_cmd, (sizeof (cau8_MsgForNA_cmd) - 1u) );
		break;


	}
	if ( (NA_CMD != eActualCmd) && (HELP != eActualCmd))
	{
		TX_Buffer.u16_BufferSize = u16_strcatMv(TX_Buffer.u8_Buffer, (uint8_t*)cas_CmdList[eActualCmd].cpu8_Cmd, 0u);
		TX_Buffer.u16_BufferSize = u16_strcatMv(TX_Buffer.u8_Buffer, (uint8_t*)&"\n\rOK\n\r", TX_Buffer.u16_BufferSize);
		vVirtualComPort_SendBuffer(TX_Buffer.u8_Buffer, TX_Buffer.u16_BufferSize );
	}
}

