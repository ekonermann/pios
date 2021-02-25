#include <stdio.h>
#include "led.h"

unsigned int *GPSET1 = 0xFE200020;
unsigned int *GPSEL4 = 0xFE200010;
unsigned int *GPCLR1 = 0xFE20002C;


void led_init(){
	*GPSEL4 &= 0xFFFFFE3F;
	*GPSEL4 |= (1 << 6);
	return;	
}

void led_on(){
	*GPSET1 = (1 << 10);
}

void led_off(){
	*GPCLR1 = (1 << 10);
}

void delay(){
	for(unsigned int i = 0; i < 100000; i++){
		asm("NOP");
	}
}
