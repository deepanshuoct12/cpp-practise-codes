void dfs(int src,vector<bool>&visited,vector<int>graph[],vector<int>&topsort)
{
	visited[src]=1;
	for(auto nbr:graph[src])
	{
		if(!visited[nbr])
			dfs(nbr,visited,graph,topsort);
	}
	topsort.push_back(src);
}
void rev_dfs(int node,vector<bool>&visited,vector<int>rev_graph[],vector<int>&temp)
{
	visited[node]=true;
	temp.push_back(node);
	for(auto nbr:rev_graph[node])
	{
		if(!visited[nbr])
		{
			rev_dfs(nbr,visited,rev_graph,temp);
		}
	}
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
	int e=edges.size();
	vector<int>graph[n],rev_graph[n];
	for(int i=0;i<e;i++){
		int u=edges[i][0];
		int v=edges[i][1];
		graph[u].push_back(v);
		rev_graph[v].push_back(u);
	}
	
	vector<int>topsort;
	vector<bool>visited(n,false);
	for(int i=0;i<n;i++){
		if(!visited[i])
		{
			dfs(i,visited,graph,topsort);
		}
	}
	reverse(topsort.begin(),topsort.end());
	for(int i=0;i<visited.size();i++)
	{
		visited[i]=false;
	}
	vector<vector<int>>ans;
	for(int i=0;i<topsort.size();i++)
	{
		
		if(!visited[topsort[i]])
		{vector<int>temp;
			rev_dfs(topsort[i],visited,rev_graph,temp);
		 ans.push_back(temp);
		}
	}
	return ans;
    // Write your code here.
}