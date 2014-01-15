/*************************************************************************
    > File Name: hdu2121.cpp
    > Author: GentleH
    > Mail: GentleHJX@Gmail.com 
    > Created Time: 2014年01月15日 星期三 20时00分45秒
 ************************************************************************/

//不定根的最小树形图

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int SIZE_V = 1024;
const int SIZE_E = SIZE_V+10000;

struct Edge
{
	int start,end,cost;
}edge[SIZE_E];

int V,E;
int initE,sum,root;
int mincost[SIZE_V],pre[SIZE_V];
int belong[SIZE_V],newId[SIZE_V];
int ans,who;

int directed_mst()
{
	int ret = 0;
	while(true)
	{
		for(int i=1; i<=V; i++)
			mincost[i] = sum+1;
		for(int i=1; i<=E; i++)
		{
			int u = edge[i].start,v = edge[i].end;
			if(u != v && mincost[v] > edge[i].cost)
			{
				mincost[v] = edge[i].cost, pre[v] = u;
				if(u == root)
					who = i;
			}
		}
		int single = 0;
		for(int i=1; i<=V; i++)
		{
			if(i != root && pre[i] == root)
				++single;
			if(single > 1)
				return -1;
		}
		mincost[root] = 0;
		memset(belong,-1,sizeof(belong));
		memset(newId,-1,sizeof(newId));
		int index = 0;
		for(int i=1; i<=V; i++)
		{
			ret += mincost[i];
			int v = i;
			while(belong[v] != i && newId[v] == -1 && v != root)
				belong[v] = i, v = pre[v];
			if(v != root && newId[v] == -1)
			{
				newId[v] = ++index;
				for(int u=pre[v]; u!=v; u=pre[u])
					newId[u] = index;
			}
		}
		if(!index)
			break;
		for(int i=1; i<=V; i++)
			if(newId[i] == -1)
				newId[i] = ++index;
		for(int i=1; i<=E; i++)
		{
			int u = edge[i].start,v = edge[i].end;
			edge[i].start = newId[u];
			edge[i].end = newId[v];
			if(edge[i].start != edge[i].end)
				edge[i].cost -= mincost[v];
		}
		V = index;
		root = newId[root];
	}
	return ret;
}

int main()
{
	while(~scanf("%d%d",&V,&E))
	{
		initE = E,sum = 1;
		for(int i=1; i<=E; i++)
		{
			int u,v,c;
			scanf("%d%d%d",&u,&v,&c);
			++u, ++v;
			sum += c;
			edge[i].start = u, edge[i].end = v;
			edge[i].cost = c;
		}
		root = V+1;
		for(int i=1; i<=V; i++)
		{
			++E;
			edge[E].start = root;
			edge[E].end = i;
			edge[E].cost = sum;
		}
		++V;
		ans = -1;
		ans = directed_mst();
		if(ans == -1)
			puts("impossible");
		else
			printf("%d %d\n",ans-sum,who-initE-1);
		puts("");
	}
}
