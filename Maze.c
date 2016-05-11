#include<reg932.h>
#include<stdlib.h>
#include"uart.h"
#include "maps.h"

sbit LED1 = P2 ^ 4;
sbit LED2 = P0 ^ 5;
sbit LED3 = P2 ^ 7;
sbit LED4 = P0 ^ 6;
sbit LED5 = P1 ^ 6;
sbit LED6 = P0 ^ 4;
sbit LED7 = P2 ^ 5;
sbit LED8 = P0 ^ 7;
sbit LED9 = P2 ^ 6;

sbit SW1 = P2 ^ 0;
sbit SW2 = P0 ^ 1;
sbit SW3 = P2 ^ 3;
sbit SW4 = P0 ^ 2;
sbit SW5 = P1 ^ 4;
sbit SW6 = P0 ^ 0;
sbit SW8 = P0 ^ 3;



void delay(long x)
{
	long i = 0;
	for (i; i<x; i++);
}

void cheatMap(const char** map_array, unsigned char arr_x, unsigned char arr_y) //rename map_array to group code name for the map array
{
	unsigned char i;
	unsigned char j;
	for (i = 0; i < arr_x; i++)
	{

		for (j = 0; j < arr_y; j++)
		{
			uart_transmit(map_array[i][j]);
		}
		uart_transmit('\n'); //I think this will work?
	}
	uart_transmit(arr_x);
	uart_transmit('\n');
	uart_transmit(arr_y);
	return;
}

void Redraw_Map(unsigned char Play_x, unsigned char Play_y, const char** Map)
{
	unsigned char i = 0;
	//Shows what the 8 spaces around the player are
	//LED1
	if (Map[Play_x - 1][Play_y - 1] == 'W') //Wall
		LED1 = 0;
	else if (Map[Play_x - 1][Play_y - 1] == 'G')
	{
		for (i; i < 3; i++)
		{
			LED1 = 0;
			delay(100);
			LED1 = 1;
			delay(100);
		}
	}
	else //Open
		LED1 = 1;
	//LED2
	if (Map[Play_x][Play_y - 1] == 'W') //Wall
		LED2 = 0;
	else if (Map[Play_x][Play_y - 1] == 'G') //Goal
	{
		for (i; i < 3; i++)
		{
			LED2 = 0;
			delay(100);
			LED2 = 1;
			delay(100);
		}
	}
	else //Open
		LED2 = 1;
	//LED3
	if (Map[Play_x + 1][Play_y - 1] == 'W') //Wall
		LED3 = 0;
	else if (Map[Play_x + 1][Play_y - 1] == 'G') //Goal
	{
		for (i; i < 3; i++)
		{
			LED3 = 0;
			delay(100);
			LED3 = 1;
			delay(100);
		}
	}
	else //Open
		LED3 = 1;
	//LED4
	if (Map[Play_x - 1][Play_y] == 'W') //Wall
		LED4 = 0;
	else if (Map[Play_x - 1][Play_y] == 'G') //Goal
	{
		for (i; i < 3; i++)
		{
			LED4 = 0;
			delay(100);
			LED4 = 1;
			delay(100);
		}
	}
	else //Open
		LED4 = 1;
	//LED5
	if (Map[Play_x][Play_y] == 'W') //Wall
		LED5 = 0;
	else if (Map[Play_x][Play_y] == 'G') //Goal
	{
		for (i; i < 3; i++)
		{
			LED5 = 0;
			delay(100);
			LED5 = 1;
			delay(100);
		}
	}
	else //Open
		LED5 = 1;
	//LED6
	if (Map[Play_x + 1][Play_y] == 'W') //Wall
		LED6 = 0;
	else if (Map[Play_x + 1][Play_y] == 'G') //Goal
	{
		for (i; i < 3; i++)
		{
			LED6 = 0;
			delay(100);
			LED6 = 1;
			delay(100);
		}
	}
	else //Open
		LED6 = 1;
	//LED7
	if (Map[Play_x - 1][Play_y + 1] == 'W') //Wall
		LED7 = 0;
	else if (Map[Play_x - 1][Play_y + 1] == 'G') //Goal
	{
		for (i; i < 3; i++)
		{
			LED7 = 0;
			delay(100);
			LED7 = 1;
			delay(100);
		}
	}
	else //Open
		LED7 = 1;
	//LED8
	if (Map[Play_x][Play_y + 1] == 'W') //Wall
		LED8 = 0;
	else if (Map[Play_x][Play_y + 1] == 'G') //Goal
	{
		for (i; i < 3; i++)
		{
			LED8 = 0;
			delay(100);
			LED8 = 1;
			delay(100);
		}
	}
	else //Open
		LED8 = 1;
	//LED9
	if (Map[Play_x + 1][Play_y + 1] == 'W') //Wall
		LED9 = 0;
	else if (Map[Play_x + 1][Play_y + 1] == 'G') //Goal
	{
		for (i; i < 3; i++)
		{
			LED9 = 0;
			delay(100);
			LED9 = 1;
			delay(100);
		}
	}
	else //Open
		LED9 = 1;

}

