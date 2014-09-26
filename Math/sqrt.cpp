// 牛顿迭代法
double sqrt(double number)
{
	if (number <= 0)
		return 0;
	double i = 1; //i越接近sqrt(number)，循环次数越少
	double j = number / i;
	while ((i < j ? j - i : i - j) > 1e-9) {
		i = (i + j) / 2;
		j = number / i;
	}
	return i;
}
