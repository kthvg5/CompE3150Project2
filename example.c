


#include <reg932.h>
sbit SPKR		= P1^7;
sbit BLUE_LED	= P1^6;
sbit BLUE_SW	= P1^4;
/* Constants */
#define OSC_FREQ		7372800
#define ALLOFF         0x00
#define ALLON          0x0f
#define O_WIN          0x01
#define I_MASK         0x0f
#define N_FLASH        0x04
#define N_PAUSE        250 //(OSC_FREQ/29491)
#define MAX_LEVELS     32
#define INIT_LEVELS    0x08
#define MAX_DELAY      700 //(OSC_FREQ/10532)
#define TEMPO			(OSC_FREQ/204800)		/* Duration of a 64th note */
#define SPEAKER


#ifdef SPEAKER

    /* Speaker tone periods 									period[#]    */
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

/* Inlines */

#define writeP2(A)   P2 = ~( ( (A) << 4 ) & 0xf0 )
#define readP2()     ( (~P2) & I_MASK )
#define writeP0(A)   P0 = ~( ( (A) << 4 ) & 0xf0 )
#define readP0()     ( (~P0) & I_MASK )

/* function prototypes */
void start	(void);
void displ	(char n,char d);
char roll	(char);
char simon	(char);
char getval	(char);
char input	(void);
void sdelay	(int);
void win	(char b, char e);
void song	(char);
void play	(char n,char d);
char lock	(char level, char tries);
char lites	(char);
char music	(char);
extern void winlock (void);			// an external assembly routine


# ifdef SPEAKER
code int   period[] = { 0,B6,A6,G6,C7,0,F6,C6,D6,E6,B4,E4,A4,G5,D4,D5,C5,
						C4,G4,E5,0,0,0,0,0,0,0,0,Ab3,G3,B3,F5,D7,
						Bb6,Ab6,Gb6,Bb5,0,A5,B5,Db6,Eb6,Bb4,Eb4,Ab4,Ab5,Db4,Db5,F4,
						Bb3,Gb4,Eb5,0,0,0,0,0,0,0,0,F3,E3,A3,Gb5};
int       *p_per;
char    levels=0;

code char  notes[18][18] = {// ODE TO JOY
							19,19,31,13,13,31,19,15,16,16,15,19,19,15,15,0,0,0,
							19,19,31,13,13,31,19,15,16,16,15,19,15,16,16,0,0,0,
							15,15,19,16,15,19,31,19,16,15,19,31,19,15,16,15,18,0,
							19,19,31,13,13,31,19,15,16,16,15,19,15,16,16,0,0,0,
							// AMERICA THE BEAUTIFUL
							42,42,18,18,42,42,48,48,18,44,42,16,15,42,0,0,0,0,
							42,42,18,18,42,42,48,48,31,19,31,13,16,31,0,0,0,0,
							42,13,13,31,51,51,15,15,51,31,15,16,42,51,0,0,0,0,
							51,51,16,16,51,51,42,42,42,16,51,42,31,51,0,0,0,0,
							// MY COUNTRY TIS OF THEE
							16,16,15,10,16,15,19,19,31,19,15,16,15,16,10,16,0,0,
							13,13,13,13,31,19,31,31,31,31,19,15,0,0,0,0,0,0,
							19,31,19,15,16,19,31,13,38,31,19,15,16,0,0,0,0,0,
							// THIS OLD MAN
							13,19,13,13,19,13,38,13,31,19,15,19,31,0,0,0,0,0,
							19,31,13,16,16,16,16,16,15,19,31,13,0,0,0,0,0,0,
							13,15,15,31,19,15,16,0,0,0,0,0,0,0,0,0,0,0,
							// MEXICAN HAT DANCE
							7,39,7,38,45,38,31,19,31,16,0,0,0,0,0,0,0,0,
							12,42,16,15,19,31,13,38,36,13,0,0,0,0,0,0,0,0,
							36,38,36,13,63,13,19,51,19,16,0,0,0,0,0,0,0,0,
							7,39,7,8,7,36,38,13,31,0,0,0,0,0,0,0,0,0,};
