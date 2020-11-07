/*
 * SchM_Callouts.c
 *
 *  Created on: Apr 13, 2020
 *      Author: ok
 */


#include "SchM.h"
#include "Led.h"
#include "VirtualComPort.h"
#include "TheApp.h"


/****************************************************************************************
 * Funtion:
 * @brief:
 * Parameters:
 * Return:
 */
void vSchM_IdleTask(void)
{

}

/***************************************************************************************
 * Funtion:
 * @brief:
 * Parameters:
 * Return:
 */
void vSchM_BaseRecurrenceTask	(void)
{
	vTheApp_MainFunction();
	vLed_MainFunction();
	vVirtualComPort_MainFunction();

}

/***************************************************************************************
 * Funtion:
 * @brief:
 * Parameters:
 * Return:
 */
void vSchM_BaseRecurrenceTaskDiv2(void)
{


}

/*************************************************************************************
 * Funtion:
 * @brief:
 * Parameters:
 * Return:
 */
void vSchM_BaseRecurrenceTaskDiv4(void)
{


}

/***************************************************************************************
 * Funtion:
 * @brief:
 * Parameters:
 * Return:
 */
void vSchM_BaseRecurrenceTaskDiv8(void)
{


}

/***************************************************************************************
 * Funtion:
 * @brief:
 * Parameters:
 * Return:
 */
void vSchM_BaseRecurrenceTaskDiv16(void)
{


}


/***************************************************************************************
 * Funtion:
 * @brief:
 * Parameters:
 * Return:
 */
void vSchM_BaseRecurrenceTaskDiv32(void)
{


}
