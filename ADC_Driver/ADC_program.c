/*
 * ADC_program.c
 *
 *  Created on: Apr 19, 2020
 *      Author: madel
 */

#include "STD_TYPES.h"

#include "ADC_interface.h"
#include "ADC_config.h"

/* Registers */

#define ADC_BASE_ADDRESS	 ( (volatile ADC_Registers_t*) (0x24))
#define ADC_SFIOR			*( (volatile uint8_t*) (0x50))

/* Defines */


#define ADATE_SET			(0x20)
#define ADATE_CLR			(0xDF)


#define ADEN				(0x80)
#define ADSC				(0x40)
#define ADIE				(0x08)

typedef enum{

	Available = 0 ,
	Busy      = 1

}ADC_State_t;

typedef struct{

uint8_t ADCL;
uint8_t ADCH;
uint8_t ADCSRA;
uint8_t ADMUX;

}ADC_Registers_t;

typedef struct{

uint16_t *DataReservior;
uint8_t   ADC_State ;
ADC_CBF_t ADC_Internal_CBF;

}ADC_InternalReservior_t;

ADC_InternalReservior_t ADC_InternalReservior;

/*================================================== Implementations of APIs =================================================*/

ADC_Errortype_t ADC_Init(void)
{
	ADC_Errortype_t Local_Error = ADC_ERROR_OK;
	volatile ADC_Registers_t *ADC_Registers = ADC_BASE_ADDRESS;

	/* Setup the ADC */
	ADC_Registers->ADMUX = ADC_VOLTAGE_SOURCE | ADC_DATA_ADJUST;

	/* Enable the Interrupt & Set the prescaler  and enabling the ADC */
	ADC_Registers->ADCSRA = ADEN | ADIE | ADC_CLK_PRESCALER;




	return Local_Error;
}

ADC_Errortype_t ADC_StartConv(uint8_t Channel , uint16_t * Data ,uint8_t ADC_AUTO_TRIGGER)
{
	ADC_Errortype_t Local_Error = ADC_ERROR_OK;
	volatile ADC_Registers_t *ADC_Registers = ADC_BASE_ADDRESS;

	if( ADC_InternalReservior.ADC_State == Available )
	{
		if(Data)
		{
			/* Set the required channel to start */
			ADC_Registers->ADMUX |= Channel ;


			/* Set Auto Trigger option if exist */
			if(ADC_AUTO_TRIGGER == ADC_AUTO_TRIGGER_NO_TRIGGER)
			{
				ADC_Registers->ADCSRA &= ADATE_CLR;
			}
			else
			{
				ADC_Registers->ADCSRA |= ADATE_SET;

				/* Set the required mode of trigger */
				ADC_SFIOR |= ADC_AUTO_TRIGGER;
			}

			/* update the internal reservoir */
			ADC_InternalReservior.DataReservior = Data;

			/* Begin Conversion */
			ADC_Registers->ADCSRA |= ADSC;

		}

		else
		{
			/* NULL Pointer ERROR */
		}
	}
	else
	{
		/* Busy Error */
	}

	return Local_Error;
}

ADC_Errortype_t ADC_SetCallBackFunction(ADC_CBF_t ADC_CBF)
{
	ADC_Errortype_t Local_Error = ADC_ERROR_OK;

	if(ADC_CBF)
	{

		ADC_InternalReservior.ADC_Internal_CBF = ADC_CBF;
	}
	else
	{
		/* NULL POINTER ERROR */
	}

	return Local_Error;
}


/* Handler */
#define ADC					__vector_16

#define ISR(vect)			void vect(void) __attribute__((signal,used));\
							void vect(void)

ISR(ADC)
{
	volatile ADC_Registers_t *ADC_Registers = ADC_BASE_ADDRESS;

	/* return the data to the user */
	if(ADC_DATA_ADJUST == ADC_RIGHT_ADJUST)
	{
		*(ADC_InternalReservior.DataReservior) = ADC_Registers->ADCL | (ADC_Registers->ADCH << 8);
	}
	else
	{
		*(ADC_InternalReservior.DataReservior) = (ADC_Registers->ADCH);
	}
	/* Reset the values of the internal reservoir */
	ADC_InternalReservior.DataReservior = NULL;
	ADC_InternalReservior.ADC_State = Available;

	/* call CBF */
	if( ADC_InternalReservior.ADC_Internal_CBF )
	{
		ADC_InternalReservior.ADC_Internal_CBF();
	}
}
