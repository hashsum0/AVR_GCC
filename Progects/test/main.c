#include <avr/io.h>


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


int main(void){
    
    DDRD=0xFC;    //порт на выход
    PORTD=0x00;   //порт в ноль
	
    while(1)
    {
        
            PORTD=0xff;
            delay(100);
            PORTD=0x00;
            delay(100);
        
        
        
	}

}


