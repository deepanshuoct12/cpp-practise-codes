#include<bits/stdc++.h>
using namespace std;

vector<int> parent;
//FIND operation
int find(int v)
{
	if(parent[v]==-1)
		return v;
	return find(parent[v]);
}

void union_op(int fromP,int toP)
{
	fromP = find(fromP);
	toP = find(toP);
	parent[fromP] = toP;
}

bool isCyclic(vector<pair<int,int> >& edge_List)
{
	for(auto p: edge_List)
	{
		int fromP = find(p.first);	//FIND absolute parent of subset
		int toP = find(p.second);

		if(fromP == toP)
			return true;

		//UNION operation
		union_op(fromP,toP);	//UNION of 2 sets
	}
	return false;
}

int main()
{
	int E;	//No of edges
	int V;	//No of vertices (0 to V-1)
	cin>>E>>V;

	parent.resize(V,-1);	//Mark all vertices as separate subsets with only 1 element
	vector<pair<int,int>> edge_List;	//Adjacency list
	for(int i=0;i<E;++i)
	{
		int from,to;
		cin>>from>>to;
		edge_List.push_back({from,to});
	}

	if(isCyclic(edge_List))
		cout<<"TRUE\n";
	else
		cout<<"FALSE\n";

	return 0;
}

//TIME COMPLEXITY: O(E.V)
