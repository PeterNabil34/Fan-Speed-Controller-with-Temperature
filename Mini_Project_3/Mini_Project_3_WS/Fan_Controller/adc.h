 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: Header file for the ATmega32 ADC driver
 *
 * Author: Peter Nabil
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum
{
	AREF,AVCC,INTERNAL_VOLTAGE_REFERENCE=3
}ADC_ReferenceVolatge;

typedef enum
{
	DIVISION_FACTOR_2_ADPS0_0,DIVISION_FACTOR_2_ADPS0_1,DIVISION_FACTOR_4,DIVISION_FACTOR_8,DIVISION_FACTOR_16,DIVISION_FACTOR_32,DIVISION_FACTOR_64,DIVISION_FACTOR_128
}ADC_Prescaler;

typedef struct
{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   (2.56)

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
