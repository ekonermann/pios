#include "serial.h"

void putc(int data){
	char *mu_io = 0x3F215040;
	*mu_io = data;
}
