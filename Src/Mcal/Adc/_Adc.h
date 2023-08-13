/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  _Adc.h
 *       Module:  _Adc
 *
 *  Description:  header file for _Adc Module    
 *  
 *********************************************************************************************************************/
#ifndef _Adc_H
#define _Adc_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
 
#include "Std_Types.h"
#include "_Adc_Cfg.h"
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
* \Syntax          : void Adc_Init(void)
* \Description     : Initalizes Adc, Gpio Clock                                                                   
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Adc_Init(void);

/******************************************************************************
* \Syntax          : void SampleSequencer_Init(SampleSequencerConfigType* SSConfig)
* \Description     : Initalizes SampleSequencer Configuration.                                                                   
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : SampleSequencerConfigType* SampleSequencerConfig 
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void SampleSequencer_Init(SampleSequencerConfigType* SSConfig);

/******************************************************************************
* \Syntax          : void Channels_Init(Adc_ConfigType *ConfigType);
* \Description     : Configure Samples Controling, Gpio Clock                                                                   
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Adc_ConfigType* ConfigType                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Channels_Init(Adc_ConfigType* ConfigType);

/******************************************************************************
* \Syntax          : void Adc_StartGroupConversion(Adc_GroupType GroupType, Adc_Type AdcType);
* \Description     : Starts SampleSequencer                                                                   
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Adc_GroupType GroupType                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Adc_StartGroupConversion(Adc_GroupType GroupType, Adc_Type AdcType);

/******************************************************************************
* \Syntax          : void Adc_StopGroupConversion(Adc_GroupType GroupType, Adc_Type AdcType);
* \Description     : Stops SampleSequencer                                                                   
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Adc_GroupType GroupType                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Adc_StopGroupConversion(Adc_GroupType GroupType, Adc_Type AdcType);

/******************************************************************************
* \Syntax          : td_ReturnType Adc_ReadGroup(Adc_GroupType GroupType, Adc_Type AdcType, Adc_ValueGroupType* ValueGroupType)
* \Description     : Reads from the FIFO register of the desired sample sequencer.                                                                   
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Adc_GroupType GroupType, Adc_Type AdcType             
* \Parameters (out): Adc_ValueGroupType* ValueGroupType               
* \Return value:   : Std_ReturnType
*******************************************************************************/
Std_ReturnType Adc_ReadGroup(Adc_GroupType GroupType, Adc_Type AdcType, Adc_ValueGroupType* ValueGroupType);

#endif  /* _Adc_H */

/**********************************************************************************************************************
 *  END OF FILE: _Adc.h
 *********************************************************************************************************************/
