/*
 * ADC_config.h
 *
 *  Created on: Apr 19, 2020
 *      Author: madel
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/* USER Names for used channels */
#define pot_1				ADC_SINGLE_ENDED_CHANNEL_0
#define pot_2				ADC_SINGLE_ENDED_CHANNEL_1

/*======================================================= PreConfiguration Options =======================================================*/
#define ADC_NUMBER_OF_CH_USED					(1)


/* Voltage Source Selection
 *
 * 		Options:
 * 				1- ADC_EXTERNAL_VOLTAGE
 * 				2- ADC_SAME_AS_VCC
 * 				3- ADC_INTERNAL_LOW_VOLTAGE
 *
 *  */
#define ADC_VOLTAGE_SOURCE						ADC_SAME_AS_VCC


/* Data Position Adjustment
 *
 * 		Options:
 * 				1- ADC_LEFT_ADJUST
 * 				2- ADC_RIGHT_ADJUST
 *
 *  */
#define ADC_DATA_ADJUST						ADC_RIGHT_ADJUST


/* ADC Clock PreScaler (must be lower than 200kHZ for stable measurement)
 *
 * 		Options:
 * 				1- ADC_PRESCALER_CLK_DIV_2
 * 				2- ADC_PRESCALER_CLK_DIV_4
 *				3- ADC_PRESCALER_CLK_DIV_8
 *				4- ADC_PRESCALER_CLK_DIV_16
 *				5- ADC_PRESCALER_CLK_DIV_32
 *				6- ADC_PRESCALER_CLK_DIV_64
 *				7- ADC_PRESCALER_CLK_DIV_128
 *
 *  */
#define ADC_CLK_PRESCALER					ADC_PRESCALER_CLK_DIV_64




#endif /* ADC_CONFIG_H_ */
