/*
 * TheApp_Type.h
 *
 *  Created on: 14 нояб. 2020 г.
 *      Author: ok
 */

#ifndef APP_THEAPP_THEAPP_TYPE_H_
#define APP_THEAPP_THEAPP_TYPE_H_

#define BUFFER_SIZE 1024u

#if 0
#define SUPPORT_RESET_CMD
#endif


typedef struct{
	uint16_t u16_BufferSize;
	uint8_t u8_Buffer[BUFFER_SIZE];

}TS_Buffer;

typedef enum
{
	WAIT_FOR_CONNECTING = 0U,
	SEND_INIT_DAT,
	WAIT_CMD,
	PROCESSING_CMD,
	EXECUT_OF_CMD

}TE_THEAPP_STATE;

typedef enum
{
	HELP = 0u,
	ON_OUT1,
	ON_OUT2,
	ON_OUT3,
	OFF_OUT1,
	OFF_OUT2,
	OFF_OUT3,
#ifdef SUPPORT_RESET_CMD
	THEAPP_RESET,
#endif
	NA_CMD

}TE_THEAPP_CMD_ID;


typedef struct
{
	TE_THEAPP_CMD_ID e_IdOfCmd;
	const uint8_t* const cpu8_Cmd;
}TS_CMD_TEMPLATE;

const TS_CMD_TEMPLATE cas_CmdList[] =
{
		{.e_IdOfCmd = HELP, .cpu8_Cmd = (uint8_t*) &"HELP" },
		{.e_IdOfCmd = ON_OUT1, .cpu8_Cmd = (uint8_t*) &"ON OUT1"},
		{.e_IdOfCmd = ON_OUT2, .cpu8_Cmd = (uint8_t*) &"ON OUT2"},
		{.e_IdOfCmd = ON_OUT3, .cpu8_Cmd = (uint8_t*) &"ON OUT3"},
		{.e_IdOfCmd = OFF_OUT1, .cpu8_Cmd = (uint8_t*) &"OFF OUT1"},
		{.e_IdOfCmd = OFF_OUT2, .cpu8_Cmd = (uint8_t*) &"OFF OUT2"},
		{.e_IdOfCmd = OFF_OUT3, .cpu8_Cmd = (uint8_t*) &"OFF OUT3"},
#ifdef SUPPORT_RESET_CMD
		{.e_IdOfCmd = THEAPP_RESET, .cpu8_Cmd = (uint8_t*) &"RESET"},
#endif

};

const uint8_t cu8_NoOfCmd = sizeof(cas_CmdList)/sizeof(TS_CMD_TEMPLATE);
#endif /* APP_THEAPP_THEAPP_TYPE_H_ */
