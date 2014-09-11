/*
 * 给出一个包含next和child指针的链表，要求按层次输出
 */
#include <cstdio>
#include <queue>

using namespace std;

struct list {
	int value;
	list *next;
	list *child;
	list()
	{
		value = 0;
		next = NULL;
		child = NULL;
	}
	list(int v):value(v)
	{
		next = NULL;
		child = NULL;
	}
};

/*
 * generate data
 */
list *init()
{
	list *p[18];
	for (int i = 1; i <= 17; i++)
	{
		int v;
		printf("input the value of the node ");
		scanf("%d", &v);
		p[i] = new list(v);
	}
	p[1]->next = p[2];
	p[2]->next = p[3];
	p[3]->next = p[4];
	p[4]->next = p[5];
	p[1]->child = p[6];
	p[4]->child = p[9];
	p[6]->next = p[7];
	p[7]->next = p[8];
	p[9]->next = p[10];
	p[7]->child = p[11];
	p[8]->child = p[12];
	p[9]->child = p[13];
	p[12]->child = p[15];
	p[13]->next = p[14];
	p[13]->child = p[16];
	p[16]->next = p[17];
	return p[1];
}

list *flatten(list **ref_head)
{
	if (!(*ref_head))
		return NULL;
	queue <list *> q;
	list *head = *ref_head, *tail = *ref_head;
	while (tail) {
		if (tail->child) {
			list *tmp = tail->child;
			q.push(tmp);
			tail->child = NULL;
		}
		if (tail->next == NULL)
			break;
		tail = tail->next;
	}
	while (!q.empty()) {
		list *cur = q.front();
		q.pop();
		while (cur) {
			if (cur->child) {
				list *tmp = cur->child;
				q.push(tmp);
				cur->child = NULL;
			}
			tail->next = cur;
			tail = tail->next;
			if (cur->next == NULL)
				break;
			cur = cur->next;
		}
	}
	return head;
}

/*
 * test
 */
int main()
{
	list *head = init();
	list *p = flatten(&head);
	list *ptr = p;
	while (ptr) {
		printf("%d ", ptr->value);
		ptr = ptr->next;
	}
	puts("");
	return 0;
}
