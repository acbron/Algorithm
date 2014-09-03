#include "liblist.h"
#include <cstdio>

void insert(list_node **head, int value)
{
	list_node *new_node = new list_node;
	new_node->value = value;
	new_node->next = NULL;
	if (*head) {
		list_node *tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	} else {
		*head = new_node;
	}
}

void remove(list_node **head, int value) 
{
	if (*head == NULL)
		return;
	for (list_node **ref_head = head; *ref_head; ) {
		list_node *tmp = *ref_head;
		if (tmp->value == value) {
			*ref_head = tmp->next;
			delete tmp;
			break;
		} else {
			ref_head = &tmp->next;
		}
	}
}

void print(list_node *head)
{
	if (head == NULL)
		return;
	list_node *tmp = head;
	while (tmp) {
		printf("%d->", tmp->value);
		tmp = tmp->next;
	}
	printf("null\n");
}
