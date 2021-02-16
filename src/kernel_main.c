#include <stdio.h>
#include "list.h"

void zero_bss();

extern int __bss_start;
extern int __bss_end;

void kernel_main(){
	zero_bss();

	char *mu_io_reg = 0x7E215040;

	struct list_element c = { NULL, NULL, 0};
	struct list_element b = { NULL, NULL, 1};
	struct list_element a = { NULL, NULL,2};
	list_add(&a, &b);
	list_add(&a, &c);
	
	list_remove(&a, &b);

	while (1){
		*mu_io_reg = 'h';
		*mu_io_reg = 'a';
		*mu_io_reg = 'r';
		*mu_io_reg = 'i';
		*mu_io_reg = 's';
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
