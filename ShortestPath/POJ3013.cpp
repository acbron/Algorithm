/*Shortest ploblem
 *using SPFA
 *           -- By GentleH
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long LL;
const int SIZE = 150050;

struct node
{
    int to,val,next;
}edge[SIZE<<2];
int head[SIZE],idx;

int cas,n,m;
int weight[SIZE];
LL dis[SIZE];
bool in_queue[SIZE];
queue <int> Q;

void addEdge(int from,int to,int val)
{
    edge[idx].to = to;
    edge[idx].val = val;
    edge[idx].next = head[from];
    head[from] = idx++;
}

void read()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        scanf("%d",&weight[i]);
    idx = 0;
    memset(head,-1,sizeof(head));
    int u,v,w;
    for(int i=1; i<=m; i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        addEdge(u,v,w);
        addEdge(v,u,w);
    }
}

void spfa()
{
    while(!Q.empty())
        Q.pop();
    for(int i=1; i<SIZE; i++)
        dis[i] = -1,in_queue[i] = false;
    dis[1] = 0,in_queue[1] = true;
    Q.push(1);
    while(!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        in_queue[cur] = false;
        for(int i=head[cur]; i!=-1; i=edge[i].next)
        {
            int to = edge[i].to,val = edge[i].val;
            if(dis[to] == -1 || dis[to] > dis[cur] + val)
            {
                dis[to] = dis[cur] + val;
                if(!in_queue[to])
                {
                    Q.push(to);
                    in_queue[to] = true;
                }
            }
        }
    }
}

int main()
{
    scanf("%d",&cas);
    while(cas--)
    {
        read();
        if(n <= 1)
        {
            puts("0");
            continue;
        }
        spfa();
        LL ans = 0;
        bool noAns = false;
        for(int i=2; i<=n; i++)
        {
            if(dis[i] == -1)
            {
                noAns = true;
                break;
            }
            ans += dis[i]*(LL)weight[i];
        }
        if(!noAns)cout << ans << endl;
        else puts("No Answer");
    }
    return 0;
}

