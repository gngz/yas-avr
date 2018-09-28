
/***********************************************************************
Example - Blink an LED connected to PORTC_5
Note - Connect a LED at PORTC_5 and flash it at a particular interval.
Here LED is connected in sinking mode Logic1 -> LED Off
Logic0 -> LED On
************************************************************************/

#include<avr/io.h>       // Header file for basic avr input/output
#include<util/delay.h>   // header file for delay generation
#define BV(x) (1<<x)     // See text below

int help();

int main(void)
{
    DDRB=0xFF;      // PORTC declared as output
    PORTB=0xFF;     // PORTC is initially high to off the led initially
    while(1==1)     // infinite loop as 1 is always equals 1
    {
        PORTB=~(BV(5));     // led glow here, Making 5th bit of PORTC LOW
        _delay_ms(help());    // one second delay
        PORTB=BV(5);        // led do not glow here
        _delay_ms(help());
    }
    return 0;

}