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

int buffer[2][16];
int col, i, j;
short write = 1;
int line = 0;

#int_timer0
void timer_isr() {
	clear_interrupt(INT_TIMER0);
	disable_interrupts(INT_TIMER0);
	write = 1;
}

#int_rda
void serial_isr() {
	clear_interrupt(INT_RDA);
	if (line < 16 && col < 2) {
		buffer[col][line++] = getc();
		clear_interrupt(INT_TIMER0);
		enable_interrupts(INT_TIMER0);
		set_timer0(0);
	} else
		line = 0, col = 0;
	if (buffer[col][line - 1] == '\n') {
		buffer[col][line - 1] = 0;
		col++;
		line = 0;
		if (col > 1)
			col = 1;
	}
	if (buffer[col][line - 1] == '\f') {
		buffer[col][line - 1] = 0;
		col = 0;
		line = 0;
	}
	if (buffer[col][line - 1] == '\r') {
		buffer[col][line - 1] = 0;
		line = 0;
	}
}

int main(void) {
	for (i = 0; i < 16; i++) {
		buffer[0][i] = 0;
		buffer[1][i] = 0;
	}
	strcpy(buffer[1], "Done");
	lcd_init();
	delay_ms(15);
	setup_timer_0(T0_DIV_4);
	clear_interrupt(INT_TIMER0);
	enable_interrupts(INT_RDA);
	disable_interrupts(INT_TIMER0);
	enable_interrupts(GLOBAL);
	while (TRUE) {
		if (write) {
			printf(lcd, "%s", buffer[0]);
			printf(lcd, "%s", buffer[1]);
			for (i = 0; i < 16; i++) {
				buffer[0][i] = 0;
				buffer[1][i] = 0;
			}
			col = 0;
			line = 0;
			write = 0;
		}
	}
	return 0;
}
