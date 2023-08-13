/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Gpio_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef GPIO_TYPES_H
#define GPIO_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define PinType_A 0u
#define PinType_B 1u
#define PinType_C 2u
#define PinType_D 3u
#define PinType_E 4u
#define PinType_F 5u

#define PinNum_0 0u
#define PinNum_1 1u
#define PinNum_2 2u
#define PinNum_3 3u
#define PinNum_4 4u
#define PinNum_5 5u
#define PinNum_6 6u
#define PinNum_7 7u

#define DirectionType_Output 1u 
#define DirectionType_Input  0u

// Will be done for PORT A & PORT B ONLY

#define PinMode_Dio 0u

                                                    /* PORT A */
                                                    
/* Port A Pin 0 */
#define PinMode_PA0_U0Rx    1u
#define PinMode_PA0_CAN1Rx  8u
/* Port A Pin 1 */
#define PinMode_PA1_U0Tx    1u
#define PinMode_PA1_CAN1Tx  8u
/* Port A Pin 2 */
#define PinMode_PA2_SSI0Clk 2u
/* Port A Pin 3 */
#define PinMode_PA3_SSI0Fss 2u
/* Port A Pin 4 */
#define PinMode_PA4_SSI0Rx  2u
/* Port A Pin 5 */
#define PinMode_PA5_SSI0Tx  2u
/* Port A Pin 6 */
#define PinMode_PA6_I2C1SCL 3u
#define PinMode_PA6_M1PWM2  5u
/* Port A Pin 7 */
#define PinMode_PA7_I2C1SDA 3u
#define PinMode_PA7_M1PWM3  5u

                                                    /* PORT B */

/* Port B Pin 0 */
#define PinMode_PB0_U1RX    1u
#define PinMode_PB0_T2CCP0  7u
/* Port B Pin 1 */
#define PinMode_PB1_U1Tx    1u
#define PinMode_PB1_T2CCP1  7u
/* Port B Pin 2 */
#define PinMode_PB2_I2C0SCL 3u
#define PinMode_PB2_T3CCP0  7u
/* Port B Pin 3 */
#define PinMode_PB3_I2C0SDA 3u
#define PinMode_PB3_T3CCP1  7u
/* Port B Pin 4 */ 
#define PinMode_PB4_SSI2Clk 2u
#define PinMode_PB4_M0PWM2  4u
#define PinMode_PB4_T1CCP0  7u
#define PinMode_PB4_CAN0Rx  8u
/* Port B Pin 5 */
#define PinMode_PB5_SSI2Fss 2u
#define PinMode_PB5_M0PWM3  4u
#define PinMode_PB5_T1CCP1  7u
#define PinMode_PB5_CAN0Tx  8u
/* Port B Pin 6 */
#define PinMode_PB6_SSI2Rx  2u
#define PinMode_PB6_M0PWM0  4u
#define PinMode_PB6_T0CCP0  7u
/* Port B Pin 7 */
#define PinMode_PB7_SSI2Tx  2u
#define PinMode_PB7_M0PWM1  4u
#define PinMode_PB7_T0CCP1  7u

#define InternalAttach_Pullup    0u
#define InternalAttach_PullDown  1u
#define InternalAttach_OpenDrain 2u

#define OutputCurrentType_2 2u
#define OutputCurrentType_4 4u
#define OutputCurrentType_8 8u



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
        /* DIO TYPES */

typedef uint8 Dio_PortLevel;    
typedef uint8 Dio_PortType;   // A B C or D
typedef uint8 Dio_ChannelLevel;  // 1 or 0 >> High or low
typedef uint8 Dio_ChannelType;  // PA1 PA2 ....

typedef enum{
    PA0, PA1, PA2, PA3, PA4, PA5, PA6, PA7           // 7
}PA;

typedef enum{
    PB0 = 8, PB1, PB2, PB3, PB4, PB5, PB6, PB7       // 15
}PB;

typedef enum{
    PC0 = 16, PC1, PC2, PC3, PC4, PC5, PC6, PC7          // 23
}PC;

typedef enum{
    PD0 = 24, PD1, PD2, PD3, PD4, PD5, PD6, PD7         //  31
}PD;

        /* PORT TYPES */

typedef uint8 Port_PinType;                                 // A B C D E F
typedef uint8 Port_PinNum;                                  // 0 >> 7
typedef uint8 Port_DirectionType;                           // Output or Input
typedef uint8 Port_PinMode;                                 // Dio or something else
typedef uint8 Port_InternalAttach;                          // PullUp PullDown OpenDrain
typedef uint8 Port_OutputCurrentType;                       // 2 , 4 or 8 mA

typedef struct{
    Port_PinType PinType;          
    Port_PinNum PinNum;           
    Port_DirectionType DirectionType;    
    Port_PinMode PinMode;          
    Port_InternalAttach InternalAttach;  
    Port_OutputCurrentType OutputCurrentType;
}ConfigType;
 
#endif  /* GPIO_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Gpio_Types.h
 *********************************************************************************************************************/
