/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  _Adc.c
 *        \brief  _Adc Controller Driver
 *
 *      \details  
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "_Adc.h"

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
* \Syntax          : void Adc_Init(void)
* \Description     : Initalizes Adc, Gpio Clock                                                                   
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Adc_Init(void){
    /*************** GPIO CLOCK ***************/
    RCGCGPIO = 0x1F;                                        // Enabling all Ports.
    /*************** ADC 0 ***************/
    #if ADC0 == STD_ON
    RCGCADC |= (1 << R0);                                   // Enabling Clock For ADC 0
    ADCACTSS(0) = 0x00;                                     // Disabling All Sample Sequencers
    #endif
    /*************** ADC 1 ***************/
    #if ADC1 == STD_ON
    RCGCADC |= (1 << R1);                                   // Enabling Clock For ADC 1
    ADCACTSS(1) = 0x00;                                     // Disabling All Sample Sequencers
    #endif
}

/******************************************************************************
* \Syntax          : void SampleSequencer_Init(SampleSequencerConfigType* SSConfig)
* \Description     : Initalizes SampleSequencer Configuration.                                                                   
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : SampleSequencerConfigType SampleSequencerConfig 
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void SampleSequencer_Init(SampleSequencerConfigType* SSConfig){
    for (uint8 i = 0; i < SS_NUM; i++){
        ADCSSPRI(SSConfig[i].AdcType) |= (SSConfig[i].GroupPriorityType << SSConfig[i].GroupPriorityType);  // Setting Priority for the sample sequencer.
        ADCEMUX(SSConfig[i].AdcType) |= (SSConfig[i].GroupTriggerSourceType << SSConfig[i].GroupType);      // Setting The trigger source type for the sample sequencer.
        switch (SSConfig[i].GroupType){
            case SS0:
                ADCIM(SSConfig[i].AdcType) |= (SSConfig[i].InterruptType << 0);
                break;
            case SS1:
                ADCIM(SSConfig[i].AdcType) |= (SSConfig[i].InterruptType << 1);
                break;
            case SS2:
                ADCIM(SSConfig[i].AdcType) |= (SSConfig[i].InterruptType << 2);
                break;
            case SS3:
                ADCIM(SSConfig[i].AdcType) |= (SSConfig[i].InterruptType << 3);
                break;
            default:
                break;
        }
    }
}

/******************************************************************************
* \Syntax          : void Channels_Init(Adc_ConfigType *ConfigType);
* \Description     : Configure Samples Controling, Gpio Clock                                                                   
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Adc_ConfigType* ConfigType                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Channels_Init(Adc_ConfigType* ConfigType){
    for (uint8 i = 0; i < SAMPLES_NUM; i++){
        /************* GPIO CONFIGS ****************/
        switch (ConfigType[i].ChannelType){
            case ChannelType_AIN0:
                GPIOAFSEL(P_E) |= (1 << 3);
                GPIODEN(P_E) |= (1 << 3);
                GPIOAMSEL(P_E) |= (1 << 3);
                break;
            case ChannelType_AIN1:
                GPIOAFSEL(P_E) |= (1 << 2);
                GPIODEN(P_E) |= (1 << 2);
                GPIOAMSEL(P_E) |= (1 << 2);
                break;
            case ChannelType_AIN2:
                GPIOAFSEL(P_E) |= (1 << 1);
                GPIODEN(P_E) |= (1 << 1);
                GPIOAMSEL(P_E) |= (1 << 1);
                break;
            case ChannelType_AIN3:
                GPIOAFSEL(P_E) |= (1 << 0);
                GPIODEN(P_E) |= (1 << 0);
                GPIOAMSEL(P_E) |= (1 << 0);
                break;
            case ChannelType_AIN4:
                GPIOAFSEL(P_D) |= (1 << 3);
                GPIODEN(P_D) |= (1 << 3);
                GPIOAMSEL(P_D) |= (1 << 3);
                break;
            case ChannelType_AIN5:
                GPIOAFSEL(P_D) |= (1 << 2);
                GPIODEN(P_D) |= (1 << 2);
                GPIOAMSEL(P_D) |= (1 << 2);
                break;
            case ChannelType_AIN6:
                GPIOAFSEL(P_D) |= (1 << 1);
                GPIODEN(P_D) |= (1 << 1);
                GPIOAMSEL(P_D) |= (1 << 1);
                break;
            case ChannelType_AIN7:
                GPIOAFSEL(P_D) |= (1 << 0);
                GPIODEN(P_D) |= (1 << 0);
                GPIOAMSEL(P_D) |= (1 << 0);
                break;
            case ChannelType_AIN8:
                GPIOAFSEL(P_E) |= (1 << 5);
                GPIODEN(P_E) |= (1 << 5);
                GPIOAMSEL(P_E) |= (1 << 5);
                break;
            case ChannelType_AIN9:
                GPIOAFSEL(P_E) |= (1 << 4);
                GPIODEN(P_E) |= (1 << 4);
                GPIOAMSEL(P_E) |= (1 << 4);
                break;
            case ChannelType_AIN10:
                GPIOAFSEL(P_B) |= (1 << 4);
                GPIODEN(P_B) |= (1 << 4);
                GPIOAMSEL(P_B) |= (1 << 4);
                break;
            case ChannelType_AIN11:
                GPIOAFSEL(P_B) |= (1 << 5);
                GPIODEN(P_B) |= (1 << 5);
                GPIOAMSEL(P_B) |= (1 << 5);
                break;
            default:
            break;
        }
        /*********** ADCSSMUX CONFIGS ***************/
        ADCSSMUX(ConfigType[i].AdcType, ConfigType[i].GroupType) |= (ConfigType[i].ChannelType << ConfigType[i].SampleTurn);
        /*********** ADCSSCTL CONFIGS ***************/
        ADCSSCTL(ConfigType[i].AdcType, ConfigType[i].GroupType) |= (ConfigType[i].SampleType << ConfigType[i].SampleTurn + 0)
                                                                  | (ConfigType[i].SampleFinal << ConfigType[i].SampleTurn + 1)
                                                                  | (ConfigType[i].SampleInterrupt << ConfigType[i].SampleTurn + 2)
                                                                  | (ConfigType[i].SampleReadSource << ConfigType[i].SampleTurn + 3);         
    }
}

