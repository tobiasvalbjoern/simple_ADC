/*
 * @brief ADC example This example show how to  the ADC in Polling mode
 * @author morten@hih.au.dk oct 12, 2016
 */

#include "board.h"
#include "adc.h"

/**
 * @brief	ADC0 interrupt handler sub-routine
 * @return	Nothing
 */
void ADC_IRQHandler(void)
{
	/* ADC interrupt is not used YET*/
	uint16_t dataADC;

}

/**
 * @brief	Main routine for ADC example
 * @return	Nothing
 */

delay_ms(int ms){
	int i=40000*ms;

	while(i--){};
}

int main(void)
{
	unsigned int adc_val, adc_val2;

	SystemCoreClockUpdate();
	Board_Init();

	/*init adc channel 0*/
	adc_init();

	while(1)
	{
		/* rad from the adc*/
		adc_val = adc_read(4);
		adc_val++;
		adc_val=cal_val(adc_val);
		printf("\nADC value pin 19 %u mV", adc_val);
		//NOTE! DelayMs is declared as "Static" in board.c, undo and make function global to access it here

		/* rad from the adc*/
			adc_val2 = adc_read(5);
			adc_val2++;
			adc_val2=cal_val(adc_val2);
			printf("\nADC value pin 20 %u mV", adc_val2);
			//NOTE! DelayMs is declared as "Static" in board.c, undo and make function global to access it here

		delay_ms(200);

	}


	return 0;
}

/**
 * @}
 */
