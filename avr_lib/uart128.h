#ifndef _UART_H_
#define	_UART_H_ 1
//���������� UART//
void uart_init( unsigned long baud )
{
unsigned int bauddiv = ((F_CPU+(baud*8L))/(baud*16L)-1);
UBRRH = (unsigned char) (bauddiv>>8);
UBRRL = (unsigned char) bauddiv;
UCSRA = (0<<RXC)|(1<<TXC)|(0<<UDRE)|(0<<FE)|(0<<DOR)|(0<<PE)|(0<<U2X)|(0<<MPCM); 
UCSRB = (1<<RXEN)|(1<<TXEN)|(0<<UCSZ2);
UCSRC = (0<<UMSEL)|(0<<UPM1)|(0<<UPM0)|(1<<USBS)|(1<<UCSZ1)|(1<<UCSZ0)|(0<<UCPOL); 
}
//������� �������� �������
void tx( unsigned char data)
{
while( !( UCSRA & (1<<UDRE)) );
UDR=data;
return;
}
//������� ������ �������
unsigned char rx(void)
{
while( !( UCSRA & (1<<RXC)) );
return(255-UDR);
}

//������� �������� �����
void print(char *sw,int x)
{
  while (*sw) 
	{
	   
        tx(*sw++);
		
	}
	if(x==1) tx('\r');
return;	
}
//������� ������ �����
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
