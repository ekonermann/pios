#include <stdio.h>

extern unsigned long __bss_start;
extern unsigned long __bss_end;

int kernel_main(){
	char *front_bss = & __bss_start;
	char *back_bss = & __bss_end;

	//iterate through the bss and zero it out. Change sizeof(front_bss to back_bss)?
	for(int i = 0; i < sizeof(front_bss); i++){
		front_bss[i] = 0;
	}

	return 0;
}
