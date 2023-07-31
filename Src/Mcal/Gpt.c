/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Gpt.c
 *        \brief  General Purpose Timer Controller Driver
 *
 *      \details  This driver Controls The HW of the General Purpose Timer and Its Different Functions.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Gpt.h"


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
* \Syntax          : void Gpt_Init(void);                                    
* \Description     : Initialize all predefined Timers.                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_Init(void){

	GPTMCTL(0) &= ~(1 << TAEN);  GPTMCTL_WIDE(0) &= ~(1 << TAEN);                   // Ensure the timer is disabled
    GPTMCFG(0) = 0x00;  GPTMCFG_WIDE(0) = 0x00;                                     // Reset all configurations

    
    #if GPT_PREDEF_TIMER_100US_32BIT == 1

    GPTMCFG_WIDE(0) = 0x4;                                                          // Timer A only.
    GPTMTAMR_WIDE(0) |= (0x2 << TAMR);                                              // Periodic timer >> continous mode
    GPTMTAMR_WIDE(0) |= (1 << TACDIR);                                              // The timer Counts Up
    GPTMTAMR_WIDE(0) &= ~(1 << TAWOT);                                              // Timer A begins counting as soon as it's enabled

    GPTMTAILR_WIDE(0) = 0x00;                                                       // Loading initial value with 0

    GPTMTAPR_WIDE(0) = 0x640;                                                       // 10Khz >> 100us for tick time.

    GPTMCTL_WIDE(0) |= (1 << TAEN);                                                 // Timer A starts to count.

    #endif



    #if GPT_PREDEF_TIMER_1US_32BIT == 1

    GPTMCFG_WIDE(1) = 0x4;                                                          // Timer A only.
    GPTMTAMR_WIDE(1) |= (0x2 << TAMR);                                              // Periodic timer >> continous mode
    GPTMTAMR_WIDE(1) |= (1 << TACDIR);                                              // The timer Counts Up
    GPTMTAMR_WIDE(1) &= ~(1 << TAWOT);                                              // Timer A begins counting as soon as it's enabled

    GPTMTAILR_WIDE(1) = 0x00;                                                       // Loading initial value with 0

    GPTMTAPR_WIDE(1) = 0x10;                                                        // 1Mhz >> 1us for tick time.

    GPTMCTL_WIDE(1) |= (1 << TAEN);                                                 // Timer A starts to count.
    
    #endif



    #if GPT_PREDEF_TIMER_1US_24BIT == 1

    GPTMCFG_WIDE(2) = 0x4;                                                          // Timer A only.
    GPTMTAMR_WIDE(2) |= (0x2 << TAMR);                                              // Periodic timer >> continous mode
    GPTMTAMR_WIDE(2) |= (1 << TACDIR);                                              // The timer Counts Up
    GPTMTAMR_WIDE(2) &= ~(1 << TAWOT);                                              // Timer A begins counting as soon as it's enabled

    GPTMTAPR_WIDE(2) = 0x10;                                                        // 1Mhz >> 1us for tick time.

    GPTMCTL_WIDE(2) |= (1 << TAEN);                                                 // Timer A starts to count.

    #endif



    #if GPT_PREDEF_TIMER_1US_16BIT == 1

    GPTMCFG(0) = 0x4;                                                               // Timer A only.
    GPTMTAMR(0) |= (0x2 << TAMR);                                                   // Periodic timer >> continous mode
    GPTMTAMR(0) |= (1 << TACDIR);                                                   // The timer Counts Up
    GPTMTAMR(0) &= ~(1 << TAWOT);                                                   // Timer A begins counting as soon as it's enabled
    
    GPTMTAILR(0) = 0x00;                                                            // Loading initial value with 0

    GPTMTAPR(0) = 0x10;                                                             // 1Mhz >> 1us for tick time.

    GPTMCTL(0) |= (1 << TAEN);                                                      // Timer A starts to count.

    #endif
}

