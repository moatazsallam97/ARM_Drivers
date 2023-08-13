/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  _Adc_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef _Adc_TYPES_H
#define _Adc_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
 
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define ADC0                         0 
#define ADC1                         1 
#define StatusType_Busy              0
#define StatusType_Idle              1
#define StreamBufferMode_Linear      0
#define StreamBufferMode_Circular    1
#define SampleType_NotDifferntial    0
#define SampleType_Differntial       1
#define SampleFinal_On               1
#define SampleFinal_Off              0
#define SampleInterrup_Enalbed       1
#define SampleInterrup_Disabled      0
#define SampleReadSource_ADCMUX      1
#define SampleReadSource_TempSensor  0
#define InterruptType_Enabled        1
#define InterruptType_Disabled       0
#define SampleTurn_1st               0
#define SampleTurn_2nd               4
#define SampleTurn_3rd               8
#define SampleTurn_4th               12
#define SampleTurn_5th               16
#define SampleTurn_6th               20
#define SampleTurn_7th               24
#define SampleTurn_8th               28

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

typedef uint8  Adc_Type;                                // Adc0 or Adc1 
typedef uint8  Adc_StatusType;                          // Idle or Busy
typedef uint8  Adc_ChannelType;                         // ADCAIN0 ADCAIN1 ,,,
typedef uint8  Adc_GroupType;                           // SS0 SS1 ,,,               
typedef uint16 Adc_ValueGroupType;                      // 12bit by default.                    
typedef uint8  Adc_GroupPriorityType;                   // 0 >> 3                                                                                                                                  
typedef uint8  Adc_GroupTriggerSourceType;              // if oneshot >> Default, Analog_Comparator0 ,,,  can be continous too, without trigger source.                          
typedef uint8  Adc_StreamBufferMode;                    // Linear or Circular.                      
typedef uint8  Adc_StreamingNumSaples;                  // Depending on SS , if SS0 >> 1 > 8. 
typedef uint8  Adc_InterruptType;                       // 1 on , 0 off              
typedef uint8  Adc_SampleTurn;                          // The Placement of the sample among the samples in a specific sample sequencer.
typedef uint8  Adc_SampleType;                          // Differentially sampled or not >> 1 or 0
typedef uint8  Adc_SampleFinal;                         // final sample or not.
typedef uint8  Adc_SampleInterrupt;                     // Enabled or Disabled.
typedef uint8  Adc_SampleReadSource;                    // ADCSSMUXn or Temperature sensor.
typedef void (*Adc_Callback)(void);                     // Callback Function pointer.      NOT SUPPORTED YET.

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum{
    ChannelType_AIN0,
    ChannelType_AIN1,
    ChannelType_AIN2,
    ChannelType_AIN3,
    ChannelType_AIN4,
    ChannelType_AIN5,
    ChannelType_AIN6,
    ChannelType_AIN7,
    ChannelType_AIN8,
    ChannelType_AIN9,
    ChannelType_AIN10,
    ChannelType_AIN11,
    ChannelType_AIN12,
    ChannelType_AIN13,
    ChannelType_AIN14,
    ChannelType_AIN15 
}ADC_AIN;

typedef enum{
    GroupType_SS0,
    GroupType_SS1 = 4,
    GroupType_SS2 = 8,
    GroupType_SS3 = 12
}SampleSequencerBits;
typedef enum{
    GroupType_SS0N,
    GroupType_SS1N,
    GroupType_SS2N,
    GroupType_SS3N
}SampleSequencerNumber;

typedef enum{
    GroupTriggerSourceType_OneShot,                // By setting SSn Bit in ADCPSSI register.
    GroupTriggerSourceType_Analog_Comparator0,
    GroupTriggerSourceType_Analog_Comparator1,
    GroupTriggerSourceType_Reveresed_0,
    GroupTriggerSourceType_External_GPIO,
    GroupTriggerSourceType_Timer,
    GroupTriggerSourceType_PWM_GENERATOR_0,         // not supported
    GroupTriggerSourceType_PWM_GENERATOR_1,         // not supported
    GroupTriggerSourceType_PWM_GENERATOR_2,         // not supported
    GroupTriggerSourceType_PWM_GENERATOR_3,         // not supported
    NotUsed_1,
    NotUsed_2,
    NotUsed_3,
    NotUsed_4,
    NotUsed_5,
    GroupTriggerSourceType_Continuous
}TriggerSelect;

typedef struct{
    Adc_Type AdcType;
    Adc_GroupType GroupType;
    Adc_GroupPriorityType GroupPriorityType;
    Adc_GroupTriggerSourceType GroupTriggerSourceType;
    Adc_InterruptType InterruptType;
}SampleSequencerConfigType;

typedef struct{
    Adc_Type AdcType;
    Adc_ChannelType ChannelType;
    Adc_GroupType GroupType;
    Adc_SampleType SampleType;
    Adc_SampleFinal SampleFinal;
    Adc_SampleInterrupt SampleInterrupt;
    Adc_SampleReadSource SampleReadSource;
    Adc_SampleTurn SampleTurn;
}Adc_ConfigType;


#endif  /* _Adc_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: _Adc_Types.h
 *********************************************************************************************************************/
