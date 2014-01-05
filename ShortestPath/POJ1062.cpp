//shortest path, dijkstra
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int SIZE = 128;
const int INF = 0xfffffff;

struct node
{
    int val,num,lev;
}man[SIZE];

struct Edge
{
    int to,next,val;
}edge[SIZE*SIZE];
int head[SIZE],idx;

int n,m;
int dist[SIZE],vis[SIZE];

void addEdge(int from,int to,int val)
{
    edge[idx].to = to;
    edge[idx].val = val;
    edge[idx].next = head[from];
    head[from] = idx++;
}

void read()
{
    idx = 0;
    memset(head,-1,sizeof(head));
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d%d",&man[i].val,&man[i].lev,&man[i].num);
        for(int j=1; j<=man[i].num; j++)
        {
            int who,val;
            scanf("%d%d",&who,&val);
            addEdge(who,i,val);
        }
    }
}

int dijkstra()
{
    int ret = INF;
    for(int d=man[1].lev-m; d<=man[1].lev; d++)
    {
        int l = d, r = d+m;
        for(int i=1; i<=n; i++)
        {
            vis[i] = 0;
            if(man[i].lev >= l && man[i].lev <= r) dist[i] = man[i].val;
            else dist[i] = INF;
        }
        for(int i=1; i<=n; i++)
        {
            int mini = INF,who;
            for(int j=1; j<=n; j++)if(dist[j] < mini && !vis[j])
            {
                mini = dist[j];
                who = j;
            }
            vis[who] = 1;
            for(int j=head[who]; j!=-1; j=edge[j].next)
            {
                int to = edge[j].to,val = edge[j].val;
                if(dist[to] > dist[who] + val && man[to].lev >= l && man[to].lev <= r)
                    dist[to] = dist[who] + val;
            }
        }
        ret = min(ret,dist[1]);
    }
    return ret > 10000?10000:ret;
}

int main()
{
    while(~scanf("%d%d",&m,&n))
    {
        read();
        int ans = dijkstra();
        printf("%d\n",ans);
    }
    return 0;
}