/******************************************************************************
* \Syntax          : void Gpt_StartTimer(Gpt_ConfigType ConfigType);                                    
* \Description     : Start a certain timer depending on the configtype.
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Gpt_ConfigType ConfigType.                    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_StartTimer(Gpt_ConfigType ConfigType){
    if (ConfigType.ChannelId <= 5){
        GPTMCTL(ConfigType.ChannelId) &= ~(1 << TAEN);                      // Disable the Timer.
        GPTMCFG(ConfigType.ChannelId) = 0x00;                               // Clearing Config Register.
        GPTMCFG(ConfigType.ChannelId) = 0x04;                               // Using Timer A only.
        if (ConfigType.ChannelMode == ChannelMode_CONTINUOUS){  
            GPTMTAMR(ConfigType.ChannelId) |= (0x2 << TAMR);                // Continuous mode.
        }
        //else {}  >> One_Shot_Mode Not supported.
        GPTMTAMR(ConfigType.ChannelId) |= (1 << TACDIR);                    // Timer counts up (By default) > no config for this option.
        GPTMTAMR(ConfigType.ChannelId) &= (1 << TAWOT);                     // Timer Starts Counting once it's enabled.

        switch (ConfigType.ChannelTickFrequency){                           // Timer Frequency >> Prescaler Control.
            case ChannelTickFrequency_16Mhz:
                break;
            case ChannelTickFrequency_8Mhz:
                GPTMTAPR(ConfigType.ChannelId) = 0x02;
                break;
            case ChannelTickFrequency_4Mhz:
                GPTMTAPR(ConfigType.ChannelId) = 0x04;
                break;
            case ChannelTickFrequency_2Mhz:
                GPTMTAPR(ConfigType.ChannelId) = 0x08;
                break;
            case ChannelTickFrequency_1Mhz:
                GPTMTAPR(ConfigType.ChannelId) = 0x16;
                break;
            default:
                break;
        }
        GPTMCTL(ConfigType.ChannelId) |= (1 << TAEN);                       // Timer Starts Counting.   
    }
    
    else{
        GPTMCTL_WIDE(ConfigType.ChannelId - 6) &= ~(1 << TAEN);                      // Disable the Timer.
        GPTMCFG_WIDE(ConfigType.ChannelId - 6) = 0x00;                               // Clearing Config Register.
        GPTMCFG_WIDE(ConfigType.ChannelId - 6) = 0x04;                               // Using Timer A only.
        if (ConfigType.ChannelMode == ChannelMode_CONTINUOUS){  
            GPTMTAMR_WIDE(ConfigType.ChannelId - 6) |= (0x2 << TAMR);                // Continuous mode.
        }
        //else {}  >> One_Shot_Mode Not supported.
        GPTMTAMR_WIDE(ConfigType.ChannelId - 6) |= (1 << TACDIR);                    // Timer counts up (By default) > no config for this option.
        GPTMTAMR_WIDE(ConfigType.ChannelId - 6) &= (1 << TAWOT);                     // Timer Starts Counting once it's enabled.
    
        switch (ConfigType.ChannelTickFrequency){                                    // Timer Frequency >> Prescaler Control.
            case ChannelTickFrequency_16Mhz:
                break;
            case ChannelTickFrequency_8Mhz:
                GPTMTAPR_WIDE(ConfigType.ChannelId - 6) = 0x02;
                break;
            case ChannelTickFrequency_4Mhz:
                GPTMTAPR_WIDE(ConfigType.ChannelId - 6) = 0x04;
                break;
            case ChannelTickFrequency_2Mhz:
                GPTMTAPR_WIDE(ConfigType.ChannelId - 6) = 0x08;
                break;
            case ChannelTickFrequency_1Mhz:
                GPTMTAPR_WIDE(ConfigType.ChannelId - 6) = 0x16;
                break;
            default:
                break;
        }
        GPTMCTL_WIDE(ConfigType.ChannelId - 6) |= (1 << TAEN);                       // Timer Starts Counting. 
    }
}

/******************************************************************************
* \Syntax          : void Gpt_StopTimer(Gpt_ChannelId ChannelId);                                    
* \Description     : Stops a certain timer depending on ChannelId                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                    
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Gpt_StopTimer(Gpt_ChannelId ChannelId){
    if (ChannelId <= 5){
        GPTMCTL(ChannelId) &= ~(1 << TAEN);
    }
    else{
        GPTMCTL_WIDE(ChannelId - 6) &= ~(1 << TAEN);
    }
}

/******************************************************************************
* \Syntax          : Gpt_TimerValue Gpt_GetTimeElapsed(Gpt_ConfigType ConfigType);                                    
* \Description     : Calculates the time elapsed.                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Gpt_ConfigType ConfigType                    
* \Parameters (out): Gpt_TimerValue                                                      
* \Return value:   : Gpt_TimerValue
*******************************************************************************/
Gpt_TimerValue Gpt_GetTimeElapsed(Gpt_ConfigType ConfigType){
    uint16 Val_16Bit;
    uint32 Val_32Bit;
    uint16 Mask_8_bit = 0x00FF;
    uint32 Mask_24_bit = 0x00FFFFFF;
    if (ConfigType.ChannelId <= 5){
        switch (ConfigType.ChannelTickFrequency){
            case ChannelTickFrequency_16Mhz:
                Val_16Bit = GPTMTAV(ConfigType.ChannelId);
                break;
            case ChannelTickFrequency_8Mhz:
                Val_16Bit = (GPTMTAPR(ConfigType.ChannelId) & 0x1) << 15;
                Val_16Bit |= GPTMTAV(ConfigType.ChannelId) >> 1;
                break;
            case ChannelTickFrequency_4Mhz:
                Val_16Bit = (GPTMTAPR(ConfigType.ChannelId) & 0x3) << 14;
                Val_16Bit |= GPTMTAV(ConfigType.ChannelId) >> 2;
                break;
            case ChannelTickFrequency_2Mhz:
                Val_16Bit = (GPTMTAPR(ConfigType.ChannelId) & 0x7) << 13;
                Val_16Bit |= GPTMTAV(ConfigType.ChannelId) >> 3;
                break;
            case ChannelTickFrequency_1Mhz:
                Val_16Bit = (GPTMTAPR(ConfigType.ChannelId) & 0xF) << 13;
                Val_16Bit |= GPTMTAV(ConfigType.ChannelId) >> 3; 
                break;
            default:
                break;
        }
        if (ConfigType.ChannelTickValueMax == ChannelTickValueMax_16_BIT) return Val_16Bit;
        else if (ConfigType.ChannelTickValueMax == ChannelTickValueMax_8_BIT) return Val_16Bit & Mask_8_bit;
    }
    
    else{
        switch (ConfigType.ChannelTickFrequency){
            case ChannelTickFrequency_16Mhz:
                Val_32Bit = GPTMTAV(ConfigType.ChannelId - 6);
                break;
            case ChannelTickFrequency_8Mhz:
                Val_32Bit = (GPTMTAPR(ConfigType.ChannelId - 6) & 0x1) << 31;
                Val_32Bit |= GPTMTAV(ConfigType.ChannelId - 6) >> 1;
                break;
            case ChannelTickFrequency_4Mhz:
                Val_32Bit = (GPTMTAPR(ConfigType.ChannelId - 6) & 0x3) << 31;
                Val_32Bit |= GPTMTAV(ConfigType.ChannelId - 6) >> 2;
                break;
            case ChannelTickFrequency_2Mhz:
                Val_32Bit = (GPTMTAPR(ConfigType.ChannelId - 6) & 0x7) << 31;
                Val_32Bit |= GPTMTAV(ConfigType.ChannelId - 6) >> 3;
                break;
            case ChannelTickFrequency_1Mhz:
                Val_32Bit = (GPTMTAPR(ConfigType.ChannelId - 6) & 0xF) << 31;
                Val_32Bit |= GPTMTAV(ConfigType.ChannelId - 6) >> 3; 
                break;
            default:
                break;
        }
        if (ConfigType.ChannelTickValueMax == ChannelTickValueMax_32_BIT) return Val_32Bit;  
        else if (ConfigType.ChannelTickValueMax == ChannelTickValueMax_24_BIT) return Val_32Bit & Mask_24_bit;
    }

    return 1;
}


/**********************************************************************************************************************
 *  END OF FILE: Gpt.c
 *********************************************************************************************************************/
