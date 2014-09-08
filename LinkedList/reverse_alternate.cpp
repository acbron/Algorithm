#include <cstdio>
#include "liblist.h"

list_node *reverse_alternate(list_node *head, int k)
{
	if (!head || k <= 1)
		return head;
	list_node *cur = head, *prev = NULL, *tmp = NULL;
	for (int i = 0; i != k && cur; i++) {
		tmp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = tmp;
	}
	head->next = tmp;
	for (int i = 0; i != k && tmp; i++) {
		head = tmp;
		tmp = tmp->next;
	}
	head->next = reverse_alternate(tmp, k);
	return prev;
}
int main()
{
	list_node *head = input();
	print(head);
	printf("input the group size\n");
	int k;
	scanf("%d", &k);
	head = reverse_alternate(head, k);
	print(head);
	return 0;
}
