#ifndef LINKED_LIST_STRUCT
#define LINKED_LIST_STRUCT

struct list_element{
	struct list_element *next;
	struct list_element *prev;
};

void list_add(struct list_element **head, struct list_element *new_element);

void list_remove(struct list_element *b);

#endif
