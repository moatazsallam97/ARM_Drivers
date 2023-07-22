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
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

#define _A 0u
#define _B 1u
#define _C 2u
#define _D 3u
#define _E 4u
#define _F 5u


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
                                            /* NVIC REGISTERS */

#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000  

#define APINT                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0xD0C))
#define INTCTRL                                *((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS + 0xD04))
#define ENX(X)                                 *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x100 + ((X / 32) * 4))) // as X is the number of the interrupt. >> Determines the base address of the reg.
#define DISX(X)                                *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x180 + ((X / 32) * 4))) // as X is the number of the interrupt. >> Determines the base address of the reg.
#define PENDX(X)                               *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x200 + ((X / 32) * 4))) // as X is the number of the interrupt. >> Determines the base address of the reg.
#define UNPENDX(X)                             *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x280 + ((X / 32) * 4))) // as X is the number of the interrupt. >> Determines the base address of the reg.
#define ACTIVEX(X)                             *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x300 + ((X / 32) * 4))) // as X is the number of the interrupt. >> Determines the base address of the reg.
#define PRIX(X)                                *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x400 + ((X / 4) * 4))) // as X is the number of the interrupt. >> Determines the base address of the reg.

                                            /* GPIO REGISTERS */   // 0x40000000, 0x400FFFFF

#define RCGCGPIO_BASE_ADDRESS                  0x400FE000
#define RCGCGPIO                               *((volatile uint32*)(RCGCGPIO_BASE_ADDRESS + 0x608))  // Enabling or Disabling Clock for GPIOS


/* APB */
#define GPIO_BASE_ADDRESS_PORT(X)              ((X) <= _D ? (0x40004000 + ((X) * 0x1000))  :  (0x40020000 + ((X) * 0x1000)))


#define GPIODATAW(X,LOC)                       *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + LOC)) // LOC is location
#define GPIODATA(X)                            *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0x3FC))
#define GPIODIR(X)                             *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0x400))
#define GPIOIS(X)                              *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0x404))
#define GPIOIBE(X)                             *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0x408))
#define GPIOIEV(X)                             *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0x40C))
#define GPIOIM(X)                              *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0x410))
#define GPIORIS(X)                             *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0x414))
#define GPIOMIS(X)                             *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0x418))   
#define GPIOICR(X)                             *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0x41C))   
#define GPIOAFSEL(X)                           *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0x420))
#define GPIODR2R(X)                            *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0x500))   
#define GPIODR4R(X)                            *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0x504))
#define GPIODR8R(X)                            *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0x508))   
#define GPIOODR(X)                             *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0x50C))
#define GPIOPUR(X)                             *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0x510)) 
#define GPIOPDR(X)                             *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0x514))  
#define GPIOSLR(X)                             *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0x518))
#define GPIODEN(X)                             *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0x51C))
#define GPIOLOCK(X)                            *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0x520)) 
#define GPIOCR(X)                              *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0x524))
#define GPIOAMSEL(X)                           *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0x528)) 
#define GPIOPCTL(X)                            *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0x52C))
#define GPIOADCCTL(X)                          *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0x530))
#define GPIODMACTL(X)                          *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0x534))
#define GPIOPeriphID0(X)                       *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0xFE0))
#define GPIOPeriphID1(X)                       *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0xFE4))
#define GPIOPeriphID2(X)                       *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0xFE8))
#define GPIOPeriphID3(X)                       *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0xFEC))
#define GPIOPeriphID4(X)                       *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0xFD0))
#define GPIOPeriphID5(X)                       *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0xFD4))
#define GPIOPeriphID6(X)                       *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0xFD8))
#define GPIOPeriphID7(X)                       *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0xFDC))   
#define GPIOPCellID0(X)                        *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0xFF0))
#define GPIOPCellID1(X)                        *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0xFF4))
#define GPIOPCellID2(X)                        *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0xFF8))
#define GPIOPCellID3(X)                        *((volatile uint32*)(GPIO_BASE_ADDRESS_PORT(X) + 0xFFC))

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS LIKE FUNCTION
 *********************************************************************************************************************/

/* Global MLF */

#define SETBIT(REG,BIT) (REG |= 1 << BIT)
#define CLRBIT(REG,BIT) (REG &= ~(1 << BIT))
#define TOGBIT(REG,BIT) (REG ^= 1 << BIT)
#define READBIT(REG,BIT) ((REG >> BIT) & 1)
 
/* Interrupt Priority Setting */ 
 
#define SET_PRI(X,Y)   if ((X - ((X / 4) * 4)) == 0)  PRIX(X) |= (Y << 5); else PRIX(X) |=  (Y << (5 + ((X - ((X / 4) * 4)) * 8))); // X is the interrupt number and Y is the Priority value.

    
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
