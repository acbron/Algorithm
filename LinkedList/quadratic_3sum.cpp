/*
 * 在三个链表中分别找出一个结点，使三个结点的值等于给定值K
 * Quadratic Algorithm, 3sum problem, time O(n^2)
 */
#include <cstdio>
#include "liblist.h"

bool bigger(int lhs, int rhs)
{
	return lhs > rhs;
}
bool smaller(int lhs, int rhs)
{
	return lhs < rhs;
}
list_node *merge(list_node *left, list_node *right, bool (*func)(int, int))
{
	if (!left)
		return right;
	else if (!right)
		return left;
	list_node *head = NULL, *tail = NULL;
	while (left && right) {
		list_node *tmp = new list_node;
		tmp->next = NULL;
		if (func(left->value, right->value)) {
			tmp->value = left->value;
			left = left->next;
		} else {
			tmp->value = right->value;
			right = right->next;
		}
		if (!head) {
			head = tail = tmp;
		} else {
			tail->next = tmp;
			tail = tail->next;
		}
	}
	while (left) {
		tail->next = left;
		tail = tail->next;
		left = left->next;
	}
	while (right) {
		tail->next = right;
		tail = tail->next;
		right = right->next;
	}
	return head;
}

void merge_sort(list_node **ref_head, bool (*func)(int, int))
{
	if (!(*ref_head))
		return;
	list_node *fast = *ref_head, *slow = *ref_head;
	while (fast && fast->next && fast->next->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	list_node *left = *ref_head, *right = slow->next;
	slow->next = NULL;
	if (!right)
		return;
	merge_sort(&left, func);
	merge_sort(&right, func);
	*ref_head = merge(left, right, func);
}

bool quadratic_algorithm(list_node *head1, list_node *head2, list_node *head3, int target)
{
	if (!head1 || !head2 || !head3)
		return false;
	merge_sort(&head2, smaller);
	merge_sort(&head3, bigger);
	list_node *ptr1 = head1, *ptr2 = head2, *ptr3 = head3;
	while (ptr1) {
		int v1 = ptr1->value;
		ptr2 = head2, ptr3 = head3;
		while (ptr2 && ptr3) {
			int v2 = ptr2->value, v3 = ptr3->value;
			if (v1 + v2 + v3 == target) {
				printf("%d %d %d\n", v1, v2, v3);
				return true;
			} else if (v1 + v2 + v3 < target) {
				ptr2 = ptr2->next;
			} else {
				ptr3 = ptr3->next;
			}
		}
		ptr1 = ptr1->next;
	}
	return false;
}
int main()
{
	list_node *head = input();
	list_node *head2 = input();
	list_node *head3 = input();
	printf("input the target number\n");
	int k;
	scanf("%d", &k);
	bool flag = quadratic_algorithm(head, head2, head3, k);
	flag ? puts("yes") : puts("no");
	return 0;
}
