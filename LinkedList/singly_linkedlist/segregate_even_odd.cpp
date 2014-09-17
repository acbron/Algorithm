#include <cstdio>
#include "liblist.h"

void segregate(list_node **ref_head, bool (*func)(int))
{
	if ((*ref_head) == NULL)
		return;
	list_node *cur = *ref_head;
	list_node **ref_next = ref_head;
	list_node *head = NULL, *tail = NULL;
	while (cur) {
		if (func(cur->value)) {
			*ref_next = cur->next;
			list_node *tmp = cur;
			cur = cur->next;
			tmp->next = NULL;
			if (!head) {
				head = tmp;
				tail = tmp;
			} else {
				tail->next = tmp;
				tail = tail->next;
			}
		} else {
			ref_next = &(cur->next);
			cur = cur->next;
		}
	}
	tail->next = *ref_head;
	*ref_head = head;
}

bool is_even(int value)
{
	return (value % 2 == 0);
}
int main()
{
	list_node *head = input();
	segregate(&head, is_even);
	print(head);
	return 0;
}
