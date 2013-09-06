/*
 * lcd232.c
 *
 *  Created on: 01/10/2012
 *      Author: cuki
 */

#include<16F628A.h>
#zero_ram

#fuses NOWDT,NOPUT,INTRC_IO,NOMCLR,NOBROWNOUT,NOLVP,NOCPD,NOPROTECT
#use delay(clock=4MHz)
#use rs232(baud=9600,xmit=pin_b2,rcv=pin_b1)

#include"lcd_4b.c"

int buffer[34];
int col, i, j;
short write = 1;
int line = 0;

#INT_TIMER1
void isr_timer1() {
	clear_interrupt(INT_TIMER1);
	setup_timer_1(T1_DISABLED);
	write = 1;
}

#int_rda
void serial_isr() {
	clear_interrupt(INT_RDA);
	if (line < 31) {
		buffer[line++] = getc();
		buffer[line] = '\0';
	} else {
		strcpy(buffer, "");
		line = 0;
	}
	set_timer1(0);
	setup_timer_1(T1_INTERNAL | T1_DIV_BY_1);
}

int main(void) {

	output_low(PIN_B3);
	strcpy(buffer, "Done2");
	lcd_init();
	delay_ms(15);

	clear_interrupt(INT_TIMER1);
	enable_interrupts(INT_RDA);
	enable_interrupts(INT_TIMER1);
	enable_interrupts(GLOBAL);

	while (TRUE) {
		if (write) {
			printf(lcd, "\f%s", buffer);
			buffer[0] = '\0';
			line = 0;
			write = 0;
		}
	}
	return 0;
}
