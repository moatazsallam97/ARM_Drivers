/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Gpt.h
 *       Module:  Gpt
 *
 *  Description:  header file for Gpt Module    
 *  
 *********************************************************************************************************************/
#ifndef Gpt_H
#define Gpt_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
 
#include "Std_Types.h"
#include "Gpt_Cfg.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
/******************************************************************************
* \Syntax          : void Gpt_Init(void);                                    
* \Description     : Initialize all predefined Timers.                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_Init(void);

/******************************************************************************
* \Syntax          : void Gpt_StartTimer(Gpt_ConfigType ConfigType);                                    
* \Description     : Start a certain timer depending on the configtype.
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Gpt_ConfigType ConfigType.                    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_StartTimer(Gpt_ConfigType ConfigType);

/******************************************************************************
* \Syntax          : void Gpt_StopTimer(Gpt_ChannelId ChannelId);                                    
* \Description     : Stops a certain timer depending on ChannelId                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_StopTimer(Gpt_ChannelId ChannelId);

/******************************************************************************
* \Syntax          : Gpt_TimerValue Gpt_GetTimeElapsed(Gpt_ConfigType ConfigType);                                    
* \Description     : Calculates the time elapsed.                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Gpt_ConfigType ConfigType                    
* \Parameters (out): Gpt_TimerValue                                                      
* \Return value:   : Gpt_TimerValue
*******************************************************************************/
Gpt_TimerValue Gpt_GetTimeElapsed(Gpt_ConfigType ConfigType);

/******************************************************************************
* \Syntax          : void Gpt_Init(void);                                    
* \Description     : Initialize all predefined Timers.                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
//Gpt_TimerValue Gpt_GetTimeRemaining(Gpt_ChannelId ChannelId);


/******************************************************************************
* \Syntax          : void Gpt_Init(void);                                    
* \Description     : Initialize all predefined Timers.                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
//Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType ChannelId);

#endif  /* Gpt_H */

/**********************************************************************************************************************
 *  END OF FILE: Gpt.h
 *********************************************************************************************************************/
