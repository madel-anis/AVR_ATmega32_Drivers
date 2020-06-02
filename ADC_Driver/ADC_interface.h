/*
 * ADC_interface.h
 *
 *  Created on: Apr 19, 2020
 *      Author: madel
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "ADC_config.h"


/*--------------------------------------------------- User Macros --------------------------------------------------*/

/* Channels */
#define ADC_SINGLE_ENDED_CHANNEL_0						(0x00)
#define ADC_SINGLE_ENDED_CHANNEL_1						(0x01)
#define ADC_SINGLE_ENDED_CHANNEL_2						(0x02)
#define ADC_SINGLE_ENDED_CHANNEL_3						(0x03)
#define ADC_SINGLE_ENDED_CHANNEL_4						(0x04)
#define ADC_SINGLE_ENDED_CHANNEL_5						(0x05)
#define ADC_SINGLE_ENDED_CHANNEL_6						(0x06)
#define ADC_SINGLE_ENDED_CHANNEL_7						(0x07)
/* Differential didn't added yet */

/* Auto Trigger MODE */
#define ADC_AUTO_TRIGGER_NO_TRIGGER						(0x00)
#define ADC_AUTO_TRIGGER_ANALOG_COMPARATOR				(0x20)
#define ADC_AUTO_TRIGGER_EXT_INTERRUPT_REQ_0			(0x40)
#define ADC_AUTO_TRIGGER_TIMER0_COMPARE_MATCH			(0x60)
#define ADC_AUTO_TRIGGER_TIMER0_OVERFLOW				(0x80)
#define ADC_AUTO_TRIGGER_TIMER1_COMPARE_MATCH			(0xA0)
#define ADC_AUTO_TRIGGER_TIMER1_OVERFLOW				(0xC0)
#define ADC_AUTO_TRIGGER_TIMER1_CAPTURE_EVENT			(0xE0)
/*----------------------------------------------- Configuration Macros -----------------------------------------------*/


/* Voltage Source Options */
#define ADC_EXTERNAL_VOLTAGE							(0x00)
#define ADC_SAME_AS_VCC									(0x40)
#define ADC_INTERNAL_LOW_VOLTAGE						(0xC0)

/* Data Position Adjustment Options */
#define ADC_LEFT_ADJUST									(0x20)
#define ADC_RIGHT_ADJUST								(0x00)

/* ADC Clock PreScaler */
#define ADC_PRESCALER_CLK_DIV_2							(0x01)
#define ADC_PRESCALER_CLK_DIV_4							(0x02)
#define ADC_PRESCALER_CLK_DIV_8							(0x03)
#define ADC_PRESCALER_CLK_DIV_16						(0x04)
#define ADC_PRESCALER_CLK_DIV_32						(0x05)
#define ADC_PRESCALER_CLK_DIV_64						(0x06)
#define ADC_PRESCALER_CLK_DIV_128						(0x07)


/*================================================ General Definitions ====================================================*/

typedef uint8_t ADC_Errortype_t;

#define ADC_ERROR_OK						(0x00)


typedef void(*ADC_CBF_t)(void);
/*------------------------------------------------------ Prototypes  ------------------------------------------------------*/
ADC_Errortype_t ADC_Init(void);
ADC_Errortype_t ADC_StartConv(uint8_t Channel , uint16_t * Data ,uint8_t ADC_AUTO_TRIGGER);
ADC_Errortype_t ADC_SetCallBackFunction(ADC_CBF_t ADC_CBF);


#endif /* ADC_INTERFACE_H_ */
