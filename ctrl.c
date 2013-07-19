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

float cont;

int main(void) {
	delay_ms(1000);
	printf("\fInicio");
	printf("\nSegunda");
	while (TRUE) {
		if (!input(PIN_A0)) {
			delay_ms(50);
			if (!input(PIN_A0)) {
				cont = cont + 0.83;
				printf("\fU%dA%dR%dB%d", 1, 1, 0, 1);
				printf("\n%5lu.%2lu %f", (long long) cont,
						(long long) ((float) (cont - (long long) cont) * 100),
						60.87);
			}
		}
	}
	return 0;
}
