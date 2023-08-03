/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Wdt.c
 *        \brief  Watchdog Timer Controller Driver
 *
 *      \details  The Driver Configure Watchdog Timer registers and control.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Wdt.h"


/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

WatchdogCallback WdtCallback = NULL_PTR;

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
* \Syntax          : void Wdg_Init(Wdg_InitialTimeout InitialTimeout)                                      
* \Description     : Initialize the watchdog timer.                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Wdg_InitialTimeout InitialTimeout                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Wdg_Init(Wdg_InitialTimeout InitialTimeout){
    RCGCWD |= (1 << R1);                                        // Enabling clock to wdg
    WDTLOCK = Wdt_UnlockValue;                                  // unlocking watchdog timer
    uint32 Timeout_Ticks = InitialTimeout / Timeout_Ratio;      // Calculating Ticks
    while(READBIT(WDTCTL, WRC) == 0);                           // Checking WRC till it becomes 1.
    WDTLOAD = Timeout_Ticks;                                    // Loading The value into WDTLOAD
    //while(READBIT(WDTCTL, WRC) == 0);                         // Checking WRC till it becomes 1.

    
    #if TriggerSystemReset == 1
    while(READBIT(WDTCTL, WRC) == 0);                           // Checking WRC till it becomes 1.
    WDTCTL |= (1 << RESEN);                                     // Setting RESEN BIT
    #else
    while(READBIT(WDTCTL, WRC) == 0);                           // Checking WRC till it becomes 1.
    WDTCTL &= ~(1 << RESEN);                                    // Clearing RESEN BIT
    #endif

    #if Wdg_Notification == 1
    WdtCallback = Wdg_InterruptNotification();

    #elif Wdg_Notification == 0
    WdtCallback = NULL_PTR;

    #endif  


    #if Wdg_InterruptType == InterruptType_Standard
    while(READBIT(WDTCTL, WRC) == 0);                           // Checking WRC till it becomes 1.
    WDTCTL &= ~(1 << INTTYPE);                                   // Interrupt type is standard.
    #elif Wdg_InterruptType == InterruptType_NonMaskable
    while(READBIT(WDTCTL, WRC) == 0);                           // Checking WRC till it becomes 1.
    WDTCTL |= (1 << INTTYPE);                                   // Interrupt type is non-maskable.
    #endif

    
    while(READBIT(WDTCTL, WRC) == 0);                           // Checking WRC till it becomes 1.
    WDTCTL |= (1 << INTEN);                                     // enabling watchdog timer, and it starts counting.


    #if LockWdg == 1
    while(READBIT(WDTCTL, WRC) == 0);                           // Checking WRC till it becomes 1.
    WDTLOCK = 0xFF;                                             // Locking WDT Registers with typing any value in WDTLOCK.
    #endif
}

/******************************************************************************
* \Syntax          : void Wdg_SetTriggerCondition(uint16 Timeout)                                      
* \Description     : Refreshes the watchdog timer.                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : uint16 Timeout                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Wdg_SetTriggerCondition(uint16 Timeout){
    uint32 Timeout_Ticks = Timeout / Timeout_Ratio;
    #if LockWdg == 0
    while(READBIT(WDTCTL, WRC) == 0);
    WDTLOAD = Timeout_Ticks;
    #else
    while(READBIT(WDTCTL, WRC) == 0);
    WDTLOCK = Wdt_UnlockValue;
    while(READBIT(WDTCTL, WRC) == 0);
    WDTLOAD = Timeout_Ticks;
    while(READBIT(WDTCTL, WRC) == 0);
    WDTLOCK = 0xFF;
    #endif
}


/******************************************************************************
* \Syntax          : void WDT0_Handler(void)                                  
* \Description     : ISR of the watchdog timer.                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void WDT0_Handler(void){
  if (WdtCallback != NULL_PTR){
    WdtCallback();
  }
}

/**********************************************************************************************************************
 *  END OF FILE: Wdt.c
 *********************************************************************************************************************/