//Button Actions
//Up button
void Up (unsigned char Play_x,unsigned char Play_y, const char** Map) {
	if (Map[Play_x][Play_y-1]!= 'W') 
		Play_y -= 1;
	Redraw_Map(Play_x, Play_y, Map);
	return;
}

//Down
void Down (unsigned char Play_x,unsigned char Play_y, const char** Map) {
	if (Map[Play_x][Play_y + 1] != 'W')
		Play_y += 1;
	Redraw_Map(Play_x, Play_y, Map);
	return;
}

//Right 
void Right(unsigned char Play_x,unsigned char Play_y, const char** Map) {
	if (Map[Play_x + 1][Play_y] != 'W')
		Play_x += 1;
	Redraw_Map(Play_x, Play_y, Map);
	return;
}

//Left 
void Left(unsigned char Play_x,unsigned char Play_y, const char** Map) {
	if (Map[Play_x - 1][Play_y] != 'W')
		Play_x -= 1;
	Redraw_Map(Play_x, Play_y, Map);
	return;
}
//Check if Player is at goal

void GameStart(const char** Map, const unsigned char Start_x, const unsigned char Start_y) {
	unsigned char GameOver = 0; //reset every new game
	unsigned char Play_x = Start_x;	//Load starting positions
	unsigned char Play_y = Start_y;
	unsigned char i = 0;
	unsigned char k = 0;

	Redraw_Map(Play_x, Play_y, Map);

	while (GameOver == 0) { //This loop plays the game until finished
		while (SW1 == 0 || SW3 == 0 || SW2 == 0 || SW8 == 0 || SW4 == 0 || SW6 == 0) { //Check if any input
			//Nothing to do here
		}

		delay(10);
			//waiting for input
		if (SW1 == 0) //Exit Button
			GameOver = 0;
		else if (SW5 == 0) // Help Button
			;//Help(Play_x, Play_y, Map[][]);
		else if (SW2 == 0)
			Up(Play_x, Play_y, Map);
		else if (SW8 == 0)
			Down(Play_x, Play_y, Map);
		else if (SW4 == 0)
			Left(Play_x, Play_y, Map);
		else if (SW6 == 0)
			Right(Play_x, Play_y, Map);
		else if (SW3 == 0)
			cheatMap(Map, Play_x, Play_y);
			//Check if Game Over
		if (Map[Play_x][Play_y] == 'G')
			GameOver = 1;
	}
	return;
}



void playMenu()
{
	char* title = "Simon's A-MAZE-ing Adventures!";
	char* star_bar = "*********************************";
	char* menu1 = "Please select difficulty level: \n";
	char* menu2 = "1) Easy          2) Medium          3) Hard          4)DEBUG \n";

	unsigned char titlesize = sizeof(title) / sizeof(title[0]);
	unsigned char starsize = sizeof(star_bar) / sizeof(title[0]);
	unsigned char menu1size = sizeof(menu1) / sizeof(title[0]);
	unsigned char menu2size = sizeof(menu2) / sizeof(title[0]);

	unsigned char i;
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

	while (1)
	{
		if (SW1 == 0) //Exit Button
			GameStart(&map1[7][7], M1startX, M1startY);
		//victory
		else if (P2^1 == 0)
			GameStart(&map2[7][7], M2startX, M2startY);
		//victory
		else if (P2^2 == 0)
			GameStart(&map3[12][12], M3startX, M3startY);
		//victory
	}

	return;
}

//Looping Code for playing the game
void main(void)
{
	uart_init();
	P2M1 = 0x00;
	
	while (1)
	{
		playMenu();
	}

	return;
}	
