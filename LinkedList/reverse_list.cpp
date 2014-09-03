/*
 * 反转链表
 */
#include <cstdio>
#include "liblist.h"

void reverse_list(list_node **ref_head)
{
	if (*ref_head == NULL)
		return;
	list_node *prev = NULL, *cur = *ref_head;
	while (cur->next) {
		list_node *tmp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = tmp;
	}
	cur->next = prev;
	*ref_head = cur;
}
void reverse_list_recursive(list_node **ref_head)
{
	if (*ref_head == NULL)
		return;
	list_node *next_node = (*ref_head)->next;
	if (next_node) {
		reverse_list_recursive(&next_node);
		(*ref_head)->next->next = *ref_head;
		(*ref_head)->next = NULL;
		*ref_head = next_node;
	}
}
int main()
{
	int nodes;
	while (scanf("%d", &nodes)) {
		list_node *head = NULL;
		int v;
		for (int i = 0; i < nodes; i++) {
			scanf("%d", &v);
			insert(&head, v);
		}
		print(head);
		reverse_list(&head);
		print(head);
		reverse_list_recursive(&head);
		print(head);
	}
	return 0;
}
