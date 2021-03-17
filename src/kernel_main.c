//#include <stdio.h>
#include "list.h"
#include "led.h"
#include "serial.h"
#include "rprintf.h"
#include "page.h"

void zero_bss();

extern int __bss_start;
extern int __bss_end;
extern struct ppage *free_list;

void kernel_main(){
	//zero_bss();
	//led_init();
	//esp_printf(putc, "Current Execution Level is %d\r\n", kernel_main);
	
/*	struct list_element c = { NULL, NULL, 0};
	struct list_element b = { NULL, NULL, 1};
	struct list_element a = { NULL, NULL,2};
	list_add(&a, &b);
	list_add(&a, &c);
	
	list_remove(&a, &b);
*/

/*	while (1){
		led_on();
		delay();
		led_off();
		delay();
	}
	*/

	init_pfa_list();
	struct ppage *p = free_list;
	p = p->next;
	esp_printf((void*)putc, "Physical addr: %x\n", p->physical_addr);
	//the (void*) gets rid of the annoyinf incompatible pointer type
	p = allocate_physical_pages(2);
	esp_printf((void*)putc, "Allocated physical addr: %x\n", p->physical_addr);
	p = allocate_physical_pages(2);
	esp_printf((void*)putc, "allocated physical addr: %x\n", p->physical_addr);

	free_physical_pages(p);
	esp_printf((void*)putc, "Address after free func: %x\n", p->physical_addr);
	
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
