#include <uart.h>
#include <avr/io.h>
#include <avr/interrupt.h>

void yas_uart_init(unsigned int baudrate) {

    baudrate  =F_CPU / 16 / baudrate - 1 ;
    UBRR0H = (baudrate>>8);
    UBRR0L = baudrate;                           
    UCSR0B|= (1<<TXEN0)|(1<<RXEN0);
    UCSR0C = (0<<USBS0)|(3<<UCSZ00);

}


void yas_uart_sendchar(char c) {
    while (!( UCSR0A & (1<<UDRE0)));
    UDR0 = c;
}

void yas_uart_sendstring(const char *string) {

    while(*string != 0x00)
    {
        yas_uart_sendchar(*string);
        string++;
    }

}

unsigned char yas_uart_readchar() {
    while ( !(UCSR0A & (1<<RXC0)));

    return UDR0;
}

char* yas_uart_readstring() {
    return 0;
}