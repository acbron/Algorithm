/*
 * Kruskal Algorithm
 * Time complexity: O(ElogV)
 */

//const int SIZE_E  = the possibility numbers of edges
//const int SIZE_V = the possibility numbers of vertices

//the struct records the infomation of each edge
struct Edge
{
	int start,end,weight;
}edge[SIZE_E];

//boolean function for sorting the struct Edge
bool cmp(Edge a,Edge b)
{
	return a.weight < b.weight;
}

//union-find set, which is used to check whether the vertices of the end
//of the edge have been added to the spanning tree
int father[SIZE_V];

//using recursion to find x's ancester
int find(int x)
{
	if(x != father[x])
		father[x] = find(father[x]);
	return father[x];
}

//union operation
bool Union(int x,int y)
{
	x = find(x);
	y = find(y);
	if(x != y)
	{
		father[x] = y;
		return true;
	}
	return false;
}

int kruskal()
{
	int ret = 0;//record the sum of weight after completing the spanning tree
	//sort edge weight by increasing order..
	for(int i=0; i<SIZE_V; i++)
		father[i] = i; //initialize every vertices' father is themselves
	sort(edge+1,edge+1+all,cmp);
	for(int i=1; i<=all; i++)
	{
		if(Union(edge[i].start,edge[i].end))
			ret += edge[i].weight;
	}
	return ret;
}
