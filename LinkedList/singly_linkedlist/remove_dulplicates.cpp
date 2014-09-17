#include <cstdio>
#include "liblist.h"

void remove_duplicates(list_node **ref_head)
{
	if ((*ref_head) == NULL)
		return;
	list_node *ptr = *ref_head;
	while (ptr && ptr->next) {
		if (ptr->value == ptr->next->value) {
			list_node *tmp = ptr->next;
			ptr->next = ptr->next->next;
			delete tmp;
			tmp = NULL;
		} else {
			ptr = ptr->next;
		}
	}
}
int main()
{
	int nodes;
	while (scanf("%d", &nodes) != EOF) {
		list_node *head = NULL;
		int v = 0;
		for (int i = 0; i < nodes; i++) {
			scanf("%d", &v);
			insert(&head, v);
		}
		print(head);
		remove_duplicates(&head);
		print(head);
	}
}
