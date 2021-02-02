#ifndef LINKED_LIST_STRUCT
#define LINKED_LIST_STRUCT

typedef struct list_element{
	struct list_element *next;
	int data;
} list_nodes;

void list_add(list_nodes **front, int data);

int list_remove(list_nodes **front);

#endif
