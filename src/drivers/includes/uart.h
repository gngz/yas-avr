#ifndef _YAS_UART_H_
#define _YAS_UART_H_

void yas_uart_init(unsigned int baudrate);
void yas_uart_sendchar(char c);
void yas_uart_sendstring(const char *string);
unsigned char yas_uart_readchar();
char* yas_uart_readstring();

#endif