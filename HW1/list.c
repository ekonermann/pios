#include <stdio.h>
#include<stdlib.h>
#include "list.h"

void list_add(list_nodes **front, int data){
	list_nodes *new_node;
	//Allocate the new node
	new_node = (list_nodes *)malloc(sizeof(list_nodes));
	new_node->data = data;
	
	//Point to the new node and then make front point to it
	new_node->next = *front;
	(*front) = new_node;
}

//Removes data from the end of the list
int list_remove(list_nodes **front){
	int link_data = -1;		
	list_nodes *prev_node = NULL;

	//check to see if the list is empty
	if(*front == NULL){
		return -1;
	}

	//Frees the current node (pops) and then sets the front to the stored previous data 
	prev_node = (*front)->next;
	link_data = (*front)->data;
	free(*front);
	*front = prev_node;
	
	//Return the linked list data
	return link_data;
}

