/*
Han, Christian
cjh3752
16295
EE312-Assignment 2
*/

#include <stdio.h>
int main(void)
{
	while (1) {

		int number = 0;//used for number selection

		printf("Enter a number from the menu (1 - 11) to select a specific conversion to perform or to quit: ");
		scanf("%d", &number);
		
		if (number == 1)
		{
			int austin_hours, austin_minutes, converted_ireland_hours;

			printf("Enter Austin time to be converted, expressed in hours and minutes: ");
			scanf("%d %d", &austin_hours, &austin_minutes);

			converted_ireland_hours = austin_hours + 6;

			if (converted_ireland_hours >= 24)
			{
				converted_ireland_hours = converted_ireland_hours - 24;
				printf("The time in Ireland equivalent to %d hours %d minutes in Austin is %d hours %d minutes of the next day.\n", austin_hours, austin_minutes, converted_ireland_hours, austin_minutes);
			}
			else
			{
				printf("The time in Ireland equivalent to %d hours %d minutes in Austin is %d hours %d minutes of the same day.\n", austin_hours, austin_minutes, converted_ireland_hours, austin_minutes);
			}
			
		}

		else if (number == 2)
		{
			int ireland_hours, ireland_minutes, converted_austin_hours;
			printf("Enter Irish time to be converted, expressed in hours and minutes: ");
			scanf("%d %d", &ireland_hours, &ireland_minutes);

			converted_austin_hours = ireland_hours - 6; 

			if (converted_austin_hours < 0)
			{
				converted_austin_hours = 24 + converted_austin_hours;
				printf("The time in Austin equivalent to %d hours %d minutes in Ireland is %d hours %d minutes of the previous day.\n", ireland_hours, ireland_minutes, converted_austin_hours, ireland_minutes);
			}
			else
			{
				printf("The time in Austin equivalent to %d hours %d minutes in Ireland is %d hours %d minutes of the same day.\n", ireland_hours, ireland_minutes, converted_austin_hours, ireland_minutes);
			}
		}

		else if (number == 3)//GOOD
		{
			float dollars, amount_in_euros;
			const float dollar_exchange = 0.89;

			printf("Enter USD value: ");
			scanf("%f", &dollars);

			amount_in_euros = dollar_exchange * dollars;

			printf("\nEUR value is: %f Euros\n", amount_in_euros); 

		}

		else if (number == 4)
		{
			float euros, amount_in_dollars;
			const float euro_exchange = 1.13;
			
			printf("Enter EUR value: ");
			scanf("%f", &euros);
			
			amount_in_dollars = euro_exchange * euros;

			int dollar_integer = (int)amount_in_dollars;
			float cents_decimal = amount_in_dollars - dollar_integer;
			cents_decimal = cents_decimal * 100;

			
			printf("USD value is: $%d dollars %.0f cents\n", dollar_integer, cents_decimal);//no clue if rounding works yet need to look more into
		}

		else if (number == 5)//good
		{
			float temp_f, final_temp_c;
			const float freeze = 32.0;
			const float scale1 = 5.0 / 9.0;

			printf("Enter temperature in Fahrenheit: ");
			scanf("%f", &temp_f);

			final_temp_c = (scale1)*(temp_f - freeze);

			printf("\nTemperature in Celsius is: %f\n", final_temp_c);
		}

		else if (number == 6)//pretty sure rounding is good
		{
			float temp_c, final_temp_f;
			const float scale2 = 9.0 / 5.0;
			const float freeze = 32.0;

			printf("Enter temperature in Celsius: ");
			scanf("%f", &temp_c);

			final_temp_f = (scale2 * temp_c) + freeze;

			printf("\nTemperature in Fahrenheit is: %.0f\n", final_temp_f);

		}

		else if (number == 7)// need to fix 2 lb 16 oz. 
		{
			const float kilo_scale = 2.20462262185;
			float kilograms, weight_in_pounds;

			printf("Enter weight in kg: "); //2.20462262185 lb = 1 kg
			scanf("%f", &kilograms);

			weight_in_pounds = kilo_scale * kilograms;

			int pounds_integer = (int) weight_in_pounds;
			float ounces_decimal = weight_in_pounds - pounds_integer;
			ounces_decimal = ounces_decimal * 16;

			if (ounces_decimal >= 15.5)
			{
				ounces_decimal = 0;
				pounds_integer = pounds_integer + 1;
				printf("Weight in pounds and ounces is: %d lb %.0f oz\n", pounds_integer, ounces_decimal);
			}
			
			else
			{
				printf("Weight in pounds and ounces is: %d lb %.0f oz\n", pounds_integer, ounces_decimal);
			}
			
		}

		else if (number == 8)
		{
			float pounds, ounces, weight_in_kilograms;
			const float ounce_to_pound = 16.0;
			const float pounds_to_kilo_scale = 0.45359237;

			printf("Enter weight in pounds and ounces: ");
			scanf("%f %f", &pounds, &ounces);

			ounces = ounces / ounce_to_pound;
			pounds = pounds + ounces;
			weight_in_kilograms = pounds * pounds_to_kilo_scale;

			printf("Weight in kg is: %f kg\n", weight_in_kilograms);
		}

		else if (number == 9)
		{
			float distance_km, final_distance_m;
			const float scale_km = 0.6213712;

			printf("Enter distances in km: ");
			scanf("%f", &distance_km);

			final_distance_m = (scale_km)* distance_km;

			printf("\nDistance in miles is: %f mi\n", final_distance_m);

		}

		else if (number == 10)
		{
			float distance_m, final_distance_km;
			const float scale_m = 1.609344;

			printf("Enter distance in miles: ");
			scanf("%f", &distance_m);

			final_distance_km = scale_m * distance_m;

			printf("\nDistance in km is: %f km\n", final_distance_km);
		}

		else if (number == 11)
		{
			printf("\nGood Bye\n");
			break;
		}
	}

	
}