code char  dur[18][18] = {	// ODE TO JOY
							16,16,16,16,16,16,16,16,16,16,16,16,24,8,32,0,0,0,
							16,16,16,16,16,16,16,16,16,16,16,16,24,8,32,0,0,0,
							16,16,16,16,16,8,8,16,16,16,8,8,16,16,16,16,32,0,
							16,16,16,16,16,16,16,16,16,16,16,16,24,8,32,0,0,0,
							// AMERICA THE BEAUTIFUL
							16,24,8,16,16,24,8,16,16,16,16,16,16,48,0,0,0,0,
							16,24,8,16,16,24,8,16,16,16,16,16,16,48,0,0,0,0,
							16,24,8,16,16,24,8,16,16,16,16,16,16,48,0,0,0,0,
							16,24,8,16,16,24,8,16,16,16,16,16,16,48,0,0,0,0,
							// MY COUNTRY TIS OF THEE
							16,16,16,24,8,16,16,16,16,24,8,16,16,16,16,48,0,0,
							16,16,16,24,8,16,16,16,16,24,8,16,0,0,0,0,0,0,
							16,8,8,8,8,24,8,16,8,8,16,16,48,0,0,0,0,0,
							// THIS OLD MAN
							8,8,16,8,8,16,8,8,8,8,8,8,8,0,0,0,0,0,
							4,4,8,8,4,4,8,4,4,4,4,16,0,0,0,0,0,0,
							8,8,8,8,8,8,16,0,0,0,0,0,0,0,0,0,0,0,
							// MEXICAN HAT DANCE
							4,4,4,4,4,4,4,4,4,12,0,0,0,0,0,0,0,0,
							4,4,4,4,4,4,4,4,4,12,0,0,0,0,0,0,0,0,
							4,4,4,4,4,4,4,4,4,12,0,0,0,0,0,0,0,0,
							4,4,4,4,4,4,4,4,12,0,0,0,0,0,0,0,0,0};



/*
* Interrupt Handler for Timer 1 (Generates sound)
*/
void clk( void ) interrupt 3 using 1
{
    TH1=-(*p_per)>>8;
    TL1=-(*p_per)&0x0ff;
    SPKR = ~SPKR;
}
# endif

/* Global variables */
unsigned int 	delay_t = MAX_DELAY;

/* Constant Arrays */
// Translates level value for some games
code char		trans[] = {0,8,16,0,24,0,0,0,32};
// Converts port inputs to sound and display values
code char		dicein[] = {0,8,4,12,2,10,30,20,6,14,16,22,18,24,26,28,
							0,1,3,13,9,11,31,21,7,15,17,23,19,25,27,29,
							5,40,36,44,34,42,62,52,38,46,48,54,50,56,58,60,
							5,33,35,45,41,43,63,53,39,47,49,55,51,57,59,61};
// Dice number display
code char		diceP0[] = {0,0,0,0,0,0,5,5,15,15};
code char		diceP2[] = {0,0,10,10,15,15,15,15,15,15};
// Converts display value to port values "P2(7:4):P0(7:4)"
code char		disp[] = {0,0x10,0x04,0x20,0x02,0x00,0x08,0x80,0x01,0x40,0x05,0x50,0x03,0x30,0x09,0x90,
						  0x0A,0xA0,0x0C,0xC0,0x07,0x70,0x0B,0xB0,0x0D,0xD0,0x0E,0xE0,0x0F,0xF0,0x06,0x60};


// Main Routine

