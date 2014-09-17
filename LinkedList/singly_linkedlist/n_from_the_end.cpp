/*
 * 输出倒数第n个结点
 */
#include <cstdio>
#include "liblist.h"

void n_from_the_end(list_node *head, int n)
{
	if (!head || n <= 0)
		return;
	list_node *fast = head, *slow = head;
	int total = 0;
	for (list_node *ptr = head; ptr; ptr = ptr->next)
		total++;
	if (n > total)
		return;
	for (int i = 0; i < n - 1; i++)
		fast = fast->next;
	while (fast->next) {
		fast = fast->next;
		slow = slow->next;
	}
	printf("%d\n", slow->value);
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
		int n;
		printf("input the Nth node from the end\n");
		scanf("%d", &n);
		n_from_the_end(head, n);
	}
	return 0;
}
