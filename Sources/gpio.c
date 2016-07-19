/*********************************************************************
 * gpio.c
 *
 *  Created on: Jun 26, 2016
 *      Author: Evandro
 *********************************************************************/
#include "gpio.h"
/********************************************************************/
// função que define a direção do pino
/********************************************************************/
void gpio_direction(uint8_t port, uint8_t pin, uint8_t mode)
{
	switch(port)
	{	    
		case PTA:
			SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;
			PORT_PCR_REG(PORTA_BASE_PTR,pin) = PORT_PCR_MUX(1);
			if(mode == OUTPUT)
			{
				GPIOA_PDDR |= (1 << pin);
			}
			else if(mode == INPUT)
			{
				GPIOA_PDDR &=~ (1 << pin);
			}			
		break;
	
		case PTB:
			//switch(pin)
			//{
			SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;
			PORT_PCR_REG(PORTB_BASE_PTR,pin) = PORT_PCR_MUX(1);
			if(mode == OUTPUT)
			{
				GPIOB_PDDR |= (1 << pin);
			}
			else if(mode == INPUT)
			{
				GPIOB_PDDR &=~ (1 << pin);
			}
			//}
		break;
		
		case PTC:
			SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;
			PORT_PCR_REG(PORTC_BASE_PTR,pin) = PORT_PCR_MUX(1);
			if(mode == OUTPUT)
			{
				GPIOC_PDDR |= (1 << pin);
			}
			else if(mode == INPUT)
			{
				GPIOC_PDDR &= (1 << pin);
			}			
		break;
		
		case PTD:
			SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;
			PORT_PCR_REG(PORTD_BASE_PTR,pin) = PORT_PCR_MUX(1);
			if(mode == OUTPUT)
			{
				GPIOD_PDDR |= (1 << pin);
			}
			else if(mode == INPUT)
			{
				GPIOD_PDDR &=~ (1 << pin);
			}			
		break;
		
		case PTE:
			SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;
			PORT_PCR_REG(PORTE_BASE_PTR,pin) = PORT_PCR_MUX(1);
			if(mode == OUTPUT)
			{
				GPIOE_PDDR |= (1 << pin);
			}
			else if(mode == INPUT)
			{
				GPIOE_PDDR &=~ (1 << pin);
			}			
		break;
	}
}
/********************************************************************/
// Função que set o pino 0 ou 1
/********************************************************************/
void gpio_set(uint8_t port, uint8_t pin, uint8_t value)
{
	switch(port)
	{
		case PTA:
			if(value == HIGH)
			{
				GPIOA_PSOR |= (1 << pin);
			}
			else if(value == LOW)
			{
				GPIOA_PDOR &=~ (1 << pin);
			}
		break;	
	
		case PTB:
			if(value == HIGH)
			{
				GPIOB_PSOR |= (1 << pin);
			}
			else if(value == LOW)
			{
				GPIOB_PDOR &=~ (1 << pin);
			}
		break;	
		
		case PTC:
			if(value == HIGH)
			{
				GPIOC_PSOR |= (1 << pin);
			}
			else if(value == LOW)
			{
				GPIOC_PDOR &=~ (1 << pin);
			}
		break;	
		
		case PTD:
			if(value == HIGH)
			{
				GPIOD_PSOR |= (1 << pin);
			}
			else if(value == LOW)
			{
				GPIOD_PDOR &=~ (1 << pin);
			}
		break;	
		
		case PTE:
			if(value == HIGH)
			{
				GPIOE_PSOR |= (1 << pin);
			}
			else if(value == LOW)
			{
				GPIOE_PDOR &=~ (1 << pin);
			}
		break;	
	}
}
/********************************************************************/
// função que inverte o valor do pino
/********************************************************************/
void gpio_toggle(uint8_t port, uint8_t pin)
{
	switch(port)
	{
		case PTA:
			GPIOA_PTOR = (1 << pin);
		break;
		
		case PTB:
			GPIOB_PTOR = (1 << pin);
		break;
		
		case PTC:
			GPIOC_PTOR = (1 << pin);
		break;
		
		case PTD:
			GPIOD_PTOR = (1 << pin);
		break;
		
		case PTE:
			GPIOE_PTOR = (1 << pin);
		break;
	}
}
/********************************************************************/
// função que le o valor do pino
/********************************************************************/
bool gpio_read(uint8_t port, uint8_t pin)
{
	switch(port)
	{
		case PTA:
			/*if ( GPIOA_PDIR & (1 << pin))
			{
				return TRUE;
			}
			else
			{
				return FALSE;
			}*/
			return (GPIOA_PDIR & (1 << pin));
		break;
		
		case PTB:
			/*if ( GPIOB_PDIR & (1 << pin))
			{
				return TRUE;
			}
			else
			{
				return FALSE;
			}*/
			return (GPIOB_PDIR & (1 << pin));
		break;	
		
		case PTC:
			/*if ( GPIOC_PDIR &= (1 << pin))
			{
				return TRUE;
			}
			else
			{
				return FALSE;
			}
			*/
			return (GPIOC_PDIR & (1 << pin));
		break;	
		
		case PTD:
			/*if ( GPIOD_PDIR & (1 << pin))
			{
				return TRUE;
			}
			else
			{
				return FALSE;
			}*/
			return (GPIOD_PDIR & (1 << pin));
		break;	
		
		case PTE:
			/*if ( GPIOE_PDIR & (1 << pin))
			{
				return TRUE;
			}
			else
			{
				return FALSE;
			}*/
			return ( GPIOE_PDIR & (1 << pin));
		break;	
	}
}
/********************************************************************/
