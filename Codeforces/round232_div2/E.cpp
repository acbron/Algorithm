/*
E. On Changing Tree

time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output

You are given a rooted tree consisting of n vertices numbered from 1 to n. The root of the tree is a vertex number 1.

Initially all vertices contain number 0. Then come q queries, each query has one of the two types:

The format of the query: 1 v x k. In response to the query, you need to add to the number at vertex v number x; to the numbers at the descendants of vertex v at distance 1, add x - k; and so on, to the numbers written in the descendants of vertex v at distance i, you need to add x - (i·k). The distance between two vertices is the number of edges in the shortest path between these vertices.
The format of the query: 2 v. In reply to the query you should print the number written in vertex v modulo 1000000007 (109 + 7).
Process the queries given in the input.

Input
The first line contains integer n (1 ≤ n ≤ 3·105) — the number of vertices in the tree. The second line contains n - 1 integers p2, p3, ... pn (1 ≤ pi < i), where pi is the number of the vertex that is the parent of vertex i in the tree.

The third line contains integer q (1 ≤ q ≤ 3·105) — the number of queries. Next q lines contain the queries, one per line. The first number in the line is type. It represents the type of the query. If type = 1, then next follow space-separated integers v, x, k (1 ≤ v ≤ n; 0 ≤ x < 109 + 7; 0 ≤ k < 109 + 7). If type = 2, then next follows integer v (1 ≤ v ≤ n) — the vertex where you need to find the value of the number.

Output
For each query of the second type print on a single line the number written in the vertex from the query. Print the number modulo 1000000007 (109 + 7).

Sample test(s)
input
3
1 1
3
1 1 2 1
2 1
2 2
output
2
1

对于一棵树，根据搜索时间可以构造出线段树的区间。
对于此题，由于每个节点的值只与它自己以及它的祖先有关，而跟子孙无关。所以可以记录每个节点在树中的深度dep[v]，如果有更新操作，则对v所表示区间sum增加val+dep[x]*k，同时用一个lazy标记该区间的更新情况k。每当询问到v时，则答案为sum-lazy*dep[v]。显然，对于v的孩子v'，dep[v']大于dep[v]，所以在求答案的时候会把多加数量的k减去。
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 300030;
const int MOD = 1000000007;
#define ls l,mid,rt<<1
#define rs mid+1,r,rt<<1|1

int n;
vector <int> v[SIZE];
int L[SIZE],R[SIZE],dep[SIZE],tim;
long long sum[SIZE<<2],sub[SIZE<<2];

void dfs(int cur)
{
	L[cur] = ++tim;
	for(size_t i=0; i<v[cur].size(); i++)
	{
		int to = v[cur][i];
		dep[to] = dep[cur]+1;
		dfs(to);
	}
	R[cur] = tim;
}

void pushDown(int rt)
{
	sum[rt<<1] += sum[rt];
	sum[rt<<1] %= MOD;
	sub[rt<<1] += sub[rt];
	sub[rt<<1] %= MOD;
	sum[rt<<1|1] += sum[rt];
	sum[rt<<1|1] %= MOD;
	sub[rt<<1|1] += sub[rt];
	sub[rt<<1|1] %= MOD;
	sum[rt] = sub[rt] = 0;
}

void update(int l,int r,int rt,int ll,int rr,long long val,long long k)
{
	if(ll <= l && r <= rr)
	{
		sum[rt] += val;
		sum[rt] %= MOD;
		sub[rt] += k;
		sub[rt] %= MOD;
		return;
	}
	pushDown(rt);
	int mid = (l+r)>>1;
	if(ll <= mid)
		update(ls,ll,rr,val,k);
	if(rr > mid)
		update(rs,ll,rr,val,k);
}

long long query(int l,int r,int rt,int pos,int deep)
{
	if(l == r)
	{
		long long ret = 0;
		ret = (sum[rt]-sub[rt]*deep)%MOD;
		if(ret < 0)ret += MOD;
		return ret;
	}
	pushDown(rt);
	int mid = (l+r) >> 1;
	if(pos <= mid)
		return query(ls,pos,deep);
	return query(rs,pos,deep);
}

int main()
{
	cin >> n;
	for(int i=1; i<=n; i++)
		v[i].clear();
	for(int i=2; i<=n; i++)
	{
		int x;
		cin >> x;
		v[x].push_back(i);
	}
	dep[1] = 1;
	tim = 0;
	dfs(1);
	memset(sum,0,sizeof(sum));
	memset(sub,0,sizeof(sub));
	int q;
	cin >> q;
	while(q--)
	{
		int type;
		long long x,val,k;
		cin >> type;
		if(type == 1)
		{
			cin >> x >> val >> k;
			val = (val+dep[x]*k)%MOD;
			update(1,tim,1,L[x],R[x],val,k);
		}
		else
		{
			cin >> x;
			long long ans = query(1,tim,1,L[x],dep[x]);
			cout << ans << endl;
		}
	}
	return 0;
}
