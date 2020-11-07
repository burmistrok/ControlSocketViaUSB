/*
 * Led.c
 *
 *  Created on: 13 ���. 2020 �.
 *      Author: ok
 */
/*!< Include section ------------------------------------------------------------------------------- */
#include "VirtualComPort.h"
#include "Utils.h"
#include "CircularFIFOBuffer.h"


/*******************************************************************************//**
 * @addtogroup App Manager
 * @{
 **********************************************************************************/

/*******************************************************************************//**
 * @addtogroup VirtualComPort
 * @brief SomeThing
 * @{
 */


/*!< Definitions section --------------------------------------------------------------------------- */

/*! \def CYCLIC_TASK_RECURRENCE
    \brief Defines the recurrence of the module cyclic function (ms).
 */
#define VirtualComPort_CYCLIC_TASK_RECURRENCE      (1)


/*!< Type definitions section ---------------------------------------------------------------------- */
#define TIMEOUT_FOR_1SEC		1000u

#define USE_ECHO

/*!< Exported variables section -------------------------------------------------------------------- */


/*!< Static variable section ----------------------------------------------------------------------- */
static bool bVirtualComPortInit = false;
TS_CircularFIFOBuffer S_RXBuffer;
/*!< Static functions prototypes sections ---------------------------------------------------------- */


/*!< Static functions definition sections ---------------------------------------------------------- */


/*!< Function definitions -------------------------------------------------------------------------- */
extern uint8_t CDC_Transmit_FS(uint8_t* Buf, uint16_t Len);

/***************************************************************************//**
 * \fn VirtualComPort_Init
 * \brief   The module initialisation function.
 * \details
 * \param[in] ConfigPtr - A pointer to the initialisation configuration.
 * \return  This function has no return value.
 * \callgraph
 * \callergraph
 ******************************************************************************/
void vVirtualComPort_Init(const void* configPtr)
{

	bVirtualComPortInit = true;
	(void)configPtr;
}


/***************************************************************************//**
 * \fn VirtualComPort_MainFunction
 * \brief   The module main function.
 * \details
 * \param[in] void
 * \return  This function has no return value.
 * \callgraph
 * \callergraph
 ******************************************************************************/
void vVirtualComPort_MainFunction(void)
{

    if(false == bVirtualComPortInit){ /* if not initialised, don't execute */
        return;
    }

	/*Write here your code*/

#if defined (USE_ECHO)
	    uint8_t buffer[BUFFER_SIZE];
	    uint16_t lu16_len = 0u;
	    while (bCircularFIFOBuffer_getElement(&S_RXBuffer, &buffer[lu16_len]) != false)
	    {
	    	lu16_len++;
	    }
	    if (lu16_len > 0u)
	    {
	    	CDC_Transmit_FS( &buffer[0], lu16_len);
	    }
#endif //end USE_ECHO

}

/***************************************************************************//**
 * \fn VirtualComPort_ReceiveData_Callback
 * \brief   The module  is called in the interrupt at received data via USB, and put data in the FIFO  RX buffer
 * \details
 * \param[in] uint8_t* Buf - address to the received buffer
 * 			  uint32_t Len	- length of the received data
 * \return  This function has no return value.
 * \callgraph
 * \callergraph
 ******************************************************************************/
void vVirtualComPort_ReceiveData_Callback (uint8_t* Buf, uint32_t Len)
{
	uint32_t lu32_counter;
	uint8_t lu8_flag = 0u;

	for (lu32_counter = 0u; lu32_counter < Len; lu32_counter++){
		lu8_flag = bCircularFIFOBuffer_addElement(&S_RXBuffer, *Buf );
		Buf++;
		if (lu8_flag == false)
			break;
	}
}


/***************************************************************************//**
 * \fn VirtualComPort_SendBuffer
 * \brief   The module  send buffer via USB
 * \details
 * \param[in] uint8_t* Buf - address to the buffer
 * 			  uint32_t Len	- length of the data
 * \return  This function has no return value.
 * \callgraph
 * \callergraph
 ******************************************************************************/
void vVirtualComPort_SendBuffer(uint8_t* Buf, uint32_t Len)
{
	CDC_Transmit_FS(Buf, Len);
}

/***************************************************************************//**
 * \fn VirtualComPort_GetChar
 * \brief   The module return a char from FIFO RX buffer
 * \details
 * \param[in] uint8_t* Data - address of the buffer for char
 * \return  This function return status of the request.
 * \callgraph
 * \callergraph
 ******************************************************************************/
bool bVirtualComPort_GetChar(uint8_t* Data)
{
	bool lb_Data;
	lb_Data = bCircularFIFOBuffer_getElement(&S_RXBuffer, Data);

	return lb_Data;
}
/****************************************************************************************/
