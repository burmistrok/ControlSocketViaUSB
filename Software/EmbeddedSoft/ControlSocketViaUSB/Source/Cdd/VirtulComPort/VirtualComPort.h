/*
 * Led.h
 *
 *  Created on: 13 ���. 2020 �.
 *      Author: ok
 */
/*!< Define to prevent recursive inclusion --------------------------------------------------------- */
#ifndef VirtualComPort_H
#define VirtualComPort_H


/*!< C++ banding section start --------------------------------------------------------------------- */
#ifdef __cplusplus
    extern "C" {
#endif


/*<! Include section ------------------------------------------------------------------------------- */
#include "Std_types.h"


/*!< Type definitions section ---------------------------------------------------------------------- */

void vVirtualComPort_Init(const void* configPtr);
void vVirtualComPort_MainFunction(void);
void vVirtualComPort_SendBuffer(uint8_t* Buf, uint32_t Len);
bool bVirtualComPort_GetChar(uint8_t* Data);


/*!< C++ banding section finish -------------------------------------------------------------------- */
#ifdef __cplusplus
    }
#endif /* __cplusplus */


#endif /* VirtualComPort_H */


/**************************************** END OF FILE ************************************************/
