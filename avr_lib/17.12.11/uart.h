#ifndef _UART_H_
#define	_UART_H_ 1
//èíèöèèðóåì UART//
void uart_init( unsigned long baud )
{
unsigned int bauddiv = ((F_CPU+(baud*8L))/(baud*16L)-1);
UBRRH = (unsigned char) (bauddiv>>8);
UBRRL = (unsigned char) bauddiv;
UCSRB = (1<<RXEN)|(1<<TXEN)|(1<<RXCIE);
UCSRC = (0<<UMSEL)|(3<<UCSZ0); 
}
//ÔÓÍÊÖÈß ÏÅÐÅÄÀ×È ÑÈÌÂÎËÀ
void tx( unsigned char data)
{
while( !( UCSRA & (1<<UDRE)) );
UDR=data;
return;
}
//ÔÓÍÊÖÈß ÏÐÈÅÌÀ ÑÈÌÂÎËÀ
unsigned char rx(void)
{
while( !( UCSRA & (1<<RXC)) );
return(255-UDR);
}

//ÔÓÍÊÖÈß ÏÅÐÅÄÀ×È ÑËÎÂÀ
void print(char *sw,int x)
{
  while (*sw) 
	{
	   
        tx(*sw++);
		
	}
	if(x==1) tx('\r');
return;	
}
//ÔÓÍÊÖÈß ÏÐÈÅÌÀ ÑËÎÂÀ
void scan(char *str,int x)
{
    char z=0;
	int i=0;
	while (z!=0xf2) 
	{
	z=rx();
	
	if(x==1) 
	{
	*str++=z;
	if(z==0xf2)return;
	}
	else if(x==0)
	{
	if(z==0xf2)return;
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