void main( void )
{
    char    i,j;
    char    game,level,tries;
	unsigned int count;
    EA=1;

// Initialize ports
	P2M1=0;
	P1M1=0x2F&P1M1;
	P0M1=0;
	TMOD=0x11;

    start();
// Endless loop for main menu
	while(1)
	{
		do  // Main menu
		{
			writeP0(ALLON);
			BLUE_LED=0;
			sdelay(MAX_DELAY>>2);
			writeP0(ALLOFF);
			BLUE_LED=1;
			count=0;
			do
			{
				count++;
				game=readP0();
				if(BLUE_SW==0) game=16;
			} while(game==0 & count<65430);
			TL0=count&0xFF;
			TH0=count>>8;
			TR0=1;
			writeP0(game);
			sdelay(MAX_DELAY>>1);
// Execute roll game when blue_sw is pressed
			if(game==16)
			{
				do
				{
					writeP0(ALLON);
					writeP2(0x0E);
					BLUE_LED=0;
					sdelay(MAX_DELAY>>2);
					writeP0(ALLOFF);
					writeP2(ALLOFF);
					BLUE_LED=1;
					sdelay(MAX_DELAY>>2);
					writeP2(0x01);
					sdelay(MAX_DELAY>>2);
					writeP2(ALLOFF);
					count=0;
					i=0;
					do
					{
						count++;
						i=0;
						i=readP2();
						if(i!=0) i=i+16;		// Port2 on second and fourth lines of dicein[]
						if(BLUE_SW==0) i=i+32;	// SW5 shifts to third and fourth lines
						i=i+readP0();			// Port0 on first and third lines of dicein[]
						i=dicein[i];			// translates inputs to usable values for all routines
						if(i>1 && i<10)
						{
							i=roll(i);
						}
						if(i==1) count=65530;
					}while(count<65430);
				}while(i!=1);
				game=0;
			}
		}while(game==0);

// Sub-menu for level selection
		do
		{
			writeP2(ALLON);
			sdelay(MAX_DELAY>>2);
			writeP2(ALLOFF);
			sdelay(MAX_DELAY>>2);
			BLUE_LED=0;
			sdelay(MAX_DELAY>>2);
			BLUE_LED=1;
			count=0;
			do
			{
				count++;
				level=readP2();
				if(BLUE_SW==0)
				{
					game=0;
					level=16;
				}
			}while(level==0 & count<65430);
		}while(level==0);
		TL2=count&0xFF;
		TH2=count>>8;
		TCR20=0x01;
		writeP2(level);
		sdelay(MAX_DELAY);
		if(game!=0 & level!=0)
		{
			writeP0(ALLOFF);
			writeP2(ALLOFF);
			if(game==1)   // Simon
			{
				level=trans[level];
				level=simon(level);
				game=0;
				level=0;
			}
			if(game==2)  // Lock
			{
				level=trans[level];
				tries=level;
				j=0;
				do
				{
					if(j<6) // five rounds or less
					{
						sdelay(MAX_DELAY>>1);
						writeP0(diceP0[j]);  // display rounds won
						writeP2(diceP2[j]);
						BLUE_LED=(~j)&0x01;
						sdelay(MAX_DELAY>>1);
						writeP0(ALLOFF);
						writeP2(ALLOFF);
						BLUE_LED=1;
						level=lock(level,tries);  // tries=attempts possible
						tries=tries-(level>>3);   // reduce # of attempts with each round
						j++;
					}
					else if (j==6) // win lock after 6 rounds complete
					{
						level=0;
						win(11,14);
					}
				}while(level!=0);
				game=0;
			}
			if(game==4)  // Lights Off
			{
				level=trans[level];
				level=(level>>3)+2; // level sets possible number of LEDs changed
				j=lites(level);
			}
			if(game==8)  // Music
			{
				level=music(level);
				game=0;
			}
		}
	}
}




/* Functions */
// Start up light and sound display
void start(void)
{
    char    i,j,k;

    delay_t = MAX_DELAY>>2;

    for( i=0 ; i<N_FLASH ; i++ )
	{
    	for( j=1 ; j<8 ; j=j+2 )
		{
			k=j;
			if(j==5) k=9;
            displ( k,0 );
        }
    }
}

// Light LEDs and call sound function
// val=light and sound value
// dur=length of sound
void displ( char val,char dur )
{
	char i;
	bit j;

	i=disp[(val&0x1F)];
	writeP0(i&0x0f);
    writeP2(i>>4);
	i=(val&0x20)>>5;
	j=i;
	BLUE_LED=~(j);

#ifdef SPEAKER
    play( val,dur );
#else
    sdelay(delay_t);
#endif

    writeP0( ALLOFF );
	writeP2( ALLOFF );
    BLUE_LED=1;
}

// delays for time value
// used to allow sound to play
// or debounce switch presses
void sdelay(int time )
{
    unsigned int    i;

    while( time-- > 0 ) {
        for( i=0 ; i<N_PAUSE ; i++ ) ;
    }
}

