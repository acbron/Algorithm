#include <cstdio>
#include "liblist.h"

list_node *merge(list_node *first, list_node *second)
{
	if (!first)
		return second;
	else if (!second)
		return first;
	list_node *head = NULL, *tail = NULL;
	while (first && second) {
		list_node *tmp = new list_node;
		tmp->next = NULL;
		if (first->value < second->value) {
			tmp->value = first->value;
			first = first->next;
		} else {
			tmp->value = second->value;
			second = second->next;
		}
		if (!head) {
			head = tmp;
			tail = tmp;
		} else {
			tail->next = tmp;
			tail = tail->next;
		}
	}
	while (first) {
		list_node *tmp = first;
		if (!head) {
			head = tmp;
			tail = tmp;
		} else {
			tail->next = tmp;
			tail = tail->next;
		}
		first = first->next;
	}
	while (second) {
		list_node *tmp = second;
		if (!head) {
			head = tmp;
			tail = tmp;
		} else {
			tail->next = tmp;
			tail = tail->next;
		}
		second = second->next;
	}
	return head;
}

void merge_sort(list_node **ref_head)
{
	if ((*ref_head) == NULL)
		return;
	list_node *fast = *ref_head, *slow = *ref_head;
	while (fast && fast->next && fast->next->next) {
		fast = fast->next->next;
		slow = slow->next;
	}
	list_node *left = *ref_head, *right = slow->next;
	if (!right)
		return;
	slow->next = NULL;
	merge_sort(&left);
	merge_sort(&right);
	*ref_head = merge(left, right);
}
int main()
{
	list_node *head = input();
	merge_sort(&head);
	print(head);
}
