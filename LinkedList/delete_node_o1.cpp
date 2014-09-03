/*
 * 在O（1）时间内删除一个给定的结点
 */
#include <cstdio>
#include "liblist.h"

void delete_node_o1(list_node **ref_head, list_node *del)
{
	if (*ref_head == NULL || del == NULL)
		return;
	if (*ref_head == del) {
		//删除的是头结点
		*ref_head = del->next;
	} else {
		if (del->next) {
			//删除的结点不是尾结点，直接修改该结点的值为其next结点的值，并删除其next结点
			list_node *save = del;
			save->value = del->next->value;
			del = save->next;
			save->next = del->next;
		} else {
			//删除的是我尾结点，需要遍历链表。只有删除的结点是尾结点时才需要便利，如果链表结点数为n，平均复杂度仍为O(1)
			list_node *tmp = *ref_head;
			while (tmp->next != del)
				tmp = tmp->next;
			tmp->next = NULL;
		}
	}
	delete del;
	del = NULL;
}

/*
 * main function for test
 */
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
		printf("input the node that need to be deleted.\n");
		scanf("%d", &v);
		list_node *tmp = head;
		for ( ; tmp; tmp = tmp->next) {
			if (tmp->value == v)
				break;
		}
		if (tmp) {
			delete_node_o1(&head, tmp);
			print(head);
		} else {
			puts("no such a node");
		}
	}
	return 0;
}
