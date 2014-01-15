//固定根的最小树形图
//O（VE）
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int SIZE = 128;
const int INF = 0xfffffff;

struct Edge
{
    int start,end,cost;
}edge[SIZE*SIZE];

int V,E;
int minCost[SIZE],pre[SIZE]; //minCost[i]记录以i为终点的最小边权值，pre[i]为其前驱
int belong[SIZE],newVertex[SIZE]; //belong[]用于缩点，newVertex[]则用于重新为点标号

int directed_mst()
{
    int ret = 0,root = 1; //root 初始为固定的根节点
    while(true)
    {
        for(int i=1; i<=V; i++)
            minCost[i] = INF;
        for(int i=1; i<=E; i++)
        {
            int start = edge[i].start,end = edge[i].end;
            if(start == end) //忽略到自环
                continue;
            if(minCost[end] > edge[i].cost)
                minCost[end] = edge[i].cost,pre[end] = start;
        }
        for(int i=1; i<=V; i++)
        {
            if(i == root)
                continue;
            if(minCost[i] == INF) //有孤立点，无界，直接返回。否则算法会进入死循环
                return -1;
        }
        minCost[root] = 0;
        memset(belong,-1,sizeof(belong));
        memset(newVertex,-1,sizeof(newVertex));
        int num = 0;
        for(int i=1; i<=V; i++)
        {
            ret += minCost[i];
            int vertex = i;
	//判断是否出现环
            while(belong[vertex] != i && newVertex[vertex] == -1 && vertex != root)
                belong[vertex] = i,vertex = pre[vertex];
	//缩点
            if(vertex != root && newVertex[vertex] == -1)
            {
                newVertex[vertex] = ++num;
                for(int v=pre[vertex]; v !=vertex; v=pre[v])
                    newVertex[v] = num;
            }
        }
        if(!num) //无环，答案已找到
            break;
        for(int i=1; i<=V; i++)
            if(newVertex[i] == -1)
                newVertex[i] = ++num;
        for(int i=1; i<=E; i++) //为新点标号，并且更新对应权值
        {
            int start = edge[i].start,end = edge[i].end;
            edge[i].start = newVertex[start];
            edge[i].end = newVertex[end];
            if(edge[i].start != edge[i].end)
                edge[i].cost -= minCost[end];
        }
        V = num;
        root = newVertex[root];
    }
    return ret;
}

int main()
{
    while(~scanf("%d%d",&V,&E))
    {
        if(!V && !E)
            break;
        for(int i=1; i<=E; i++)
            scanf("%d%d%d",&edge[i].start,&edge[i].end,&edge[i].cost);
        int ans = directed_mst();
        if(ans == -1)
            printf("impossible\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
