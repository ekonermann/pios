#include <stdio.h>
#include "list.h"

//adds data to the list
void list_add(struct list_element *list_head, struct list_element *new_element){
	struct list_element *temp = list_head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = new_element;	
}

//Removes data from the end of the list
void list_remove(struct list_element *element){
	struct list_element *temp = element;
	if(temp == NULL){
		return;
	}
	while(temp->prev != NULL){
		temp = temp->prev;
	}
	temp->prev = element;
}

