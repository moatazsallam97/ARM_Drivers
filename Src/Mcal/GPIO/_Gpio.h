/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  _Gpio.h
 *       Module:  Gpio
 *
 *  Description:  header file for Gpio Module    
 *  
 *********************************************************************************************************************/
#ifndef _Gpio_H
#define _Gpio_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
 
#include "Std_Types.h"
#include "Gpio_Cfg.h"
#include "Mcu_Hw.h"
#include "Gpio_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
#define PORTE 4
#define PORTF 5

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
* \Syntax          : void Gpio_Init(void)
* \Description     : Initalize GPIO.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpio_Init(void);

/******************************************************************************
* \Syntax          : Dio_ChannelLevel Dio_ReadChannel(Dio_ChannelType ChannelType);                                      
* \Description     : Reads a certain bit level (high or low).                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
Dio_ChannelLevel Dio_ReadChannel(Dio_ChannelType ChannelType);

/******************************************************************************
* \Syntax          : void Dio_WriteChannel(Dio_ChannelType ChannelType, Dio_ChannelLevel ChannelLevel);                                      
* \Description     : writes on a certain bit.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Dio_ChannelType                     
* \Parameters (out): Dio_ChannelLevel                                                      
* \Return value:   : Dio_ChannelLevel
*******************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelType, Dio_ChannelLevel ChannelLevel);

/******************************************************************************
* \Syntax          : Dio_PortLevel Dio_ReadPort(Dio_PortLevel PortLevel);                                       
* \Description     : Read the whole port as a uint8                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Dio_ChannelLevel, Dio_ChannelType                    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
Dio_PortLevel Dio_ReadPort(Dio_PortType PortLevel);

/******************************************************************************
* \Syntax          : Dio_PortLevel Dio_ReadPort(Dio_PortLevel PortLevel);                                      
* \Description     :                                     
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Dio_PortType                     
* \Parameters (out): Dio_PortLevel                                                      
* \Return value:   : Dio_PortLevel
*******************************************************************************/
void Dio_WritePort(Dio_PortLevel PortLevel, Dio_PortType PortType);

/******************************************************************************
* \Syntax          : void Port_Init(const ConfigType Config);                                      
* \Description     : Initialize the port.                                     
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigType                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Port_Init(const ConfigType Config);

#endif  /* _GPIO_H */

/**********************************************************************************************************************
 *  END OF FILE: _Gpio.h
 *********************************************************************************************************************/
