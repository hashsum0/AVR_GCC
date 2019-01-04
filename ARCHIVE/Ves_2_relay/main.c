#include <avr/io.h>
#include "gpio_init.h"
#define on  |=
#define of  &=~
void delay(int t)
{
	for(int i=0;i<t;i++)
	{
		for(int s=0;s<1536;s++)
		{
		asm("nop");	
		}
	}
}
void main(void)
{
	
	DDRB=0xff;
    DDRC=0x00;
	PORTB=0x00;
	
	PORTB on (1<<5);
    PORTB on (1<<4);
    PORTB of (1<<2);
	while(1)
	{
		if(PINC&(1<<2))
        {
            PORTB on (1<<5);
            PORTB of (1<<4);
            PORTB on (1<<2);
        }
        else if(PINC&(1<<1))
        {
            PORTB on (1<<4);
            PORTB of (1<<5);
            PORTB on (1<<2);
        }
        else if(PINC&(1<<0)) //reset
        {
            PORTB on (1<<5);
            PORTB on (1<<4);
            PORTB of (1<<2);
        }
	}
}
