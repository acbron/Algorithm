/*
 * Vertices为点的总数
 * inDegree[v]为点v的入度
 * cnt[u][v]表示存在由u指向v的边
 * Queue为队列
 */

//BFS
int topologicalSort()
{
	for(int v=1; v<=Vertices; v++)
		if(inDegree[v] == 0)
			Queue.push(v);
	int num = 0;
	if((int)Queue.size() > 1)
		return 0; //拓扑排序不唯一
	while(!Queue.empty())
	{
		int cur = Q.front();
		Q.pop();
		num++;
		for(int v=1; v<=Vertices; v++)
		{
			if(cnt[cur][v])
				--inDegree[v];
			if(inDegree[v] == 0)
				Queue.push(v);
		}
	}
	if(num < Vertices)
		return -1; //有环
	else
		return true
}

//DFS
//ans[]存储拓扑序列,vis[v]记录点v是否已被访问
void topologicalSort(int len)
{
	if(len == Vertices)
	{
		for(int i=0; i<len; i++)
			printf("%d",ans[i]);
		printf("\n");
		return;
	}
	for(int i=1; i<=Vertices; i++)
	{
		if(!vis[i] && inDegree[i] == 0)
		{
			for(int v=1; v<=Vertices; v++)
				if(cnt[i][v])
					--inDegree[v];
			vis[i] = true;
			ans[len] = i;
			topologicalSort(len+1);
			for(int v=1; v<=Vertices; v++)
				if(cnt[i][v])
					++inDegree[v];
			vis[i] = true;
		}
	}
}

