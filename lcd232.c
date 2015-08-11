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
#use rs232(baud=19200,xmit=pin_b2,rcv=pin_b1)

#include "lcd_4b.c"

#define max 40
#define T1_ON T1_INTERNAL|T1_DIV_BY_1

short write = 1;
int buffer[max];
int line = 0;

#INT_TIMER1
void isr_timer1() {
	clear_interrupt(INT_TIMER1);
	setup_timer_1(T1_DISABLED);
	write = TRUE;
}

#int_rda
void serial_isr() {
	clear_interrupt(INT_RDA);
	buffer[line++] = getc();
	buffer[line] = '\0';
	set_timer1(0);
	setup_timer_1(T1_ON);
}

int main(void) {

	lcd_init();

	clear_interrupt(INT_TIMER1);
	clear_interrupt(INT_RDA);
	enable_interrupts(INT_RDA);
	enable_interrupts(INT_TIMER1);
	enable_interrupts(GLOBAL);

	while (TRUE) {
		if (write) {
			write = 0;
			printf(lcd, "%s", buffer);
			printf("%s", buffer);
			for (line = 0; line < max; line++)
				buffer[line] = '\0';
			line = 0;
		}
	}
	return 0;
}
