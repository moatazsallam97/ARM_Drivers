#include "_Gpio.h"

extern const ConfigType Port_Config1;

int main(void){
	Gpio_Init();
	Port_Init(Port_Config1);
	while(1){
		
	}
}
