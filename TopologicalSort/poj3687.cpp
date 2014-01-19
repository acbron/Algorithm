/*************************************************************************
    > File Name: poj3687.cpp
    > Author: GentleH
    > Mail: GentleHJX@Gmail.com 
    > Created Time: 2014年01月19日 星期日 14时54分52秒

Description

Windy has N balls of distinct weights from 1 unit to N units. Now he tries to label them with 1 to N in such a way that:

No two balls share the same label.
The labeling satisfies several constrains like "The ball labeled with a is lighter than the one labeled with b".
Can you help windy to find a solution?

Input

The first line of input is the number of test case. The first line of each test case contains two integers, N (1 ≤ N ≤ 200) and M (0 ≤ M ≤ 40,000). The next M line each contain two integers a and b indicating the ball labeled with a must be lighter than the one labeled with b. (1 ≤ a, b ≤ N) There is a blank line before each test case.

Output

For each test case output on a single line the balls' weights from label 1 to label N. If several solutions exist, you should output the one with the smallest weight for label 1, then with the smallest weight for label 2, then with the smallest weight for label 3 and so on... If no solution exists, output -1 instead.

 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int SIZE = 256;

int cas,n,m;
int in[SIZE];
int ans[SIZE],id;
vector <int> vt[SIZE];
priority_queue <int> Q;

int toposort()
{
	while(!Q.empty())
		Q.pop();
	for(int i=1; i<=n; i++)if(in[i] == 0)
		Q.push(i);
	while(!Q.empty())
	{
		int cur = Q.top();
		Q.pop();
		ans[cur] = id--;
		for(int i=0; i<(int)vt[cur].size(); i++)
		{
			int to = vt[cur][i];
			--in[to];
			if(!in[to])
				Q.push(to);
		}
	}
	if(id != 0)
		return -1;
	return 1;
}

int main()
{
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0; i<=n; i++)
		{
			vt[i].clear();
			in[i] = 0;
		}
		for(int i=1; i<=m; i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			vt[v].push_back(u);
			in[u]++;
		}
		id = n;
		int check = toposort();
		if(check == -1)puts("-1");
		else
		{
			for(int i=1; i<n; i++)
				printf("%d ",ans[i]);
			printf("%d\n",ans[n]);
		}
	}
	return 0;
}
