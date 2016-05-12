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

sbit SPEAK = P1 ^ 7;

void delay (long x);
void cheatMap(/*const*/ char map_array[12][12], /*const*/ unsigned char arr_x, /*const*/ unsigned char arr_y);
void Redraw_Map(unsigned char Play_x, unsigned char Play_y, /*const*/ char Map[12][12]);
char Up(unsigned char Play_x, unsigned char Play_y, /*const*/ char Map[12][12]);
char Down(unsigned char Play_x, unsigned char Play_y, /*const*/ char Map[12][12]);
char Left(unsigned char Play_x, unsigned char Play_y, /*const*/ char Map[12][12]);
char Right(unsigned char Play_x, unsigned char Play_y, /*const*/ char Map[12][12]);
char GameStart(/*const*/ char Map[12][12], /*const*/ unsigned char Start_x, /*const*/ unsigned char Start_y);
void playMenu();
void clearGame();
void wallHit(void);
void Delay250HZ(void);
void win(void);
void finish(char n, char d);
void finish(char n, char d);
void sdelay(int time);


//Looping Code for playing the game
void main(void)
{
	P0M1 = 0;
	P1M1 = 0;
	P2M1 = 0;
	P3M1 = 0;
	TMOD = 0x11;

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

void cheatMap(/*const*/ char map_array[12][12], unsigned char arr_x, unsigned char arr_y) //rename map_array to group code name for the map array
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

void Redraw_Map(unsigned char Play_x, unsigned char Play_y, /*const*/ char Map[12][12])
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
char Up(unsigned char Play_x, unsigned char Play_y, /*const*/ char Map[12][12]) {
	if (Map[Play_x][Play_y - 1] != 'W')
		Play_y -= 1;
	else
		wallHit();
	Redraw_Map(Play_x, Play_y, Map);
	return Play_y;
}

//Down
char Down(unsigned char Play_x, unsigned char Play_y, /*const*/ char Map[12][12]) {
	if (Map[Play_x][Play_y + 1] != 'W')
		Play_y += 1;
	else
		wallHit();
	Redraw_Map(Play_x, Play_y, Map);
	return Play_y;
}

//Right 
char Right(unsigned char Play_x, unsigned char Play_y, /*const*/ char Map[12][12]) {
	if (Map[Play_x + 1][Play_y] != 'W')
		Play_x += 1;
	else
		wallHit();
	Redraw_Map(Play_x, Play_y, Map);
	return Play_x;
}

//Left 
char Left(unsigned char Play_x, unsigned char Play_y, /*const*/ char Map[12][12]) {
	if (Map[Play_x - 1][Play_y] != 'W')
		Play_x -= 1;
	else
		wallHit();
	Redraw_Map(Play_x, Play_y, Map);
	return Play_x;
}
//Check if Player is at goal

char GameStart(/*const*/ char Map[12][12], /*const*/ unsigned char Start_x, /*const*/ unsigned char Start_y) {
	unsigned char GameOver = 0; //reset every new game
	unsigned char Play_x = Start_x;	//Load starting positions
	unsigned char Play_y = Start_y;
	unsigned char i = 0;
	unsigned char k = 0;

	//to transmit a number, use value+48

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
			cheatMap(Map, 12, 12);
		//Check if Game Over
		if (Map[Play_x][Play_y] == 'G'){
			GameOver = 1;
			//win();
		}
			
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
		else if (SW7 == 0)
			reset = GameStart(map2, 1, 1);
		//victory
		else if (SW9 == 0)
			reset = GameStart(map2, 10, 2);
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

//SOUND STUFF
#define SPEAKER

#define OSC_FREQ 73732800 
#define N_PAUSE 250 
#define delay_t 700 //max delay
#define TEMPO			(OSC_FREQ/204800)		/* Duration of a 64th note */

#ifdef SPEAKER
#define E3				((OSC_FREQ/4)/164.81)  // P1,P2-allon   	(61)
#define F3				((OSC_FREQ/4)/174.61)  // P1,P0-allon		(60)
#define G3				((OSC_FREQ/4)/196.00)  // P2-allon			(29)
#define Ab3				((OSC_FREQ/4)/207.65)  // P0-allon			(28)
#define A3				((OSC_FREQ/4)/220.00)  // P1,P0-Yel,Amb		(62)
#define Bb3				((OSC_FREQ/4)/233.08)  // P1,P2-Yel,Grn		(49)
#define B3				((OSC_FREQ/4)/246.94)  // P0-Yel,Amb		(30)
#define C4				((OSC_FREQ/4)/261.63)  // P2-Yel,Grn		(17)
#define Db4				((OSC_FREQ/4)/277.18)  // P1,P0-Red,Grn		(46)
#define D4				((OSC_FREQ/4)/293.67)  // P0-Red,Grn		(14)
#define Eb4				((OSC_FREQ/4)/311.13)  // P1,P2-Red,Amb		(43)
#define E4				((OSC_FREQ/4)/329.63)  // P2-Red,Amb		(11)
#define F4				((OSC_FREQ/4)/349.23)  // P1,P0-Yel,Grn		(48)
#define Gb4				((OSC_FREQ/4)/369.99)  // P1,P0-Amb,Grn		(50)
#define G4				((OSC_FREQ/4)/392.00)  // P0-Amb,Grn		(18)
#define Ab4				((OSC_FREQ/4)/415.30)  // P1,P0-Red,Yel		(44)
#define A4				((OSC_FREQ/4)/440.00)  // P0-Red,Yel		(12)
#define Bb4				((OSC_FREQ/4)/466.16)  // P1,P0-Red,Amb		(42)
#define B4				((OSC_FREQ/4)/493.88)  // P0-Red,Amb		(10)
#define C5				((OSC_FREQ/4)/523.25)  // P0-Yel,Grn		(16)
#define Db5				((OSC_FREQ/4)/554.37)  // P1, P2-Red,Grn	(47)
#define D5				((OSC_FREQ/4)/587.33)  // P2-Red,Grn		(15)
#define Eb5				((OSC_FREQ/4)/622.25)  // P1,P2-Amb,Grn		(51)
#define E5				((OSC_FREQ/4)/659.26)  // P2-Amb,Grn		(19)
#define F5				((OSC_FREQ/4)/698.46)  // P2-Yel,Amb		(31)
#define Gb5				((OSC_FREQ/4)/739.99)  // P1,P2-Yel,Amb		(63)
#define G5				((OSC_FREQ/4)/783.99)  // P2-Red,Yel		(13)
#define Ab5				((OSC_FREQ/4)/830.61)  // P1,P2-Red,Yel 	(45)	
#define A5				((OSC_FREQ/4)/880.00)  // P1,P0-Grn			(38)
#define Bb5				((OSC_FREQ/4)/932.33)  // P1,P0-Yel			(36)
#define B5				((OSC_FREQ/4)/987.77)  // P1,P2-Grn			(39)
#define C6				((OSC_FREQ/4)/1046.5)  // P2-Grn (per_08)	(7)
#define Db6				((OSC_FREQ/4)/1108.7)  // P1,P0-Red			(40)
#define D6				((OSC_FREQ/4)/1174.7)  // P0-Red			(8)
#define Eb6				((OSC_FREQ/4)/1244.5)  // P1,P2-Amb			(41)
#define E6				((OSC_FREQ/4)/1318.5)  // P2-Amb (per_04)	(9)
#define F6				((OSC_FREQ/4)/1396.9)  // P0-Grn			(6)
#define Gb6				((OSC_FREQ/4)/1480.0)  // P1,P2-Yel			(35)
#define G6				((OSC_FREQ/4)/1568.0)  // P2-Yel (per_02)	(3)
#define Ab6				((OSC_FREQ/4)/1661.2)  // P1,P0-Amb			(34)
#define A6				((OSC_FREQ/4)/1760.0)  // P0-Amb			(2)
#define Bb6				((OSC_FREQ/4)/1864.7)  // P1,P2-Red			(33)
#define B6				((OSC_FREQ/4)/1975.5)  // P2-Red (per_01)	(1)
#define C7				((OSC_FREQ/4)/2093.0)  // P0-Yel			(4)
#define D7				((OSC_FREQ/4)/2349.3)  // P1				(32)
#endif

#ifdef SPEAKER
code int   period[] = { 0, B6, A6, G6, C7, 0, F6, C6, D6, E6, B4, E4, A4, G5, D4, D5, C5,
C4, G4, E5, 0, 0, 0, 0, 0, 0, 0, 0, Ab3, G3, B3, F5, D7,
Bb6, Ab6, Gb6, Bb5, 0, A5, B5, Db6, Eb6, Bb4, Eb4, Ab4, Ab5, Db4, Db5, F4,
Bb3, Gb4, Eb5, 0, 0, 0, 0, 0, 0, 0, 0, F3, E3, A3, Gb5 };

int* pointer;

code char  notes[4][20] = {// Victory Fanfare
	11, 11, 11, 11, 17, 14, 11, 14, 11, 31, 48, 31, 48, 45, 0, 0, 0, 0, 0, 0,
	17, 45, 38, 45, 38, 38, 31, 48, 11, 48, 14, 14, 31, 48, 31, 48, 45, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	17, 45, 31, 45, 38, 38, 31, 48, 31, 45, 39, 39, 0, 0, 0, 0, 0, 0, 0, 0, };
code char  dur[4][20] = {	// Victory Fanfare
	16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 24, 8, 32, 0, 0, 0, 0, 0,
	16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 24, 8, 32, 0, 0, 0, 0, 0,
	16, 16, 16, 16, 16, 8, 8, 16, 16, 16, 8, 8, 16, 16, 16, 16, 32, 0, 0, 0,
	16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 24, 8, 32, 0, 0, 0, 0, 0, };

void clk(void) interrupt 3 using 1
{
	TH1 = -(*pointer) >> 8;
	TL1 = -(*pointer) & 0x0ff;
	SPEAK = ~SPEAK;
}
#endif

void wallHit(void)
{
	ET0=0;//sets timer on
	pointer = 9;
	TF0=0;
	Delay250HZ();
	
	pointer = 61;
	TF0=0;
	Delay250HZ();
	ET0=1;
	return;
}

void Delay250HZ(void)
{
	SPEAK=0;
	TF0=0;
	TL0=0x33;
	TH0=0xFB;
	TR0=1;
	while(TF0 != 1)
	{};
	TR0=0;
	TF0=0;
	SPEAK=1;
	return;
}

void win(void)
{
	char n, d;
	unsigned int i,j;
	
	i=0;
	j=0;
	
	do 
	{
		n=notes[j][i];  // read next note and duration
		d=dur[j][i];
		do 
		{
			finish(n,d);  // use displ routine to play note and light LEDs
			i++;
			n=notes[j][i];  // repeat until dur=0 (indicates end of row (phrase))
			d=dur[j][i];
		} while (d!=0);
	i=0;
	j++;
	} while (j < 4);
	return;
}

#ifdef SPEAKER
void finish(char n,char d)
{
    //ET1=0;
	//TR1=0;
	int dur_time;
	int t;
	if (d==0) //boop
	{
		dur_time=delay_t; // delay_t is a global variable used by simon
		t=0;
	}
	else
	{
		dur_time=TEMPO*d; // TEMPO defines speed of all songs
		t=20;	     	  // t=20 puts a small delay between notes
	}

  	pointer = &period[n];

    if( *pointer != 0 ) {
        /* Enable timer */
        TH1=-(*pointer)>>8;
        TL1=-(*pointer)&0x0ff;
        TR1=0;
        ET1=0;
    }

    sdelay(dur_time);

    /* Disable timer */
    ET1=1;
    TR1=1;

	if(t!=0) sdelay(t);

	return;
}
#endif

void sdelay(int time )
{
    unsigned int i;

    while( time-- > 0 ) {
        for( i=0 ; i<N_PAUSE ; i++ ) ;
    }
	return;
}
