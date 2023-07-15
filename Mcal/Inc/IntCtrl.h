/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCrtl.h
 *       Module:  IntCrtl
 *
 *  Description:  header file for IntCrtl Module    
 *  
 *********************************************************************************************************************/
#ifndef IntCrtl_H
#define IntCrtl_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl_Cfg.h"
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
* \Syntax          : void SVC_Handler(void)                                      
* \Description     : Turn on the privileged mode.                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : uint8                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void SVC_Handler(void);

/******************************************************************************
* \Syntax          : void PrivilegeOFF(void)                                      
* \Description     : Turn off the privileged mode.                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : uint8                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void PrivilegeOFF(void);

 /******************************************************************************
* \Syntax          : void Group_SubGroup_INIT(void)                                      
* \Description     : initialize APINT register for the Group & SubGroup based                                                                               
*                    on user inputs.                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Group_SubGroup_Init(void);

 /******************************************************************************
* \Syntax          : void Priority_Set(User_Data_Type given_user_data)                                      
* \Description     : Sets the priorties for each interrupt user wants to use.                                                                                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : User_Data_Type                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Priority_Set(User_Data_Type given_user_data);

 /******************************************************************************
* \Syntax          : void Interrupt_Enable(User_Data_Type given_user_data)                                      
* \Description     : Enables the Interrupts that user want to use.                                                                                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : User_Data_Type                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Interrupt_Enable(User_Data_Type given_user_data);

 /******************************************************************************
* \Syntax          : void Interrupt_Disable(User_Data_Type given_user_data)                                      
* \Description     : Disable the Interrupts that user want to use.                                                                                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : User_Data_Type                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Interrupt_Disable(User_Data_Type given_user_data); 
 
/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(void);
 
#endif  /* IntCrtl_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.h
 *********************************************************************************************************************/
