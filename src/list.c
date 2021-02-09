#include <stdio.h>
#include "list.h"

void list_add(struct list_element *list_head, struct list_element *new_element);
void list_remove(struct list_element *list_head, struct list_element *rm_element);
 
//adds data to the list
void list_add(struct list_element *list_head, struct list_element *new_element){
	struct list_element *temp = list_head;
	//Loop through the list until it becomes null
	while(temp->next != NULL){
		temp = temp->next;
	}
	/*Refer to the next, null node in the list and set it to new_element
	  And then just go back to the prev element in the added element*/
	temp->next = new_element;
	new_element->prev = temp;
}

//Removes the data from the list
void list_remove(struct list_element *list_head, struct list_element *rm_element){
	struct list_element *temp = list_head;
	if(temp == NULL){
		return;
	}
	if(temp == rm_element){
		temp = temp->next;
	}
	/*Loop through the list until they are equal 
	  Moves the head pointer until it hits the element I want removed */
	while(temp != rm_element){
		temp = temp->next;
	}
	//Update the next node
	if(temp->next != NULL){
		temp->next->prev = temp->prev;
	}
	//Update the previous node
	if(temp->prev != NULL){
		temp->prev->next = temp->next;
	}
}