// Roll game-displays value from 1 to in, when blue_sw pressed
char roll (char in)
{
	char i,j;
	writeP2(ALLOFF);
	i=0;
	sdelay(MAX_DELAY);
	while(i!=1)
	{
		do
		{
			j=BLUE_SW;
			i=readP2();
		}while(j!=0&&i!=1);

		if(j==0)
		{
			writeP0(ALLOFF);
			writeP2(ALLOFF);
			BLUE_LED=1;
			delay_t=MAX_DELAY>>2;
			for(j=0;j<N_FLASH;j++)
			{
				displ(O_WIN<<j,0);
			}
			j=getval(in);			// calls random # generator
			writeP0(diceP0[j]);		// displays number in dice format
			writeP2(diceP2[j]);
			BLUE_LED=(~j)&0x01;
		}
	}
	writeP0(ALLOFF);  // make sure all LEDs are off on exit
	writeP2(ALLOFF);
    BLUE_LED=1;
	return i;
}


// Simon game
// Level (8,16,24,32)=length of sequence to win
char simon (char level)
{
	char i,j,k,value;
	char pat[MAX_LEVELS];

	for(i=0;i<level;i++)
	{
		value=getval(4);
		if(value==3) value=8;  // random value 1,2,4 or 8
		pat[i]=dicein[value+16]; // convert to light and sound value
		displ(ALLOFF,0);
		for(j=0;j<=i;j++)
		{
			delay_t=delay_t>>1;
			displ(ALLOFF,0);
			delay_t=MAX_DELAY-(i*29);
			displ(pat[j],0);  // display pattern
		}
		for(j=0;j<=i;j++)
		{
			if(input()!=pat[j])  // read input and compare to pattern
			{
				delay_t=MAX_DELAY;
				for(k=0;k<N_FLASH;k++)
				{
					displ(29,0);   // lose if not equal
				}
				level=0;
			}
		}

	}
	if(level!=0)
		{
			sdelay(MAX_DELAY>>1);
			win(0,level>>3);  // play win song if complete pattern entered
		}
	return level;
}


// Lock game-enter correct combination to win
// level sets 4 or 9 digits and user feedback
// tries=the maximum number of attempt before lose
char lock (char level, char tries)
{
	char i,j,num,res;
	int cin;
	char comb[9];
	res=(level>>3)&0x01;
	for(i=0;i<9;i++)	// clear combination
	{
		comb[i]=0;
	}
	if(level<20)	// set controls based on level input
	{
		num=4;		// combination digits 1,3,7,9 (corners) only
	}
	else
	{
		num=9;		// combination uses all nine digits
	}
	cin=0;
	do
	{
		for(i=0;i<4;i++)	   // input four digit combination
		{
			if(comb[i]==0)
			{
				j=getval(num);  // random number 1 to num
				if(num==4)
				{
					if(j==3) j=8;
					comb[i]=dicein[j+16];  // convert to light and sound value
				}							// 1, 3, 7, or 9 only
				else
				{
					comb[i]=j;		// value is from 1 to 9
				}
			}
			delay_t=MAX_DELAY;
			j=input();   // input from user compared to combination
			if(j==comb[i]) cin=cin|0x10;  // "1"s in cin equal correct digits
			cin=cin>>1;
		}
		tries--;
		sdelay(MAX_DELAY);
		if(res==0)		// count number of correct digits and display
		{
			j=0;
			for(i=0;i<4;i++)
			{
				j=j+(cin&0x01);
				cin=cin>>1;
			}
			if(j==4)
			{
				winlock();
				num=0;
				tries=1;
			}
			else
			{
				writeP0(diceP0[j]);
				writeP2(diceP2[j]);
				BLUE_LED=(~j)&0x01;
#ifdef SPEAKER
				delay_t=MAX_DELAY<<2;
				play(29,0);
#else
				sdelay(MAX_DELAY<<2);
#endif
				writeP0(ALLOFF);
				writeP2(ALLOFF);
				BLUE_LED=1;

			}
		}
		else		// or display the correct digit locations
		{
			if(cin==0x0F)
			{
				winlock();
				num=0;
				tries=1;
			}
			else
			{
				writeP2(cin);
#ifdef SPEAKER
				delay_t=MAX_DELAY<<2;
				play(29,0);
#else
				sdelay(MAX_DELAY<<2);
#endif
				writeP2(ALLOFF);
			}
		}


	}while(tries>0&&num!=0);
	if(tries==0)  // out of attempts (lose!)
	{
		delay_t=MAX_DELAY>>1;
		for(i=0;i<8;i++)
		{
			writeP2(ALLOFF);
			BLUE_LED=1;
			writeP0(ALLON);
			play(1,0);
			writeP2(ALLON);
			BLUE_LED=0;
			writeP0(ALLOFF);
			play(15,0);
		}
		writeP2(ALLOFF);
		BLUE_LED=1;
		writeP0(ALLOFF);
		delay_t=MAX_DELAY;
		level=0;
	}
	return level;
}


