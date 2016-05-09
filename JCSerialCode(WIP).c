/***********************************************************
Programmer: John C Stinson III
For: CompE 3150 Project 2
Purpose: Serial communication handler
***********************************************************/
#include<reg932.h>
#include<stdlib.h>
/*#include<string.h>*/
#include"uart.h"

void playMenu();
void cheatMap(char** /*map_array*/, char arr_x, char arr_y);

void main ()
{
	uart_init();
	P2M1 = 0x00; //I think this sets it to Bidir, but I'd have to double check

	while(1)
	{
		;
	}
}

void playMenu()
{
	char* title = "Simon's A-MAZE-ing Adventures!";
	char* star_bar = "*********************************";
	char* menu1 = "Please select difficulty level: \n";
	char* menu2 = "1) Easy          2) Medium          3) Hard          4)DEBUG \n";

	int titlesize = sizeof(title) / sizeof(title[0]);
	int starsize = sizeof(star_bar) / sizeof(title[0]);
	int menu1size = sizeof(menu1) / sizeof(title[0]);
	int menu2size = sizeof(menu2) / sizeof(title[0]);

	char i;
	for (i = 0; i < starsize; i++)
	{
		uart_transmit(star_bar[i]);
	}
	uart_transmit('\n');
	for (i = 0; i < titlesize; i++)
	{
		uart_transmit(title[i]);
	}
	uart_transmit('\n');
	for (i = 0; i < starsize; i++)
	{
		uart_transmit(star_bar[i]);
	}
	uart_transmit('\n');
	uart_transmit('\n');
	for (i = 0; i < menu1size; i++)
	{
		uart_transmit(menu1[i]);
	}
	uart_transmit('\n');
	for (i = 0; i < menu2size; i++)
	{
		uart_transmit(menu2[i]);
	}
	uart_transmit('\n');

	//Need to add more stuff, but this is the rough idea

	return;
}

void cheatMap(char** map_array, char arr_x, char arr_y) //rename map_array to group code name for the map array
{
	char i;
	char j;
	for (i = 0; i < arr_x; i++)
	{
		
		for (j = 0; j < arr_y; j++)
		{
			uart_transmit(map_array[i][j]);
		}
		uart_transmit('\n'); //I think this will work?
	}
	return;
}

