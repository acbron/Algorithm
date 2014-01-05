/*Shortest path problem
 *using Dijkstra algortim
 *use priority_queue as data structure
 *                --by GentleH
 */
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int SIZE = 128;

struct node
{
    int to,cost,val,next;
}edge[SIZE*SIZE];
int head[SIZE],idx;

struct heapNode
{
    int dis,v,cost;
    heapNode(){}
    heapNode(int d,int v,int c):dis(d),v(v),cost(c){}
    bool operator < (const heapNode &rhs) const
    {
        return dis > rhs.dis;
    }
};

int money,n,r;
priority_queue <heapNode> Q;

void addEdge(int from,int to,int cost,int val)
{
    edge[idx].to = to;
    edge[idx].cost = cost;
    edge[idx].val = val;
    edge[idx].next = head[from];
    head[from] = idx++;
}

void read()
{
    idx = 0;
    memset(head,-1,sizeof(head));
    int start,end,cost,val;
    for(int i=1; i<=r; i++)
    {
        scanf("%d%d%d%d",&start,&end,&val,&cost);
        addEdge(start,end,cost,val);
    }
}

int dijkstra()
{
    while(!Q.empty())
        Q.pop();
    Q.push(heapNode(0,1,0));
    while(!Q.empty())
    {
        heapNode cur = Q.top();
        Q.pop();
        if(cur.v == n)
            return cur.dis;
        for(int i=head[cur.v]; i!=-1; i=edge[i].next)
        {
            int to = edge[i].to;
            int cost = edge[i].cost;
            int val = edge[i].val;
            if(cur.cost + cost <= money)
            {
                Q.push(heapNode(cur.dis+val,to,cur.cost+cost));
            }
        }
    }
    return -1;
}

int main()
{
    while(~scanf("%d%d%d",&money,&n,&r))
    {
        read();
        int ans = dijkstra();
        printf("%d\n",ans);
    }
    return 0;
}

