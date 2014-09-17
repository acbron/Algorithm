#include <cstdio>
#include "liblist.h"

bool detect_remove_loop(list_node **ref_head)
{
	if ((*ref_head) == NULL)
		return false;
	list_node *fast = *ref_head, *slow = *ref_head;
	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			break;
	}
	if (!fast || !(fast->next))
		return false;
	int count = 0;
	while (fast->next != slow) {
		++count;
		fast = fast->next;
	}
	++count;
	fast = *ref_head;
	slow = *ref_head;
	for (int i = 0; i < count; i++)
		fast = fast->next;
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}
	fast = fast->next;
	while (fast->next != slow)
		fast = fast->next;
	fast->next = NULL;
	return true;
}
int main()
{
	list_node *head = input();
	printf("input k , which is smaller than the number of nodes\n");
	int k;
	scanf("%d", &k);
	list_node *ptr = head;
	list_node *last = head;
	if (k != -1) { // make a loop
		while (last->next)
			last = last->next;
		for (int i = 0; i < k; i++)
			ptr = ptr->next;
		last->next = ptr;
	}
	if (detect_remove_loop(&head))
		print(head);
	else
		puts("no loop");
	return 0;
}
