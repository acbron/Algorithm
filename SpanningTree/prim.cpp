/*
 *  Prim Algorithm
 *  By using binary-heap(min heap),the time complexity is O(ElogV)
 */

//const int SIZE_V = the possibility numbers of vertices
//const int SIZE_E = the possibility numbers of edges

typedef pair<int,int> pii;

//min-heap,it will firstly consider the first element of pair<int,int>,then the second
priority_queue < pii,vector<pii>,greater<pii> > Q;

//cost[i] means when we add the vertex i in to the spanning tree,it costs cost[i] weight
int cost[SIZE_V];
bool vis[SIZE_V];//check wheter the vertex is added into the spanning tree

//the following struct node and array head[] performs as list,which record the connection of the graph
struct node
{
	int to,next,weight;
}edge[SIZE_E];

int head[SIZE],idx; //head[] is initialize to -1, idx is to 0

void addEdge(int from,int to,int weight)
{
	edge[idx].to = to;
	edge[idx].weight = weight;
	edge[idx].next = head[from];
	head[from] = idx++;
}

int prim()
{
	int ret = 0; //the total cost of making a minimun spanning tree
	//initial the cost[] as infinite weight, and all of the vertices is not added into the spanning tree
	for(int i=0; i<SIZE_V; i++)
		cost[i] = INF,vis[i] = false;
	//we consider the vertex 0 is root,in this step,it costs 0 weight
	Q.push(make_pair(0,0)); // the first 0 is the weight,and the second is the vertex number
	while(!Q.empty())
	{
		pii cur = Q.top();
		Q.pop();
		if(!vis[cur.second])
		{
			ret += cur.first;
			vis[cur.second] = true;
		}
		for(int i=head[cur.second]; i!=-1; i=edge[i].next)
		{
			int to = edge[i].to;
			if(!vis[to] && edge[i].weight < cost[to])
				Q.push(make_pair(edge[i].weight,to));
		}
	}
	return ret;
}

