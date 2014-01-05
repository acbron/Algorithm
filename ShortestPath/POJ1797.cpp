/*Shortest path problem
 *using Dijkstra algorithm
 *using priority queue to reduce time to O((E+V)*lgV)
 *                          -- By GentleH
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int SIZE = 1024;
const int INF = 1000000;

struct node
{
    int to,val,next;
}edge[SIZE*SIZE];
int head[SIZE],idx;

struct heapNode
{
    int val,v;
    heapNode(){}
    heapNode(int val,int v):val(val),v(v){}
    bool operator < (const heapNode &rhs)const
    {
        return val < rhs.val;
    }
};

int cas,n,m;
int vis[SIZE];
priority_queue <heapNode> Q;

void addEdge(int from,int to,int val)
{
    edge[idx].to = to;
    edge[idx].val = val;
    edge[idx].next = head[from];
    head[from] = idx++;
}

int dijkstra()
{
    while(!Q.empty())
        Q.pop();
    memset(vis,0,sizeof(vis));
    Q.push(heapNode(INF,1));
    while(!Q.empty())
    {
        heapNode cur = Q.top();
        Q.pop();
        if(vis[cur.v])continue;
        vis[cur.v] = 1;
        if(cur.v == n)
            return cur.val;
        for(int i=head[cur.v]; i!=-1; i=edge[i].next)
        {
            int to = edge[i].to,val = edge[i].val;
            if(vis[to])continue;
            val = min(val,cur.val);
            Q.push(heapNode(val,to));
        }
    }
    return -1;
}

void read()
{
    scanf("%d%d",&n,&m);
    idx = 0;
    memset(head,-1,sizeof(head));
    int u,v,val;
    for(int i=1; i<=m; i++)
    {
        scanf("%d%d%d",&u,&v,&val);
        addEdge(u,v,val);
        addEdge(v,u,val);
    }
}

int main()
{
    scanf("%d",&cas);
    for(int c=1; c<=cas; c++)
    {
        read();
        int ans = dijkstra();
        printf("Scenario #%d:\n",c);
        printf("%d\n\n",ans);
    }
    return 0;
}