// Lites game-turn off all the LEDs to win
char lites(char level)
{
	char sw[9][4];
	char alt[3];
	char i,j,k,m,port,sw_num;
	unsigned int val1,val2;
	bit b;

// init switch (sw) array
	for (i=0;i<9;i++)
	{
		sw[i][0]=0;
		sw[i][1]=0;
		sw[i][2]=0;
		sw[i][3]=0;
	}


	sw_num=0;
	port=TH0;						// random pattern of lights to start
	BLUE_LED=TL0&0x01;

	do
	{
		writeP0(port&0x0F);			// update pattern of lights
		writeP2(port>>4);
		do
		{
			i=0;
			i=readP2();
			if(i!=0) i=i+16;		// Port2 on second and fourth lines of dicein[]
			if(BLUE_SW==0) i=i+32;	// SW5 shifts to third and fourth lines
			i=i+readP0();			// Port0 on first and third lines of dicein[]
			i=dicein[i];			// translates inputs to usable values for all routines
		}while(i==0 || i>9);
		sdelay(MAX_DELAY);
		i--;
		if((sw[i][3]&(char)0x80)==0) 			// check for switch values
		{
			sw_num++;
			val1=TH0<<8; 			// if switch does have a value yet
			val1=val1|TL0;	 		// then choose two random 16-bit values
			val2=TH2<<8;			// to create switch values
			val2=val2|TL2;
			for(j=0;j<level;j++)	// level determines how many LEDs
			{						// are changed by a switch.
				k=val2&0x0F;
				k=(k*9)>>4;			// convert 4-bit random value to 1-9.
				k++;
				k=disp[k];			// convert 1-9 to an LED location
				if(k==(char)0xFF)	// if BLUE_LED choosen
				{					// then put the random action in
					m=val1&0x03;	// sw[i][3] and set value set bit
					m=m|0x80;		// 0x00 ON, 0x01 Nothing
					sw[i][3]=sw[i][3]|m;		// 0x10 OFF, 0x11 Toggle
				}
				else
				{
					m=val1&0x03;
					if(m==0x03) k=0x00; // nothing affected
					sw[i][m]=sw[i][m]|k;
					sw[i][3]=sw[i][3]|0x80;
				}
				val2=val2>>2;
				val1=val1>>2;
			}
		}
		if(sw_num==(char)0x06)
		{
			for(j=0;j<3;j++)
			{
				alt[j]=0;
			}
			for(j=0;j<9;j++)
			{
				alt[0]=alt[0]|sw[j][0];
				alt[1]=alt[1]|sw[j][1];
				alt[2]=alt[2]|sw[j][2];
			}
			k=2;
			for(j=0;j<9;j++)
			{
				if((sw[j][3]&0x80)==0)
				{
					sw[j][k]=~(alt[k]);
					sw[j][3]=((k+1)|0x80);
					k--;
					if(k<0) k=2;
				}
			}


		}
		j=sw[i][0];		// "1"s turn on LEDs
		port=port|j;
		j=sw[i][2];		// "1"s toggle LEDs
		port=port^j;
		j=sw[i][1];		// "1"s turn off LEDs
		j=~j;
		port=port&j;
		j=sw[i][3];
		b=j&0x01;		// Blue LED "00" LED ON, "01" Nothing, "10" LED OFF, "11" Toggle LED
		BLUE_LED=BLUE_LED&b;
		j=j>>1;
		b=j&0x01;
		BLUE_LED=BLUE_LED^b;
	}while(port!=0||BLUE_LED==0);
	win(14,(level+12));  // play win song when all LEDs off
	return 0;
}



