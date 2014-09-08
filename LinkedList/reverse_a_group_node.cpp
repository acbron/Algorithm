#include <cstdio>
#include "liblist.h"

list_node *reverse(list_node *head, int k)
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
	head->next = reverse(tmp, k);
	return prev;
}
int main()
{
	list_node *head = input();
	print(head);
	printf("input group size:\n");
	int k;
	scanf("%d", &k);
	list_node *n = reverse(head, k);
	print(n);
	return 0;
}
