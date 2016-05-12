#include<reg932.h>
#include<stdlib.h>
#include "maps.h"
#include "uart.h"


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
sbit SW7 = P2 ^ 1;
sbit SW8 = P0 ^ 3;
sbit SW9 = P2 ^ 2;

void delay (long x);
void cheatMap(/*const*/ char map_array[7][7], /*const*/ unsigned char arr_x, /*const*/ unsigned char arr_y);
void Redraw_Map(unsigned char Play_x, unsigned char Play_y, /*const*/ char Map[7][7]);
char Up(unsigned char Play_x, unsigned char Play_y, /*const*/ char Map[7][7]);
char Down(unsigned char Play_x, unsigned char Play_y, /*const*/ char Map[7][7]);
char Left(unsigned char Play_x, unsigned char Play_y, /*const*/ char Map[7][7]);
char Right(unsigned char Play_x, unsigned char Play_y, /*const*/ char Map[7][7]);
char GameStart(/*const*/ char Map[7][7], /*const*/ unsigned char Start_x, /*const*/ unsigned char Start_y);
void playMenu();
void clearGame();

//Looping Code for playing the game
void main(void)
{
	P0M1 = 0;
	P1M1 = 0;
	P2M1 = 0;
	P3M1 = 0;

	uart_init();
	
	while (1)
	{
		playMenu();
		clearGame();
	}

	return;
}	

/*void delay(long x)
{
	long i = 0;
	for (i; i<x; i++);
}*/

void cheatMap(/*const*/ char map_array[7][7], unsigned char arr_x, unsigned char arr_y) //rename map_array to group code name for the map array
{
	unsigned char i;
	unsigned char j;
	for (i = 0; i < arr_x; i++)
	{

		for (j = 0; j < arr_y; j++)
		{
			uart_transmit(map_array[j][i]);
		}
		uart_transmit('\n');
		uart_transmit('\r');//I think this will work?
	}
	return;
}

void Redraw_Map(unsigned char Play_x, unsigned char Play_y, /*const*/ char Map[7][7])
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
			delay(10000);
			LED1 = 1;
			delay(10000);
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
			delay(10000);
			LED2 = 1;
			delay(10000);
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
			delay(10000);
			LED3 = 1;
			delay(10000);
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
			delay(10000);
			LED4 = 1;
			delay(10000);
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
			delay(10000);
			LED5 = 1;
			delay(10000);
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
			delay(10000);
			LED6 = 1;
			delay(10000);
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
			delay(10000);
			LED7 = 1;
			delay(10000);
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
			delay(10000);
			LED8 = 1;
			delay(10000);
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
			delay(10000);
			LED9 = 1;
			delay(10000);
		}
	}
	else //Open
		LED9 = 1;

	return;
}
//Button Actions
//Up button
char Up(unsigned char Play_x, unsigned char Play_y, /*const*/ char Map[7][7]) {
	if (Map[Play_x][Play_y - 1] != 'W')
		Play_y -= 1;
	Redraw_Map(Play_x, Play_y, Map);
	return Play_y;
}

//Down
char Down(unsigned char Play_x, unsigned char Play_y, /*const*/ char Map[7][7]) {
	if (Map[Play_x][Play_y + 1] != 'W')
		Play_y += 1;
	Redraw_Map(Play_x, Play_y, Map);
	return Play_y;
}

//Right 
char Right(unsigned char Play_x, unsigned char Play_y, /*const*/ char Map[7][7]) {
	if (Map[Play_x + 1][Play_y] != 'W')
		Play_x += 1;
	Redraw_Map(Play_x, Play_y, Map);
	return Play_x;
}

//Left 
char Left(unsigned char Play_x, unsigned char Play_y, /*const*/ char Map[7][7]) {
	if (Map[Play_x - 1][Play_y] != 'W')
		Play_x -= 1;
	Redraw_Map(Play_x, Play_y, Map);
	return Play_x;
}
//Check if Player is at goal

char GameStart(/*const*/ char Map[7][7], /*const*/ unsigned char Start_x, /*const*/ unsigned char Start_y) {
	unsigned char GameOver = 0; //reset every new game
	unsigned char Play_x = Start_x;	//Load starting positions
	unsigned char Play_y = Start_y;
	unsigned char i = 0;
	unsigned char k = 0;

	//to transmit a number, use value+48

	uart_transmit(Play_x+48);
	uart_transmit('\n');
	uart_transmit('\r');
	uart_transmit(Play_y+48);
	uart_transmit('\n');
	uart_transmit('\r');

	Redraw_Map(Play_x, Play_y, Map);

	while (GameOver == 0) 
	{ //This loop plays the game until finished
		while (SW1 == 0 || SW3 == 0 || SW2 == 0 || SW8 == 0 || SW4 == 0 || SW6 == 0) 
		{ //Check if any input
			//Nothing to do here
		}

		delay(10);

		//waiting for input
		if (SW1 == 0) //Exit Button
			GameOver = 1;
		else if (SW5 == 0) // Help Button
			;//Help(Play_x, Play_y, Map[][]);
		else if (SW2 == 0)
			Play_y = Up(Play_x, Play_y, Map);
		else if (SW8 == 0)
			Play_y = Down(Play_x, Play_y, Map);
		else if (SW4 == 0)
			Play_x = Left(Play_x, Play_y, Map);
		else if (SW6 == 0)
			Play_x = Right(Play_x, Play_y, Map);
		else if (SW3 == 0)
			cheatMap(Map, 7, 7);
		//Check if Game Over
		if (Map[Play_x][Play_y] == 'G')
			GameOver = 1;
	}
	return GameOver;
}

void playMenu()
{
	char reset = 0;
	
	char* title = "Simon's A-MAZE-ing Adventures!";
	char* star_bar = "*********************************";
	char* menu1 = "Please select difficulty level: \n";
	char* menu2 = "1) Easy          2) Medium          3) Hard \n";

	unsigned char i = 0;
	while (star_bar[i] != '\0')
	{
		uart_transmit(star_bar[i]);
		i++;
	}
	uart_transmit('\n');
	uart_transmit('\r');
	i = 0;
	while (title[i] != '\0')
	{
		uart_transmit(title[i]);
		i++;
	}
	uart_transmit('\n');
	uart_transmit('\r');
	i = 0;
	while (star_bar[i] != '\0')
	{
		uart_transmit(star_bar[i]);
		i++;
	}
	uart_transmit('\n');
	uart_transmit('\r');
	uart_transmit('\n');
	uart_transmit('\r');
	i = 0;
	while (menu1[i] != '\0')
	{
		uart_transmit(menu1[i]);
		i++;
	}
	uart_transmit('\n');
	uart_transmit('\r');
	i = 0;
	while (menu2[i] != '\0')
	{
		uart_transmit(menu2[i]);
		i++;
	}
	uart_transmit('\n');
	uart_transmit('\r');
	i = 0;

	while (reset == 0)
	{
		if (SW3 == 0)
			reset = GameStart(map1, 2, 1); //fix valuse to actual variables here
		//victory
		/*else if (SW7 == 0)
			//GameStart(&(&map2[0][0]), M2startX, M2startY);
		//victory
		else if (SW9 == 0)*/
			//GameStart(&(&map3[0][0]), M3startX, M3startY);
		//victory
	}

	return;
}

void clearGame()
{
	LED1 = 1;
	LED2 = 1;
	LED3 = 1;
	LED4 = 1;
	LED5 = 1;
	LED6 = 1;
	LED7 = 1;
	LED8 = 1;
	LED9 = 1;

	return;
}

