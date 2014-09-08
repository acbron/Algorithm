#include <cstdio>
#include "liblist.h"

void reverse_list(list_node **ref_head)
{
	if ((*ref_head) == NULL)
		return;
	list_node *ptr = *ref_head;
	list_node *prev = NULL;
	while (ptr) {
		list_node *tmp = ptr->next;
		ptr->next = prev;
		prev = ptr;
		ptr = tmp;
	}
	*ref_head = prev;
}
bool is_palindrome(list_node *head) 
{
	if (!head)
		return false;
	list_node *fast = head, *slow = head;
	while (fast && fast->next && fast->next->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	list_node *middle = slow->next;
	reverse_list(&middle);
	print(middle);
	list_node *left = head, *right = middle;
	bool flag = true;
	while (right) {
		if (right->value != left->value) {
			flag = false;
			break;
		}
		right = right->next;
		left = left->next;
	}
	reverse_list(&middle);
	return flag;
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
		is_palindrome(head) ? printf("yes\n") : printf("no\n");
	}
	return 0;
}
