/*******************************************
 * @file: quick_sort.cpp
 * @author: gentleh
 * @mail: gentlehjx@gmail.com
 * @date: 2016年03月01日 星期二 23时02分11秒
 *******************************************/

#include <cstdio>
#include <ctime>
#include <cstdlib>

// swap the value of two variable
void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

// partition 
void sort_helper(int *arr_head, int *arr_tail, bool (*func)(int, int))
{
	if (arr_tail <= arr_head)
		return;

	// get the length of array
	int arr_count = arr_tail - arr_head;

	// generate random pivot
	srand((unsigned)time(NULL));
	int pivot = rand() % arr_count;

	int pivot_value = *(arr_head + pivot);
	swap(arr_head, arr_head + pivot);
	int *ptr_head = arr_head;
	int *ptr_tail = arr_tail - 1;

	// do partition
	while (ptr_head < ptr_tail) {
		while (!func(*ptr_tail, pivot_value) && ptr_tail > ptr_head)
			--ptr_tail;
		if (ptr_head < ptr_tail)
			*(ptr_head++) = *ptr_tail;
		while (func(*ptr_head, pivot_value) && ptr_head < ptr_tail)
			++ptr_head;
		if (ptr_head < ptr_tail)
			*(ptr_tail--) = *ptr_head;
	}
	*ptr_head = pivot_value;

	//do the rest sorting
	int partition = ptr_head - arr_head;
	sort_helper(arr_head, arr_head + partition, func);
	sort_helper(arr_head + partition + 1, arr_tail, func);
}

// main sorting function
void sort(int *arr_head, int *arr_tail, bool (*func)(int, int))
{
	if (arr_tail - arr_head <= 0) {
		printf("invalid array.\n");
		return;
	}
	for (int *ptr = arr_head; ptr < arr_tail; ptr++) {
		if (NULL == ptr) {
			puts("invalid array.");
			return;
		}
	}
	sort_helper(arr_head, arr_tail, func);
}

bool smaller(int x, int y)
{
	return x < y;
}

bool bigger(int x, int y)
{
	return x > y;
}

int main()
{
	int arr_count;
	while (~scanf("%d", &arr_count)) {
		int *arr = new int[arr_count];
		srand((unsigned)time(NULL));
		puts("\nbefore sorting:");
		for (int i = 0; i < arr_count; i++) {
			arr[i] = rand() % 1024;
			printf("%d ", arr[i]);
		}
		sort(arr, arr + arr_count, smaller);
		puts("\nafter sorting:");
		for (int i = 0; i < arr_count; i++) {
			printf("%d ", arr[i]);
		}
		puts("");
		delete arr;
		arr = NULL;
	}
}
