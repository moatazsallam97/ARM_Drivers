/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "IntCtrl.h"


/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	


/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
 


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void __attribute__((interrupt)) SVC_Handler(void)                                      
* \Description     : Turn on the privileged mode.                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : uint8                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void __attribute__((interrupt)) SVC_Handler(void){
        return;
}

/******************************************************************************
* \Syntax          : void PrivilegeOFF(void)                                      
* \Description     : Turn off the privileged mode.                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : uint8                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void PrivilegeOFF(void){
        return;
}

/******************************************************************************
* \Syntax          : void Group_SubGroup_Init(void)                                      
* \Description     : initialize APINT register for the Group & SubGroup based                                                                               
*                    on user inputs.                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Group_SubGroup_Init(void){
    uint8 Option;
    Option = GROUP_SUBGROUP;
    switch(Option) {
        case 0:
        APINT = (0x05FA << 16) | (0x0 << 8);
        break;
        case 1:
        APINT = (0x05FA << 16) | (0x5 << 8);
        break;
        case 2:
        APINT = (0x05FA << 16) | (0x6 << 8);
        break;
        case 3:
        APINT = (0x05FA << 16) | (0x7 << 8);
        break;
        default:
        break;
    }
}

 /******************************************************************************
* \Syntax          : void Priority_Set(User_Data_Type given_user_data)                                      
* \Description     : Sets the priorties for each interrupt user wants to use.                                                                                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : User_Data_Type                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Priority_Set(User_Data_Type given_user_data){
    uint8 x = given_user_data.InetrruptType;
    uint8 pri = given_user_data.Priority;
    SET_PRI(x, pri)
}

 /******************************************************************************
* \Syntax          : void Interrupt_Enable(User_Data_Type given_user_data)                                      
* \Description     : Enables the Interrupts that user want to use.                                                                                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : User_Data_Type                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Interrupt_Enable(User_Data_Type given_user_data){
    uint8 IntNumber = given_user_data.InetrruptType;
    ENX(IntNumber) = (1 << IntNumber);
}

 /******************************************************************************
* \Syntax          : void Interrupt_Disable(User_Data_Type given_user_data)                                      
* \Description     : Disable the Interrupts that user want to use.                                                                                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : User_Data_Type                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Interrupt_Disable(User_Data_Type given_user_data){    //0xE000E100
    uint8 IntNumber = given_user_data.InetrruptType;
    DISX(IntNumber) = (1 << IntNumber);
}

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
void IntCrtl_Init(void)
{
		extern User_Data_Type g_user_data1;
		extern User_Data_Type g_user_data2;
	
	/*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
    
    Group_SubGroup_Init();

    /*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/  
    
    Priority_Set(g_user_data1);
    Priority_Set(g_user_data2);

	/*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
    
    Interrupt_Enable(g_user_data1);
    Interrupt_Enable(g_user_data2);
}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
