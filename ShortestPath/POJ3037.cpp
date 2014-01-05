/*Shortest path problem
 *using Dijkstra algoritm
 *using priority queue
 *                -- By GentleH
 *63MS
 */
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int SIZE = 128;
const double INF = 999999999999.99;

int X[4] = {1,-1,0,0};
int Y[4] = {0,0,1,-1};

struct heapNode
{
    int x,y;
    double time,speed;
    heapNode(){}
    heapNode(int x,int y,double t,double s):
        x(x),y(y),time(t),speed(s){}
    bool operator < (const heapNode &rhs) const
    {
        return time > rhs.time;
    }
};

double V;
int R,C;
int maze[SIZE][SIZE];
double dis[SIZE][SIZE];
bool vis[SIZE][SIZE];
priority_queue <heapNode> Q;

void read()
{
    for(int i=1; i<=R; i++)
        for(int j=1; j<=C; j++)
            scanf("%d",&maze[i][j]);
}

double dijkstra()
{
    while(!Q.empty())
        Q.pop();
    memset(vis,0,sizeof(vis));
    for(int i=0; i<SIZE; i++)
        for(int j=0; j<SIZE; j++)
            dis[i][j] = INF;
    Q.push(heapNode(1,1,0.0,V));
    dis[1][1] = 0;
    while(!Q.empty())
    {
        heapNode cur = Q.top();
        Q.pop();
        if(cur.x == R && cur.y == C)
            return cur.time;
        //if(vis[cur.x][cur.y])continue;
        vis[cur.x][cur.y] = true;
        for(int i=0; i<4; i++)
        {
            int tx = cur.x + X[i];
            int ty = cur.y + Y[i];
            if(tx < 1 || tx > R || ty < 1 || ty > C)
                continue;
            if(dis[tx][ty] > dis[cur.x][cur.y] + (1.0/cur.speed) && !vis[tx][ty])
            {
                dis[tx][ty] = dis[cur.x][cur.y] + (1.0/cur.speed);
                int tmp = maze[cur.x][cur.y]-maze[tx][ty];
                double sp = cur.speed*pow(2.0,tmp+0.0);
                //cout << tx << " " << ty << " " << sp << " " << dis[tx][ty] << endl;
                Q.push(heapNode(tx,ty,dis[tx][ty],sp));
            }
        }
    }
    return -1;
}

int main()
{
    while(~scanf("%lf%d%d",&V,&R,&C))
    {
        read();
        double ans = dijkstra();
        printf("%.2lf\n",ans);
    }
    return 0;
}


/*Shortest path problem
 *using SPFA
 *         -- By GentleH
 *454MS
 */
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int SIZE = 128;
const double INF = ((long long)1<<60);

struct node
{
    int x,y;
    double time,speed;
    node(){}
    node(int x,int y,double t,double s):
        x(x),y(y),time(t),speed(s){}
};

int X[4] = {1,-1,0,0};
int Y[4] = {0,0,1,-1};

double V;
int R,C;
int maze[SIZE][SIZE];
double cost[SIZE][SIZE];
bool in_queue[SIZE][SIZE];
queue <node> Q;

void read()
{
    scanf("%lf%d%d",&V,&R,&C);
    for(int i=1; i<=R; i++)for(int j=1; j<=C; j++)
        scanf("%d",&maze[i][j]);
}

void spfa()
{
    while(!Q.empty())
        Q.pop();
    for(int i=1; i<=R; i++)for(int j=1; j<=C; j++)
        in_queue[i][j] = false,cost[i][j] = INF;
    Q.push(node(1,1,0.0,V));
    cost[1][1] = 0;
    in_queue[1][1] = true;
    while(!Q.empty())
    {
        node cur = Q.front();
        Q.pop();
        in_queue[cur.x][cur.y] = false;
        for(int i=0; i<4; i++)
        {
            int tx = cur.x + X[i];
            int ty = cur.y + Y[i];
            if(tx < 1 || tx > R || ty < 1 || ty > C)
                continue;
            if(cost[tx][ty] > cost[cur.x][cur.y]+1.0/cur.speed)
            {
                cost[tx][ty] = cost[cur.x][cur.y]+1.0/cur.speed;
                int tmp = maze[cur.x][cur.y]-maze[tx][ty];
                double sp = cur.speed*pow(2.0,tmp+0.0);
                if(!in_queue[tx][ty])
                    Q.push(node(tx,ty,cost[tx][ty],sp));
            }
        }
    }
}

int main()
{
    read();
    spfa();
    printf("%.2lf\n",cost[R][C]);
    return 0;
}
