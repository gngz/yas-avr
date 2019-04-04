#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <yas.h>
#include <uart.h>




int main(void)
{
    DDRB=0xFF;
    PORTB=0x00;
    
    yas_init();
    
    yas_uart_init(9600);
    yas_uart_sendstring("hello!");

    unsigned char str [20];
    SREG = 0;
    itoa(SREG,str,2);
    yas_uart_sendstring(str);


    sei();
 

    while(1){ 

       itoa(SREG,str,2);
    yas_uart_sendstring("SREG:");
    yas_uart_sendstring(str);
    yas_uart_sendchar('\n');
    _delay_ms(1000);

    }
  
    return 0;

}


