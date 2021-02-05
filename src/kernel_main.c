#include <stdio.h>

void zero_bss();

extern int __bss_start;
extern int __bss_end;

int kernel_main(){
	zero_bss();

	struct list_element c = { NULL, 0};
	struct list_element b = { &c, 0};
	struct list_element a = { &b, 0};
	struct list_element *head = &a;

	while (1){
	}
}

void zero_bss(){

	int *begin_bss;
        begin_bss = &__bss_start;
	int i = 0;

	//Iterate through the bss until the addresses are the same whilst writing 0 to each address
	while(&__bss_start + i != &__bss_end){
		begin_bss[i] = 0;
		i++;	
	}			
}
