/*
 * 求一个整数乘以3.5的结果，不使用算术运算符
 */

int multiply(int x)
{
	return x + (x << 1) + (x >> 1);
}

