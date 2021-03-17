#include "list.h"
#include "page.h"
//null def from class notes
#define NULL (void*)0
#define NPAGES 128

extern int __end; //used to calculate the address of the first page frame. got from kernel.ld
struct ppage physical_page_array[NPAGES]; //128 pages, each 2mb in length covers 256 megs of memory
struct ppage* free_list = NULL;

void init_pfa_list(void){
	void* address = (((unsigned long)&__end) & ~(0x200000 - 1)) + 0x200000;
	for(int i = 0; i < NPAGES; i++){
		physical_page_array[i].physical_addr = address;
		list_add(&free_list, (struct list_element*) &physical_page_array[i]);
		address += 0x200000;
	}
}

struct ppage *allocate_physical_pages(unsigned int npages){
	struct ppage *new_ptr = free_list;
	struct ppage *list_ptr = NULL;
	for(int i = 0; i < npages; i++){
		list_remove(new_ptr);
		list_add(&list_ptr, new_ptr);
	}
	return list_ptr;
}

void free_physical_pages(struct ppage *ppage_list){
	struct ppage *free_ptr = ppage_list;
	while(ppage_list != NULL){
		list_remove(free_ptr);
		list_add(&free_list, free_ptr);
	}
}
