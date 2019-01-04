#include <avr/io.h>
#define SET_HI(port, bit) port |= (1<<bit)
#define SET_LO(port, bit) port &=~ (1<<bit)
#define READ_COM (PINC&(1<<5)) //пин данных 
#define SPULSE 100 //длинна стартового импульса
#define HPULSE 50  //длинна единици
#define LPULSE 25  //длинна нуля

void delay(int t)
{
	for(int i=0;i<t;i++)
	{
		for(int s=0;s<200;s++)//464-468uS (200 при 8000000мгц)
		{
		asm("nop");	
		}
	}
}
int delta(void){
    int i=0;

    while(!READ_COM);//ждем импульс

    for(i=0;i<255;i++){     //отмеряем длительность импульса
        if(!READ_COM) break;
        delay(1);
    }

    return i;
}

int main(void){
    int buf=0x00;     //буфер где полученные биты собераются в байт
    int flag=0x00;    //флаг стартовый импульс получен следующие три записывать в buf
    int counter=3;    //счетчик принятых битов
    int sendbit=0x00; //приемник
    
    DDRC=0x00;    //порт на вход
    PORTC=0xff;
    DDRD=0xFC;    //порт на выход два младших бита исключены иначе камень не стартует
    PORTD=0x00;   //порт в ноль
    DDRB=0xff;    //порт на выход
    PORTB=0x00;   //порт в ноль
    while(1){

        
       sendbit=delta(); //получаем длинну импульса

        
        if(counter<3){//пока не приняли три бита
            
            if((sendbit>=48 && sendbit<=52) && flag==1){
                 buf |= 1<<counter++; //если длинна импульса ровна еденице то записываем ее в переменную в бит номер counter, инкрементируем counter
             }
            
            if((sendbit>=23 && sendbit<=27) && flag==1) counter++;//если длинна импульса ровна нулю то просто инкрементируем counter
        }
        else{//если counter равен или больше 3(принято три бита) то выводим переменную в PORTD и сбрасываем флаг
            if(flag==1)
            {
                PORTD=buf<<2;
                flag=0;
                delay(100);
                PORTD=0x00;
                
            }
        }

        if(sendbit>=98 && sendbit<=102)flag=1, counter=0x00, buf=0x00;//если принят стартовый импульс устанавливаем флаг и чистим все остальное
        //PORTB^=(1<<0);//для отладки
        

    }

}

