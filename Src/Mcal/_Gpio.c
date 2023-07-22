/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  _Gpio.c
 *        \brief  GPIO Driver
 *
 *      \details  The Driver Configure All GPIO Features.
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "_Gpio.h"


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

void DataReg(Dio_ChannelLevel ChannelLevel, uint8 BIT, Dio_PortType PortType){
	
	uint8 LOC;
	if 		(BIT == 0) LOC = 0b00000001;
	else if (BIT == 1) LOC = 0b00000010;
	else if (BIT == 2) LOC = 0b00000100;
	else if (BIT == 3) LOC = 0b00001000;
	else if (BIT == 4) LOC = 0b00010000;
	else if (BIT == 5) LOC = 0b00100000;
	else if (BIT == 6) LOC = 0b01000000;
	else if (BIT == 7) LOC = 0b10000000;
	if (ChannelLevel == STD_HIGH){
		GPIODATAW(PortType, LOC) = (1 << BIT);
	}
	else if(ChannelLevel == STD_LOW){
		GPIODATAW(PortType, LOC) = ~(1 << BIT);
	}
	
}
	
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
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
void Gpio_Init(void){
	if (PORT_A == STD_ON){  						
			SETBIT(RCGCGPIO,PORTA);												// Enabling Clock or Disabling Depending on The Config.
			GPIODIR(_A) = 0x00;													// Input bits as a default value.
			GPIODEN(_A) = 0xFF;													// All pins have the Digital Enabled.
		}       
	else CLRBIT(RCGCGPIO,PORTA);

	if (PORT_B == STD_ON){  						
			SETBIT(RCGCGPIO,PORTB);												// Enabling Clock or Disabling Depending on The Config.
			GPIODIR(_B) = 0x00;													// Input bits as a default value.
			GPIODEN(_B) = 0xFF;													// All pins have the Digital Enabled.
		}   
	else CLRBIT(RCGCGPIO,PORTB);

	if (PORT_C == STD_ON){  						
			SETBIT(RCGCGPIO,PORTC);												// Enabling Clock or Disabling Depending on The Config.
			GPIODIR(_C) = 0x00;													// Input bits as a default value.
			GPIODEN(_C) = 0xFF;													// All pins have the Digital Enabled.
		}   
	else CLRBIT(RCGCGPIO,PORTC);

	if (PORT_D == STD_ON){  						
			SETBIT(RCGCGPIO,PORTD);												// Enabling Clock or Disabling Depending on The Config.
			GPIODIR(_D) = 0x00;													// Input bits as a default value.
			GPIODEN(_D) = 0xFF;													// All pins have the Digital Enabled.
		}   
	else CLRBIT(RCGCGPIO,PORTD);
}

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
Dio_ChannelLevel Dio_ReadChannel(Dio_ChannelType ChannelType){
	if (ChannelType <= PA7){								// Determining the port
		if (READBIT(GPIODIR(_A), ChannelType) == STD_LOW){		// Output checking
			if(READBIT(GPIODEN(_A), ChannelType) == STD_HIGH){		// Digital Enabling checking
				return READBIT(GPIODATA(_A),ChannelType);	// Reading the bit
			}
		}
	}
	else if((ChannelType > PA7)  && (ChannelType <= PB7)){
		if (READBIT(GPIODIR(_B), (ChannelType - 8)) == STD_LOW){		
			if(READBIT(GPIODEN(_B), (ChannelType - 8)) == STD_HIGH){		
				return READBIT(GPIODATA(_B),(ChannelType - 8));
			}
		}
	}
	else if((ChannelType > PB7) && (ChannelType <= PC7)){
		if (READBIT(GPIODIR(_C), (ChannelType - 16)) == STD_LOW){		
			if(READBIT(GPIODEN(_C), (ChannelType - 16)) == STD_HIGH){		
				return READBIT(GPIODATA(_C),(ChannelType - 16));
			}
		}
	}	
	else if((ChannelType > PC7) && (ChannelType <= PD7)){
		if (READBIT(GPIODIR(_D), (ChannelType - 24)) == STD_LOW){		
			if(READBIT(GPIODEN(_D), (ChannelType - 24)) == STD_HIGH){		
				return READBIT(GPIODATA(_D),(ChannelType - 24));
			}
		}	
	}
	else return -1;
}

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
void Dio_WriteChannel(Dio_ChannelType ChannelType, Dio_ChannelLevel ChannelLevel){
	if(ChannelType <= PA7){															// Determining the Port.
		if(READBIT(GPIODEN(_A), ChannelType) == STD_HIGH){							// Digital Enabling Check
			GPIODIR(_A) |= (1 << ChannelType);										// Makes the bit output
			if (ChannelLevel == STD_HIGH) GPIODATA(_A) |= (1 << ChannelType);	    // Turns it high or low Depending on given data.
			else GPIODATA(_A) &= ~(1 << ChannelType);
		}
	}

	else if((ChannelType > PA7)  && (ChannelType <= PB7)){				
		if(READBIT(GPIODEN(_B), ChannelType - 8) == STD_HIGH){
			GPIODIR(_B) |= (1 << (ChannelType - 8));
			if (ChannelLevel == STD_HIGH) GPIODATA(_B) |= (1 << (ChannelType - 8));
			else GPIODATA(_B) &= ~(1 << (ChannelType - 8));
		}
	}

	else if((ChannelType > PB7) && (ChannelType <= PC7)){		
		if(READBIT(GPIODEN(_C), ChannelType - 16) == STD_HIGH){
			GPIODIR(_C) |= (1 << (ChannelType - 16));
			if (ChannelLevel == STD_HIGH) GPIODATA(_C) |= (1 << (ChannelType - 16));
			else GPIODATA(_C) &= ~(1 << (ChannelType - 16));
		}
	}

	else if((ChannelType > PC7) && (ChannelType <= PD7)){	
		if(READBIT(GPIODEN(_D), ChannelType - 24) == STD_HIGH){
			GPIODIR(_D) |= (1 << (ChannelType - 24));
			if (ChannelLevel == STD_HIGH) GPIODATA(_D) |= (1 << (ChannelType - 24));
			else GPIODATA(_D) &= ~(1 << (ChannelType - 24));
		}
	}
}

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
Dio_PortLevel Dio_ReadPort(Dio_PortType PortType){
	if (PortType == _A){
		if((GPIODEN(_A) == 0xFF) && (GPIODIR(_A) == 0xFF)) return GPIODATA(_A);
	}
	else if (PortType == _B){
		if((GPIODEN(_B) == 0xFF) && (GPIODIR(_B) == 0xFF)) return GPIODATA(_B);
	}
	else if (PortType == _C){
		if((GPIODEN(_C) == 0xFF) && (GPIODIR(_C) == 0xFF)) return GPIODATA(_C);
	}
	else if (PortType == _B){
		if((GPIODEN(_D) == 0xFF) && (GPIODIR(_D) == 0xFF)) return GPIODATA(_D);
	}
	else return 1;
}

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
void Dio_WritePort(Dio_PortLevel PortLevel, Dio_PortType PortType){
	if (PortType == _A){
		if (GPIODEN(_A) == 0xFF){
			GPIODIR(_A) = 0xFF;
		    GPIODATA(_A) = PortLevel;
		}
	}
	else if (PortType == _B){
		if (GPIODEN(_B) == 0xFF){
			GPIODIR(_B) = 0xFF;
		    GPIODATA(_B) = PortLevel;
		}
	}
	else if (PortType == _C){
		if (GPIODEN(_C) == 0xFF){
			GPIODIR(_C) = 0xFF;
		    GPIODATA(_C) = PortLevel;
		}
	}
	else if (PortType == _D){
		if (GPIODEN(_D) == 0xFF){
			GPIODIR(_D) = 0xFF;
		    GPIODATA(_D) = PortLevel;
		}
	}
}

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
void Port_Init(const ConfigType Config){
	GPIODEN(Config.PinType) = 0xFF;															// Digital enabling for the whole port.
	GPIODIR(Config.PinType) |= (Config.DirectionType << Config.PinNum);						// Making the pin as an output.
	if (Config.PinMode == STD_OFF) GPIOAFSEL(Config.PinType) &= ~(1 << Config.PinNum);		// Check if It's DIO or Alternate Fn.
	else 						   GPIOAFSEL(Config.PinType) |=  (1 << Config.PinNum);		// Check if It's DIO or Alternate Fn.
	GPIOPCTL(Config.PinType) |= (Config.PinMode << (Config.PinNum * 4));					// Setting the suitable Pin function.
	GPIOPUR(Config.PinType) |= (1 << Config.PinNum);

	switch (Config.OutputCurrentType){														// Setting the OutputCurrent.
		case OutputCurrentType_8:
			GPIODR8R(Config.PinType) |= (1 << Config.PinNum);
			break;
		case OutputCurrentType_4:
			GPIODR4R(Config.PinType) |= (1 << Config.PinNum);
			break;
		case OutputCurrentType_2:
			GPIODR2R(Config.PinType) |= (1 << Config.PinNum);
			break;
		default:
			break;	
	}
}

/**********************************************************************************************************************
 *  END OF FILE: _Gpio.c
 *********************************************************************************************************************/
