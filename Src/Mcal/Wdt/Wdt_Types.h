/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Wdt_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef Wdt_TYPES_H
#define Wdt_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define InterruptType_Standard      0
#define InterruptType_NonMaskable   1
#define Wdt_UnlockValue    0x1ACCE551
#define Timeout_Ratio       0.0000625                   // for 16 Mhz

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef uint16 Wdg_InitialTimeout;                      // with m sec.
typedef void (*WatchdogCallback)(void);

#endif  /* Wdt_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Wdt_Types.h
 *********************************************************************************************************************/
