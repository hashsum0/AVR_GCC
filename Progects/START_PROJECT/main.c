#include <avr/io.h>
#define setbit(port,bit)  port|=(1<<bit)
#define clrbit(port,bit)  port&=~(1<<bit)
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
	DDRD=0xFF;
	PORTD=0x00;
	while(1)
	{
		setbit(PORTD,0);
		delay(1000);
		clrbit(PORTD,0);
		delay(1000);
		
	}
}
