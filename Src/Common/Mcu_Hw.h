/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef struct {
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEND  :8;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1; 
}INTCTRL_BF;

typedef union {
    uint32 R;
    INTCTRL_BF B;
}INTCTRL_Tag;


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000
#define APINT                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0xD0C))
#define INTCTRL                                *((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS + 0xD04))
#define ENX(X)                                 *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x100 + ((X / 32) * 4))) // as X is the number of the interrupt. >> Determines the base address of the reg.
#define DISX(X)                                *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x180 + ((X / 32) * 4))) // as X is the number of the interrupt. >> Determines the base address of the reg.
#define PENDX(X)                               *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x200 + ((X / 32) * 4))) // as X is the number of the interrupt. >> Determines the base address of the reg.
#define UNPENDX(X)                             *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x280 + ((X / 32) * 4))) // as X is the number of the interrupt. >> Determines the base address of the reg.
#define ACTIVEX(X)                             *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x300 + ((X / 32) * 4))) // as X is the number of the interrupt. >> Determines the base address of the reg.
#define PRIX(X)                                *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x400 + ((X / 4) * 4))) // as X is the number of the interrupt. >> Determines the base address of the reg.

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS LIKE FUNCTION
 *********************************************************************************************************************/

#define SET_PRI(X,Y)   if ((X - ((X / 4) * 4)) == 0)  PRIX(X) |= (Y << 5); else PRIX(X) |=  (Y << (5 + ((X - ((X / 4) * 4)) * 8))); // X is the interrupt number and Y is the Priority value.
    
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
