/*
Programmer:Andrew Truong
Date Created: 5/10/2016
Date Last modified: 5/12/2016
File: Sound.C
*/
#include <reg932.h>

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

#define dur_time 700 //max delay

#ifdef SPEAKER
code int   period[] = { 0,B6,A6,G6,C7,0,F6,C6,D6,E6,B4,E4,A4,G5,D4,D5,C5,
						C4,G4,E5,0,0,0,0,0,0,0,0,Ab3,G3,B3,F5,D7,
						Bb6,Ab6,Gb6,Bb5,0,A5,B5,Db6,Eb6,Bb4,Eb4,Ab4,Ab5,Db4,Db5,F4,
						Bb3,Gb4,Eb5,0,0,0,0,0,0,0,0,F3,E3,A3,Gb5};

code char  notes[4][20] = {// Victory Fanfare
							11,11,11,11,17,14,11,14,11,31,48,31,48,45,0 ,0 ,0 ,0 ,0 ,0 ,     
							17,45,38,45,38,38,31,48,11,48,14,14,31,48,31,48,45,0 ,0 ,0 ,
							0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,
							17,45,31,45,38,38,31,48,31,45,39,39,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,};
code char  dur[4][20] = {	// Victory Fanfare
							16,16,16,16,16,16,16,16,16,16,16,16,24,8,32,0,0,0,0,0,
							16,16,16,16,16,16,16,16,16,16,16,16,24,8,32,0,0,0,0,0, 
							16,16,16,16,16,8,8,16,16,16,8,8,16,16,16,16,32,0,0,0,
							16,16,16,16,16,16,16,16,16,16,16,16,24,8,32,0,0,0,0,0,};

//need to define with sbit what speaker is, thought it was P1.7							
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
	P1.7=0;
	TF0=0;
	TL0=0x33
	TH0=0xFB
	TR0=1;
	while(TF0 != 1)
	{};
	TR0=0;
	TF0=0;
	P1.7=1;
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
	} while (j<end);
	return;
}

void finish(char n,char d){
#ifdef SPEAKER
	ET1=0;
	TR1=0;
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
#else
    sdelay(delay_t);
#endif

	return;
}		 

void sdelay(int time )
{
    unsigned int i;

    while( time-- > 0 ) {
        for( i=0 ; i<N_PAUSE ; i++ ) ;
    }
	return;
}
