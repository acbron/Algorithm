/*
 * 输出链表的中间结点
 */
#include <cstdio>
#include "liblist.h"

void print_middle_node(list_node *head) 
{
	if (!head)
		return;
	list_node *fast = head, *slow = head;
	while (fast && fast->next && fast->next->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	printf("%d\n", slow->value);
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
		print_middle_node(head);
	}
	return 0;
}
