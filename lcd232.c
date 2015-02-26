/*
 * lcd232.c
 *
 *  Created on: 01/10/2012
 *      Author: cuki
 */

#include<16F628A.h>
#zero_ram

#fuses NOWDT,NOPUT,INTRC_IO,MCLR,NOBROWNOUT,NOLVP,NOCPD,NOPROTECT
#use delay(clock=4MHz)
#use rs232(baud=9600,xmit=pin_b2,rcv=pin_b1)

#include "lcd_4b.c"

int main(void) {

	lcd_init();
	delay_ms(500);
	printf(lcd, "\fDone");

	while (TRUE) {
		printf(lcd, "%c", getc());
	}
	return 0;
}
