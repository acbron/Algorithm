/*
 * 在一个数组中，有一个元素出现一次，其余元素出现K次
 * 求出该出现一次的元素，时间复杂度O(n),空间复杂度O(1)
 */

int find_appear_once(int *array, int count, int k)
{
	if (!array || count <= 0 || k <= 0)
		return -1;	//error code
	const int total_bits = 32;
	int result = 0;
	for (int b = 0; b != total_bits; b++) {
		int tmp = 0;
		for (int i = 0; i != count; i++)
			tmp += ((array[i] >> b) & 1);
		tmp %= k;
		if (tmp)
			result |= (1 << b);
	}
	return result;
}
