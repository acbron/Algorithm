//recursive
double pow(double base, unsigned int exp)
{
	if (exp == 0)
		return 1;
	else if (exp == 1)
		return base;
	double result = pow(base, exp >> 1);
	result *= result;
	if (exp & 1) 
		result *= base;
	return result;
}

//non-recursive
double pow(double base, unsignd int exp)
{
	if (exp == 0)
		return 1;
	else if (exp == 1)
		return base;
	double result = 1;
	while (exp) {
		if (exp & 1)
			result *= base;
		exp >>= 1;
		base *= base;
	}
	return result;
}
