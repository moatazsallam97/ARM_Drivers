#include "_Adc.h"

extern const SampleSequencerConfigType SSConfig[4];
extern const Adc_ConfigType AdcConfig[1];
Adc_ValueGroupType ValueGroupBuffer[8];

int main(void){
	Adc_Init();
	SampleSequencer_Init(SSConfig);
	Channels_Init(AdcConfig);
	Adc_ReadGroup(GroupType_SS0N, ADC0, ValueGroupBuffer);
	while(1){
		
	}
}
