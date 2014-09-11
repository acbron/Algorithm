#include <cstdio>
#include "liblist.h"

void skip_m_delete_n(list_node **ref_head, int m, int n)
{
	if (!(*ref_head) || m <= 0 || n <= 0)
		return;
	int count = 0;
	list_node *cur = *ref_head;
	while (cur) {
		++count;
		cur = cur->next;
	}
	if (count < m + n)
		return;
	list_node **ref_next = ref_head;
	list_node *del_start = NULL, *del_end = NULL;
	cur = *ref_head;
	for (int i = 0; i < m; i++) {
		ref_next = &(cur->next);
		cur = cur->next;
	}
	del_start = cur;
	for (int i = 0; i + 1 < n; i++)
		cur = cur->next;
	del_end = cur->next;
	*ref_next = cur->next;
	while (del_start != del_end) {
		list_node *tmp = del_start;
		del_start = del_start->next;
		delete tmp;
		tmp = NULL;
	}
	skip_m_delete_n(&del_end, m, n);
}
int main()
{
	list_node *head = input();
	int m,n;
	puts("input skip m, delete n");
	scanf("%d %d", &m, &n);
	skip_m_delete_n(&head, m, n);
	print(head);
}
