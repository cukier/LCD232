/*
 * lcd232.c
 *
 *  Created on: 01/10/2012
 *      Author: cuki
 */

#include<16F628A.h>

#fuses NOWDT,NOPUT,INTRC,NOMCLR,NOBROWNOUT,NOLVP,NOCPD,NOPROTECT
#use delay(clock=4MHz)

#include"lcd_4b.c"

int main(void) {
//   lcd_init();
//   delay_ms(300);
	while (true) {
		output_toggle(pin_a0);
		output_toggle(pin_a1);
		output_toggle(pin_a7);
//		output_toggle(pin_a6);
		output_toggle(pin_b5);
		output_toggle(pin_b4);
//      delay_ms(500);
//      printf(lcd, "\f");
//      delay_ms(500);
//      printf(lcd, "Hola");
		delay_ms(10);
//      printf(lcd, "\nMundo");
	}
	return 0;
}
