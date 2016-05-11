#include<reg932.h>
#include<stdlib.h>
#include"uart.h"
#include "maps.h"

sbit LED1 = P2^4;
sbit LED2 = P2 ^ 4;
sbit LED3 = P2 ^ 4;
sbit LED4 = P2 ^ 4;
sbit LED5 = P2 ^ 4;
sbit LED6 = P2 ^ 4;
sbit LED7 = P2 ^ 4;
sbit LED8 = P2 ^ 4;
sbit LED9 = P2 ^ 4;



void delay(long x)
{
	long i = 0;
	for (i; i<x; i++);
}

void cheatMap(char** map_array, unsigned char arr_x, unsigned char arr_y) //rename map_array to group code name for the map array
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

void Redraw_map(unsigned char Play_x, unsigned char Play_y, const unsigned char** Map)
{
	unsigned char i = 0;
	//Shows what the 8 spaces around the player are
	//LED1
	if (Map[Play_x - 1][Play_y - 1] == 'W') //Wall
		P2^4 = 0;
	else if (Map[Play_x - 1][Play_y - 1] == 'G')
	{
		for (i; i < 3; i++)
		{
			P2^4 = 0;
			delay(100);
			P2^4 = 1;
			delay(100);
		}
	}
	else //Open
		P2^4 = 1;
	//LED2
	if (Map[Play_x][Play_y - 1] == 'W') //Wall
		P0^5 = 0;
	else if (Map[Play_x][Play_y - 1] == 'G') //Goal
	{
		for (i; i < 3; i++)
		{
			P0^5 = 0;
			delay(100);
			P0^5 = 1;
			delay(100);
		}
	}
	else //Open
		P0^5 = 1;
	//LED3
	if (Map[Play_x + 1][Play_y - 1] == 'W') //Wall
		P2^7 = 0;
	else if (Map[Play_x + 1][Play_y - 1] == 'G') //Goal
	{
		for (i; i < 3; i++)
		{
			P2^7 = 0;
			delay(100);
			P2^7 = 1;
			delay(100);
		}
	}
	else //Open
		P2^7 = 1;
	//LED4
	if (Map[Play_x - 1][Play_y] == 'W') //Wall
		P0^6 = 0;
	else if (Map[Play_x - 1][Play_y] == 'G') //Goal
	{
		for (i; i < 3; i++)
		{
			P0^6 = 0;
			delay(100);
			P0^6 = 1;
			delay(100);
		}
	}
	else //Open
		P0^6 = 1;
	//LED5
	if (Map[Play_x][Play_y] == 'W') //Wall
		P1^6 = 0;
	else if (Map[Play_x][Play_y] == 'G') //Goal
	{
		for (i; i < 3; i++)
		{
			P1^6 = 0;
			delay(100);
			P1^6 = 1;
			delay(100);
		}
	}
	else //Open
		P1^6 = 1;
	//LED6
	if (Map[Play_x + 1][Play_y] == 'W') //Wall
		P0^4 = 0;
	else if (Map[Play_x + 1][Play_y] == 'G') //Goal
	{
		for (i; i < 3; i++)
		{
			P0^4 = 0;
			delay(100);
			P0^4 = 1;
			delay(100);
		}
	}
	else //Open
		P0^4 = 1;
	//LED7
	if (Map[Play_x - 1][Play_y + 1] == 'W') //Wall
		P2^5 = 0;
	else if (Map[Play_x - 1][Play_y + 1] == 'G') //Goal
	{
		for (i; i < 3; i++)
		{
			P2^5 = 0;
			delay(100);
			P2^5 = 1;
			delay(100);
		}
	}
	else //Open
		P2^5 = 1;
	//LED8
	if (Map[Play_x][Play_y + 1] == 'W') //Wall
		P0^7 = 0;
	else if (Map[Play_x][Play_y + 1] == 'G') //Goal
	{
		for (i; i < 3; i++)
		{
			P0^7 = 0;
			delay(100);
			P0^7 = 1;
			delay(100);
		}
	}
	else //Open
		P0^7 = 1;
	//LED9
	if (Map[Play_x + 1][Play_y + 1] == 'W') //Wall
		P2^6 = 0;
	else if (Map[Play_x + 1][Play_y + 1] == 'G') //Goal
	{
		for (i; i < 3; i++)
		{
			P2^6 = 0;
			delay(100);
			P2^6 = 1;
			delay(100);
		}
	}
	else //Open
		P2^6 = 1;

}

//Button Actions
//Up button
void Up (unsigned char Play_x,unsigned char Play_y, const unsigned char** Map) {
	if (Map[Play_x][Play_y-1]!= 'W') 
		Play_y -= 1;
	Redraw_Map(Play_x, Play_y, Map);
	return;
}

//Down
void Down (unsigned char Play_x,unsigned char Play_y, const unsigned char** Map) {
	if (Map[Play_x][Play_y + 1] != 'W')
		Play_y += 1;
	Redraw_Map(Play_x, Play_y, Map);
	return;
}

//Right 
void Right(unsigned char Play_x,unsigned char Play_y, const unsigned char** Map) {
	if (Map[Play_x + 1][Play_y] != 'W')
		Play_x += 1;
	Redraw_Map(Play_x, Play_y, Map);
	return;
}

//Left 
void Left(unsigned char Play_x,unsigned char Play_y, const unsigned char** Map) {
	if (Map[Play_x - 1][Play_y] != 'W')
		Play_x -= 1;
	Redraw_Map(Play_x, Play_y, Map);
	return;
}
//Check if Player is at goal

void GameStart(Map[][], Start_x, Start_Y) {
	bool GameOver = false; //reset every new game
	unsigned char Play_x = Start_x;	//Load starting positions
	unsigned char Play_y = Start_y;
	Redraw_Map(Play_x, Play_y, Map[][])
	unsigned char i = 0, k = 0;

	while (GameOver == false) { //This loop plays the game until finished
		while (P2^0 == 0 || P2^3 == 0 || P0^1 == 0 || P0^3 == 0 || P0^2 == 0 || P0^0 == 0) { //Check if any input
			//Nothing to do here
		}

		delay(10);
			//waiting for input
		if (P2^0 == 0) //Exit Button
			GameOver = false;
		else if (P1^4 == 0) // Help Button
			;//Help(Play_x, Play_y, Map[][]);
		else if (P0^1 == 0)
			Up(Play_x, Play_y, Map[][]);
		else if (P0^3 == 0)
			Down(Play_x, Play_y, Map[][]);
		else if (P0^2 == 0)
			Left(Play_x, Play_y, Map[][]);
		else if (P0^0 == 0)
			Right(Play_x, Play_y, Map[][]);
		else if (P2^3 == 0)
			cheatMap(Map[][], Play_x, Play_y)
			//Check if Game Over
		if (Map[Play_x][Play_y] == 'G')
			GameOver = true;
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
		if (P2^0 == 0) //Exit Button
			GameStart(map1[7][7], M1startX, M1startY);
		//victory
		else if (P2^1 == 0)
			GameStart(map2[7][7], M2startX, M2startY);
		//victory
		else if (P2^2 == 0)
			GameStart(map3[12][12], M3startX, M3startY);
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
	
