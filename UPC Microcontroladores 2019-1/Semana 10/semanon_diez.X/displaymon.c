/*
 * File:   displaymon.c
 * Author: pcelklau
 *
 * Created on 23 de mayo de 2019, 11:18 AM
 */
#pragma config PLLDIV = 1       // PLL Prescaler Selection bits (No prescale (4 MHz oscillator input drives PLL directly))
#pragma config CPUDIV = OSC1_PLL2// System Clock Postscaler Selection bits ([Primary Oscillator Src: /1][96 MHz PLL Src: /2])
#pragma config FOSC = XTPLL_XT  // Oscillator Selection bits (XT oscillator, PLL enabled (XTPLL))
#pragma config PWRT = ON        // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOR = OFF        // Brown-out Reset Enable bits (Brown-out Reset disabled in hardware and software)
#pragma config BORV = 3         // Brown-out Reset Voltage bits (Minimum setting 2.05V)
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config CCP2MX = ON      // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = ON      // PORTB A/D Enable bit (PORTB<4:0> pins are configured as analog input channels on Reset)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)

#include <xc.h>
#include "ADC.h"
#include "LCD.h"
#define _XTAL_FREQ 48000000UL

void main(void) {
    TRISD = 0x00;
    __delay_ms(15); //Retardo de 15 mseg
    LCD_CONFIG();
    CURSOR_ONOFF(OFF);
    while(1){
        CURSOR_HOME();
        ESCRIBE_MENSAJE("   Hola Mundo!",14);
        __delay_ms(1000);
        POS_CURSOR(2,1);
        ESCRIBE_MENSAJE("  UPC 2019-1 uC",15);
        __delay_ms(1000);
        BORRAR_LCD();
        __delay_ms(1000);        
    }
}
