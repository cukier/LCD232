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

int buffer[34];
int line = 0;

#INT_TIMER1
void isr_timer1() {
	clear_interrupt(INT_TIMER1);
	setup_timer_1(T1_DISABLED);
	for (line = 0; line < 32; line++) {
		buffer[line] = '\0';
	}
	line = 0;
}

#int_rda
void serial_isr() {
	clear_interrupt(INT_RDA);
	buffer[line++] = getc();
	buffer[line] = '\0';
	set_timer1(0);
	setup_timer_1(T1_INTERNAL | T1_DIV_BY_1);
}

int main(void) {

	clear_interrupt(INT_TIMER1);
	enable_interrupts(INT_RDA);
	enable_interrupts(INT_TIMER1);
	enable_interrupts(GLOBAL);

	while (TRUE) {
		;
	}
	return 0;
}
