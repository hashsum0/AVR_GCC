#include <avr/io.h>
#define sbi(port, bit) port |= (1<<bit)
#define cbi(port, bit) port &=~ (1<<bit)


void delay(int t)
{
	for(int i=0;i<t;i++)
	{
		for(int s=0;s<227;s++)//464-468uS (200 при 8000000мгц)
		{
		asm("nop");	
		}
	}
}

void startbit(void)
{
        sbi(PORTB,0);
        delay(5);
        cbi(PORTB,0);
        delay(5);
        sbi(PORTB,0);
        delay(100);
        cbi(PORTB,0);
        delay(40);         
}
void lobit(void)
{
    sbi(PORTB,0);
    delay(25);
    cbi(PORTB,0);
    delay(40);     
}
void hibit(void)
{
    sbi(PORTB,0);
    delay(50);
    cbi(PORTB,0);
    delay(40);     
}
void stopbit(void)
{
    sbi(PORTB,0);
    cbi(PORTB,0);
    delay(200);
}
int main(void){
    
    DDRB=0xFF;    //порт на выход
    PORTB=0x00;   //порт в ноль
	
    while(1)
    {
        
            startbit();
            lobit();
            hibit();
            hibit();
            
        
        
        
	}

}


