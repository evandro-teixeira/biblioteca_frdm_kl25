/*********************************************************************
 * main implementation: use this 'C' sample to create your own application
 *
 *********************************************************************/
#include "derivative.h" /* include peripheral declarations */
#include "types.h"
#include "gpio.h"

int main(void)
{
	uint32_t i = 0;
	gpio_direction(PTB,18,OUTPUT);
	gpio_direction(PTB,19,OUTPUT);
	
	gpio_direction(PTC,7,INPUT);
	gpio_direction(PTC,0,INPUT);
	
	//
	
	gpio_direction(PTA,2,INPUT);
	//GPIOA_PDDR &=~ 0x4u;
	
	gpio_set(PTB,18,HIGH);
	gpio_set(PTB,19,LOW);
	
	for(;;) 
	{	   
		i++;
		if(i>1e5)
		{
			i = 0;
			gpio_toggle(PTB,19);
			gpio_toggle(PTB,18);
		}
		/*
		if(GPIOC_PDIR & (1<<7))
		{
			gpio_toggle(PTB,18);//,HIGH);
		}
		else
		{
			gpio_toggle(PTB,19);//,LOW);
		}
		*/	
		
		
		//if(gpio_read(PTC,7) == FALSE )
		/*if(GPIOC_PDIR & 0x128)
		{
			gpio_set(PTB,18,LOW);
		}*/
		//else
		/*
		if(gpio_read(PTA,2))
		//if(GPIOA_PDIR & 0x4u)
		{
			gpio_set(PTB,19,LOW);
		}
		else
		{
			gpio_set(PTB,19,HIGH);
		}
		*/
	}

}
