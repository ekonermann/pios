//#include <stdio.h>
#include "list.h"
#include "led.h"
#include "serial.h"
#include "rprintf.h"

void zero_bss();

extern int __bss_start;
extern int __bss_end;

void kernel_main(){
	//zero_bss();
	//led_init();
	esp_printf(putc, "Current Execution Level is %d\r\n", kernel_main);
	
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
