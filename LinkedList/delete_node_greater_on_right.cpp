#include <cstdio>
#include "liblist.h"

void reverse(list_node **ref_head)
{
	if ((*ref_head) == NULL)
		return;
	list_node *cur = *ref_head, *prev = NULL;
	while (cur) {
		list_node *tmp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = tmp;
	}
	*ref_head = prev;
}

void delete_greater(list_node **ref_head)
{
	if ((*ref_head) == NULL)
		return;
	list_node *head = *ref_head;
	reverse(&head);
	list_node *cur = head->next;
	list_node **ref_next = &(head->next);
	int maxi = head->value;
	while (cur) {
		if (cur->value < maxi) {
			*ref_next = cur->next;
			list_node *tmp = cur;
			cur = cur->next;
			delete tmp;
			tmp = NULL;
		} else {
			ref_next = &(cur->next);
			maxi = cur->value;
			cur = cur->next;
		}
	}
	reverse(&head);
	*ref_head = head;
}

int main()
{
	list_node *head = input();
	print(head);
	delete_greater(&head);
	print(head);
	return 0;
}