/* Uses timer0 to create a random value from 1 to seed (max 16)
	Variables are char to simplify machine code.          */
char getval(char seed)
{
	char val;

	val=TL0&0x0F;			// reads the lower four bits of timer0 (0 to 15)
	val=(val*seed)>>4;		// multiplies by seed and divides by 16 (0 to seed-1)
	val++;					// add one (1 to seed)

	return val;
}


/* Waits for a switch to be pressed and returns the value from dicein[]  */
char input(void)
{
	char i=0,j=0;

	writeP2(ALLOFF);
	writeP0(ALLOFF);
	do
	{

		i=0;
		i=readP2();
		if(i!=0) i=i+16;		// Port2 on second and fourth lines of dicein[]
		if(BLUE_SW==0) i=i+32;	// SW5 shifts to third and fourth lines
		i=i+readP0();			// Port0 on first and third lines of dicein[]
		i=dicein[i];			// translates inputs to usable values for all routines
	}while(i==0);		// wait for a key press
	j=i;
    if(j==5) j=32;
	displ(j,0);					// feedback to user and debounces

	return i;
}


// Music routine-plays on of three songs or becomes keyboard
char music(char in)
{
	char i,k,val;
	bit j;

	if(in==1)
	{
		win(0,4);	// ODE TO JOY
	}
	if(in==2)
	{
		win(4,8);	// AMERICA THE BEAUTIFUL
	}
	if(in==4)
	{
		win(8,11);  // MY COUNTRY TIS OF THEE
	}
	if(in==8)
	{
		while(1)	// No exit from this routine
		{			// Turn board off to restart
		do
		{

			i=0;
			i=readP2();
			if(i!=0) i=i+16;
			if(BLUE_SW==0) i=i+32;
			i=i+readP0();
			i=dicein[i];	// convert to light and sound value
		}while(i==0);		// wait for a key press
		val=i;
		k=disp[(val&0x1F)];	// Turn on LEDs
		writeP0(k&0x0f);
    	writeP2(k>>4);
		k=(val&0x20)>>5;
		j=k;
		BLUE_LED=~(j);

  		p_per = &period[val];
    	if( *p_per != 0 )	// Start note playing
		{
	        TH1=-(*p_per)>>8;
	        TL1=-(*p_per)&0x0ff;
	        TR1=1;
	        ET1=1;
    	}
		do
		{
			i=0;
			i=readP2();
			if(i!=0) i=i+16;
			if(BLUE_SW==0) i=i+32;
			i=i+readP0();
			i=dicein[i];
		}while(val==i);		// hold note while key is pressed

    	writeP0( ALLOFF );  // Turn LEDs off
		writeP2( ALLOFF );
    	BLUE_LED=1;

		ET1=0;				// Turn off note
    	TR1=0;
    	SPKR = 1;

		}
	}
	in=0;
	return in;
}



#ifdef SPEAKER
// Win song routine
// begin=notes and dur array row for beginning of song
// end=notes and dur array row for end of song
void win( char begin, char end )
{
	char n, d;
	unsigned int i,j;

	i=0;
	j=begin;
	do
	{
		n=notes[j][i];  // read next note and duration
		d=dur[j][i];
		do
		{
			displ(n,d);  // use displ routine to play note and light LEDs
			i++;
			n=notes[j][i];  // repeat until dur=0 (indicates end of row (phrase))
			d=dur[j][i];
		} while (d!=0);
	i=0;
	j++;
	} while (j<end);

}


// Play routine-sets p_per value used by timer1 interrupt
// n used to read p_per value
// d used to set duration of note
void play(char n,char d)
{
	int dur_time;
	int t;
	if (d==0)
	{
		dur_time=delay_t; // delay_t is a global variable used by simon
		t=0;
	}
	else
	{
		dur_time=TEMPO*d; // TEMPO defines speed of all songs
		t=20;	     	  // t=20 puts a small delay between notes
	}

  	p_per = &period[n];

    if( *p_per != 0 ) {
        /* Enable timer */
        TH1=-(*p_per)>>8;
        TL1=-(*p_per)&0x0ff;
        TR1=1;
        ET1=1;
    }

    sdelay(dur_time);

    /* Disable timer */
    ET1=0;
    TR1=0;



	if(t!=0) sdelay(t);
}

#endif
