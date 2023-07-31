/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Gpt_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef Gpt_Types_H
#define Gpt_Types_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
 
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define ChannelTickValueMax_8_BIT  8
#define ChannelTickValueMax_16_BIT 16
#define ChannelTickValueMax_24_BIT 24
#define ChannelTickValueMax_32_BIT 32

#define ChannelTickFrequency_16Mhz 16
#define ChannelTickFrequency_8Mhz  8
#define ChannelTickFrequency_4Mhz  4
#define ChannelTickFrequency_2Mhz  2
#define ChannelTickFrequency_1Mhz  1

#define ChannelMode_CONTINUOUS      1
#define ChannelMode_ONESHOT        0

#define Gpt_PredefTimer_32BIT_100US 1
#define Gpt_PredefTimer_32BIT_1US   2
#define Gpt_PredefTimer_24BIT_1US   3
#define Gpt_PredefTimer_16BIT_1US   4


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef uint8 Gpt_ChannelId;
typedef uint8 Gpt_ChannelTickFrequency;
typedef uint8 Gpt_ChannelTickValueMax;
typedef uint8 Gpt_ChannelMode;
typedef uint8 Gpt_ValueType;
typedef uint32 Gpt_TimerValue;
typedef uint8 Gpt_PredefTimerType;

typedef enum{
    TIMER0,
    TIMER1,
    TIMER2,
    TIMER3,
    TIMER4,
    TIMER5,
    WIDE_TIMER0,
    WIDE_TIMER1,
    WIDE_TIMER2,
    WIDE_TIMER3,
    WIDE_TIMER4,
    WIDE_TIMER5
}ChannelID;

typedef struct{
    Gpt_ChannelId ChannelId;
    Gpt_ChannelTickFrequency ChannelTickFrequency;
    Gpt_ChannelTickValueMax ChannelTickValueMax;
    Gpt_ChannelMode ChannelMode;
    //void (*GptNotifcations)(void);     // pointer to callback function
}Gpt_ConfigType;

#endif  /* Gpt_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Gpt_Types.h
 *********************************************************************************************************************/
