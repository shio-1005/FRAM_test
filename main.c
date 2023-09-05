
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <spi.h>
#include <fram.h>


// CONFIG1
#pragma config FOSC  = HS        // Oscillator Selection bits (HS oscillator: High-speed crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE  = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP    = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD   = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown Out Reset Selection bits (BOR enabled)
#pragma config IESO  = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP   = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR21V   // Brown-out Reset Selection bit (Brown-out Reset set to 2.1V)
#pragma config WRT   = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#define _XTAL_FREQ      20000000

/*Prtotype*/
void CONFIG();

char end_flag = 0;
char rx_status;
char rx_int;
char filt;
char data[8] = {0b00000001,0b00000010,0b00000011,0b00000100,0b00000101,0b00000110,0b00000111,0b00001000};



void main(void)
{
    
    CONFIG();
    __delay_ms(100);
    
    
   
   while(1)
   {
        Wren();
        WRITE(0b00000010, 0b00000000, &data[0], 8);
        __delay_us(50);
        READ(0b00000010, 0b00000000, 8);
        __delay_us(50);
        
        
        
   }
}

void CONFIG()
{
    OSCCON = 0b01101000;
    ANSEL  = 0b00000000;
    ANSELH = 0b00000000;
    TRISB  = 0b00000000;
    TRISC  = 0b10000000;
    PORTB  = 0b00000000;
    PORTC  = 0b00000000;
    
    spi_init();
    __delay_ms(100);
   
}

