/*
 * ctrl.c
 *
 *  Created on: 04/10/2012
 *      Author: cuki
 */
#include<18F452.h>

#fuses HS,NOOSCSEN,NOPUT,NOBROWNOUT,NOWDT,NOSTVREN,NOLVP,NODEBUG,NOPROTECT,NOCPB,NOCPD,NOWRT,NOWRTC,NOWRTB,NOWRTD,NOEBTR,NOEBTRB
#use delay(clock=8MHz)
#use rs232(baud=9600,xmit=pin_c6,rcv=pin_c7)

int cont;

int main(void) {
	while (true) {
		delay_ms(3000);
		printf("B");
		getch()
	}
	return 0;
}
