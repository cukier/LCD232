/*
 * lcd232.c
 *
 *  Created on: 01/10/2012
 *      Author: cuki
 */

#include<16F628A.h>
#zero_ram

#fuses INTRC_IO
#use delay(clock=4MHz)
#use rs232(baud=9600,xmit=pin_b2,rcv=pin_b1)

#include "lcd_4b.c"

int buff[40];
int cont;

int main(void) {

	lcd_init();

	while (TRUE) {
		gets(buff);
		printf(lcd, "%s", buff);
		for (cont = 0; cont < 40; ++cont)
			buff[cont] = 0;
	}
	return 0;
}
