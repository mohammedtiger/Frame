/*
 ============================================================================
 Name        : EmbeddedFab_Final2.c
 Author      : mohammed nabil
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARR_TOTAL_INDEX   		100
enum
{
	TEMP_VAL,
	LUX_VAL,
	HUM_VAL,
	VOLT_VAL
};


typedef struct data Var_Data;
struct data
{
	int temp;
	int lux;
	int hum;
	int volt;
	int value;
};


Var_Data Variables;

unsigned char incoming_data_arr[ARR_TOTAL_INDEX];

void Read_arr(unsigned char *Arr);
void Print_arr(unsigned char *Arr);
void ASCII_To_Var(unsigned char *Arr , Var_Data *var);

int main(void) {

	for(;;)
	{
		Read_arr(incoming_data_arr);
		ASCII_To_Var(incoming_data_arr , &Variables);

		printf("Temp : %d \n" , Variables.temp);
		printf("Lux : %d \n" , Variables.lux);
		printf("Hum : %d \n" , Variables.hum);
		printf("Volt : %d \n" , Variables.volt);

	}


	return EXIT_SUCCESS;
}


void Read_arr(unsigned char *Arr)
{
	for (int index = 0 ; index < ARR_TOTAL_INDEX ; index ++)
	{
		scanf("%c" , &Arr[index]);
		if(Arr[index] == '\n')
		{
			Arr[index] = 0;
			break;
		}
	}
}

void Print_arr(unsigned char *Arr)
{
	int index = 0;

	while(Arr[index] != 0)
	{
		printf("%c" , Arr[index]);
		index ++;
	}
}


void ASCII_To_Var(unsigned char *Arr , Var_Data *var)
{
	char stored_var = 0;
	unsigned char Stored_var_arr[10];
	char stored_index = 0;

	int new_index = 0;

	for(int index = 0; index < ARR_TOTAL_INDEX ; index ++)
	{
		if(Arr[index] == 'A')
		{
			stored_var = 'A';
			stored_index = 0;
			memset(Stored_var_arr , 0 , sizeof(Stored_var_arr));
		}
		else if (Arr[index] == 'B')
		{
			stored_var = 'B';
			var->value = atoi(Stored_var_arr);
			stored_index = 0;
			memset(Stored_var_arr , 0 , sizeof(Stored_var_arr));
		}
		else if (Arr[index] == 'C')
		{
			stored_var = 'C';
			new_index = atoi(Stored_var_arr);
			if(new_index == TEMP_VAL)
			{
				var->temp = var->value;
			}
			else if(new_index == LUX_VAL)
			{
				var->lux = var->value;
			}
			else if(new_index == HUM_VAL)
			{
				var->hum = var->value;
			}
			else if(new_index == VOLT_VAL)
			{
				var->volt = var->value;
			}
			stored_index = 0;
			memset(Stored_var_arr , 0 , sizeof(Stored_var_arr));
		}


		if(Arr[index] != 'A' && stored_var == 'A' )
		{
			Stored_var_arr[stored_index++]=Arr[index];
		}
		if(Arr[index] != 'B' && stored_var == 'B' )
		{
			Stored_var_arr[stored_index++]=Arr[index];
		}

	}

}
