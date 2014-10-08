/*
在一个数组中，找出一个最小的区间，将该区间排序后整个数组便有序
时间复杂度O(n)
*/

void print_unsorted(int arr[], int count)
{
    if (!arr || count <= 0) {
        printf("null\n");
        return;
    }
    int s = -1, e = -1;
    for (int i = 0; i + 1 != count; i++) {
        if (arr[i] > arr[i + 1]) {
            s = i;
            break;
        }
    }
    for (int i = count - 1; i != 0; i--) {
        if (arr[i] < arr[i - 1]) {
            e = i;
            break;
        }
    }
    if (s == -1 || e == -1) {
        printf("null\n");
        return;
    }
    int min = arr[s], max = arr[s];
    for (int i = s; i <= e; i++) {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    for (int i = 0; i != s; i++) {
        if (arr[i] > min) {
            s = i;
            break;
        }
    }
    for (int i = count - 1; i != e; i--) {
        if (arr[i] < max) {
            e = i;
            break;
        }
    }
    printf("%d %d\n", s, e);
}
