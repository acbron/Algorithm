#include <cstdio>
#include "liblist.h"

bool detect_loop(list_node *head) 
{
	if (!head)
		return false;
	list_node *fast = head, *slow = head;
	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return true;
	}
	return false;
}
int main()
{
	int nodes;
	while (~scanf("%d", &nodes)) {
		list_node *head = NULL;
		int v;
		for (int i = 0; i < nodes; i++) {
			scanf("%d", &v);
			insert(&head, v);
		}
		print(head);
		scanf("%d", &v);
		if (v) {
			insert(&head, v);
			list_node *last_node = head;
			while (last_node && last_node->next)
				last_node = last_node->next;
			last_node->next = head;
		}
		bool is_loop = detect_loop(head);
		is_loop ? printf("loop\n") : printf("no loop");
	}
	return 0;
}
