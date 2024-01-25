 /******************************************************************************
 *
 * File Name: Fan_Controller.c
 *
 * Description: Temperature based Fan Control System
 *
 * Created on: October 11, 2023
 *
 * Author: Peter Nabil
 *
 *******************************************************************************/

#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "DC_Motor.h"

int main(void)
{
	uint8 temperature;
	ADC_ConfigType ADC_Configurations = {INTERNAL_VOLTAGE_REFERENCE, DIVISION_FACTOR_8};
	ADC_init(&ADC_Configurations);
	LCD_init();
	DcMotor_Init();
	LCD_displayStringRowColumn(0, 3, "Fan is ");
	LCD_displayStringRowColumn(1, 3, "Temp = ");
	LCD_displayStringRowColumn(1, 13, "C");

	while(1)
	{
		temperature = LM35_getTemperature();
		LCD_moveCursor(1, 10);

		if(temperature < 30)
		{
			DcMotor_Rotate(STOP, 0);
			LCD_intgerToString(temperature);
			LCD_displayCharacter(' ');
			LCD_displayStringRowColumn(0, 10, "OFF");
		}
		else if((temperature >= 30) && (temperature < 60))
		{
			DcMotor_Rotate(CLOCKWISE, 25);
			LCD_intgerToString(temperature);
			LCD_displayCharacter(' ');
			LCD_displayStringRowColumn(0, 10, "ON");
			LCD_displayCharacter(' ');
		}
		else if((temperature >= 60) && (temperature < 90))
		{
			DcMotor_Rotate(CLOCKWISE, 50);
			LCD_intgerToString(temperature);
			LCD_displayCharacter(' ');
			LCD_displayStringRowColumn(0, 10, "ON");
			LCD_displayCharacter(' ');
		}
		else if((temperature >= 90) && (temperature < 100))
		{
			DcMotor_Rotate(CLOCKWISE, 75);
			LCD_intgerToString(temperature);
			LCD_displayCharacter(' ');
			LCD_displayStringRowColumn(0, 10, "ON");
			LCD_displayCharacter(' ');
		}
		else if((temperature >= 100) && (temperature < 120))
		{
			DcMotor_Rotate(CLOCKWISE, 75);
			LCD_intgerToString(temperature);
			LCD_displayStringRowColumn(0, 10, "ON");
			LCD_displayCharacter(' ');
		}
		else if(temperature >= 120)
		{
			DcMotor_Rotate(CLOCKWISE, 100);
			LCD_intgerToString(temperature);
			LCD_displayStringRowColumn(0, 10, "ON");
			LCD_displayCharacter(' ');
		}
	}
	return 0;
}
