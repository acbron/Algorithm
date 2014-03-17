/*
C. On Number of Decompositions into Multipliers

time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output

You are given an integer m as a product of integers a1, a2, ... an . Your task is to find the number of distinct decompositions of number m into the product of n ordered positive integers.

Decomposition into n products, given in the input, must also be considered in the answer. As the answer can be very large, print it modulo 1000000007 (109 + 7).

Input
The first line contains positive integer n (1 ≤ n ≤ 500). The second line contains space-separated integers a1, a2, ..., an (1 ≤ ai ≤ 109).

Output
In a single line print a single number k — the number of distinct decompositions of number m into n ordered multipliers modulo 1000000007 (109 + 7).

Sample test(s)
input
1
15
output
1
input
3
1 1 2
output
3
input
2
5 7
output
4

组合数学问题:stars and bars
	如果要将k个数组合成n个数的排列，排列中组合不分顺序，则答案有C(k+n-1,n-1)种
	考虑一个数m，它可以分解成这样的形式(p1^k1)*(p2^k2)*..*(pt^kt)，p为素数。如果要将m分解成n个数的乘积，我们可以将任何一个p^k分解成n个数，然后将其余的数乘到任何一个分解后的数上。所以答案为C(k1+n-1,n-1)*C(k2+n-1,n-1)*...*C(kt+n-1,n-1)
*/
#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int SIZE = 512;
const int MOD = 1000000007;

int n;
long long C[SIZE*40][SIZE];
map <int,int> M;

int main()
{
	cin >> n;
	C[0][0] = 1;
	for(int i=1; i<(SIZE*40); i++)
	{
		C[i][0] = 1;
		for(int j=1; j<=n; j++)
			C[i][j] = (C[i-1][j-1]+C[i-1][j])%MOD;
	}
	M.clear();
	int x;
	for(int i=1; i<=n; i++)
	{
		cin >> x;
		for(int j=2; j*j<=x; j++)if(x % j == 0)
		{
			while(x % j == 0)
				x /= j, M[j]++;
		}
		if(x > 1)
			M[x]++;
	}
	long long ans = 1;
	for(map <int,int>::iterator it=M.begin(); it!=M.end(); it++)
		ans = (ans * C[it->second+n-1][n-1])%MOD;
	cout << ans << endl;
	return 0;
}
