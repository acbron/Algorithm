/*
Interpolation Search(插值排序)
平均时间复杂度O(log(logn))，最坏时间复杂度O(n)
适用于：1）数组已有序，且元素值均匀分布。2）读取数据代价昂贵（比如读取每个元素都要读磁盘，插值排序可以尽量减少对元素的读取）
*/

int interpolation_search(int arr[], int count, int key)
{
    int low = 0, high = count - 1;
    while (low <= high) {
        int mid = low + (high - low) * (key - arr[low]) / (arr[high] - arr[low]);
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
