#ifndef _UART_H_
#define	_UART_H_ 1
//èíèöèèðóåì UART//
void uart_init( unsigned long baud )
{
unsigned int bauddiv = ((F_CPU+(baud*8L))/(baud*16L)-1);
UBRR0H = (unsigned char) (bauddiv>>8);
UBRR0L = (unsigned char) bauddiv;
UCSR0B = (1<<RXEN0)|(1<<RXCIE0)|(1<<TXEN0);
UCSR0C = (0<<UMSEL0)|(3<<UCSZ00);
		//UCSZ00 and UCSZ01 use 8 bit character size
}
//ÔÓÍÊÖÈß ÏÅÐÅÄÀ×È ÑÈÌÂÎËÀ
void tx( unsigned char data)
{
while( !( UCSR0A & (1<<UDRE0)) );
UDR0=data;
return;
}
//ÔÓÍÊÖÈß ÏÐÈÅÌÀ ÑÈÌÂÎËÀ
unsigned char rx(void)
{
while( !( UCSR0A & (1<<RXC0)) );
return(UDR0);
}

//ÔÓÍÊÖÈß ÏÅÐÅÄÀ×È ÑËÎÂÀ
void print(unsigned char *sw,int x)
{
  while (*sw) 
	{
	   
        tx(*sw++);
		
	}
	if(x==1) tx('\r');
return;	
}
//ÔÓÍÊÖÈß ÏÐÈÅÌÀ ÑËÎÂÀ
void scan(unsigned char *str,int x)
{
    char z=0;
	int i=0;
int t;
for(t=0;t<26;t++)str[t]='\0';
	while (z!='\r') 
	{
	z=rx();
	
	if(x==1) 
	{
	*str++=z;
	if(z=='\r')return;
	}
	else if(x==0)
	{
	if(z=='\r')return;
	*str++=z;
	}
	i=i+1;
	}
}
void clr(char str[20])
{
int i;
for(i=0;i<21;i++)str[i]='\0';
}
#endif /* _UART_H_ */