/******************************************************************************
* \Syntax          : void Adc_StartGroupConversion(Adc_GroupType GroupType, Adc_Type AdcType);
* \Description     : Starts SampleSequencer                                                                   
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Adc_GroupType GroupType                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Adc_StartGroupConversion(Adc_GroupType GroupType, Adc_Type AdcType){
    ADCACTSS(AdcType) |= (1 << GroupType);
}

/******************************************************************************
* \Syntax          : void Adc_StopGroupConversion(Adc_GroupType GroupType);
* \Description     : Stops SampleSequencer                                                                   
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Adc_GroupType GroupType                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Adc_StopGroupConversion(Adc_GroupType GroupType, Adc_Type AdcType){
    ADCACTSS(AdcType) &= ~(1 << GroupType); 
}

/******************************************************************************
* \Syntax          : td_ReturnType Adc_ReadGroup(Adc_GroupType GroupType, Adc_Type AdcType, Adc_ValueGroupType* ValueGroupType)
* \Description     : Reads from the FIFO register of the desired sample sequencer.                                                                   
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Adc_GroupType GroupType, Adc_Type AdcType             
* \Parameters (out): Adc_ValueGroupType* ValueGroupType               
* \Return value:   : Std_ReturnType
*******************************************************************************/
Std_ReturnType Adc_ReadGroup(Adc_GroupType GroupType, Adc_Type AdcType, Adc_ValueGroupType* ValueGroupType){
    uint8 Used_SS;
    switch (GroupType){                                             // For determining the samples numbers to be read
        case GroupType_SS0N:
            Used_SS = SS0_SAMPLES_USED;
            break;
        case GroupType_SS1N:
            Used_SS = SS1_SAMPLES_USED;
            break;
        case GroupType_SS2N:
            Used_SS = SS2_SAMPLES_USED;
            break;
        case GroupType_SS3N:
            Used_SS = SS3_SAMPLES_USED;
            break;
        default:
            return 2;
            break;
    }
    for (uint8 i = 0; i < Used_SS; i++){                            // Filling the Buffer with ADCSSFIFO
        ValueGroupType[i] = ADCSSFIFO(AdcType, GroupType);
    }
    for (uint8 i = 0; i < Used_SS; i++){                            // Checking whether the Buffer is filled Correctly or not.
        if (ValueGroupType[i] == 0) return 1;
    }
    return 0;
}



/**********************************************************************************************************************
 *  END OF FILE: _Adc.c
 *********************************************************************************************************************/
