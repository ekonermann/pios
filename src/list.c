#include <stddef.h>
#include "list.h"

void list_add(struct list_element **head, struct list_element *new_element);
void list_remove(struct list_element *b);
 
//adds data to the list
void list_add(struct list_element ** head, struct list_element *new_element){
	struct list_element *iterator = (struct list_element*)head ;
	
	new_element->next = iterator->next ;
	new_element->prev = iterator ;

	iterator->next = new_element ;

	if(new_element->next != NULL){
		new_element->next->prev = new_element ;
	}
}

//Removes the data from the list
void list_remove(struct list_element *b){
	if(b->next != NULL){
		b->next->prev = b->prev ;
	}

	b->prev->next = b->next ;

	b->next = NULL ;
	b->prev = NULL ;
}

