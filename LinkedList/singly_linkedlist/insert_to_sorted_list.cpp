#include <cstdio>
#include "liblist.h"

bool compare(int lhs, int rhs) 
{
	return lhs < rhs;
}

void insert_to_sorted_list(list_node **ref_head, int value, bool (*func)(int, int)) 
{
	if ((*ref_head) == NULL)
		return;
	list_node **ref_next = ref_head;
	list_node *cur = *ref_head;
	list_node *new_node = new list_node;
	new_node->value = value;
	new_node->next = NULL;
	while (cur) {
		if (func(value, cur->value)) {
			new_node->next = cur;
			*ref_next = new_node;
			return;
		}
		ref_next = &(cur->next);
		cur = cur->next;
	}
	*ref_next = new_node;
}
int main()
{
	int nodes;
	while (~scanf("%d", &nodes)) {
		list_node *head = NULL;
		int v = 0;
		for (int i = 0; i < nodes; i++) {
			scanf("%d", &v);
			insert(&head, v);
		}
		print(head);
		scanf("%d", &v);
		insert_to_sorted_list(&head, v, compare);
		print(head);
	}
	return 0;
}
