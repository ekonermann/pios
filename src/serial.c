#include "serial.h"

void putc(int data){
	int *mu_io = 0x3F215040;
	*mu_io = data;
}

//fixed from hw 5
