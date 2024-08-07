#include<iostream>
#include<vector>
using namespace std;

using namespace std;
void connectedcomponents2(int **adj,int V,int start,vector<bool>&visited)
{
//  if(visited[start])
  //  return v;
 // int k=0;
  //v.push_back(start);
  visited[start]=true;

  for(int i=1;i<=V;i++)
  {
      if(i==start)
          continue;

  else if(adj[start][i]==1&&visited[i]==false)
    {
     // visited[start]=true;
     // int *ans=new int [V];
     connectedcomponents2(adj,V,i,visited);
    }

  }
 // arr[k]=nullptr;

}


/* void connectedcomponents(int **adj,int V)
 {
     vector<bool>visited(V,false);
  // int size2=V;
   //int *arr=new int[size2];
 //  int *arr=new int[size2];
 //  int j=0;

   for(int i=0;i<V;i++)
   {
     if(visited[i]==false){
       vector<int> v;
       connectedcomponents2(adj,V,i,visited,v);
       sort(v.begin(),v.end());

       for(int i=0;i<v.size();i++)
         cout<<v[i]<<" ";
       cout<<endl;

       }
     }
}*/
/*void dfs(int **adj,int n,int start,vector<bool>&visited)
{
  if(visited[start])return;

  visited[start]=true;

  for(int i=1;i<=n;i++)
  {
    if(adj[start][i]==1&&visited[i]==false)
    {
      visited[i]=true;
      dfs(adj,n,i,visited);
    }
  }
}*/
int solve(int n,int m,vector<int>u,vector<int>v)
{

  int **adj=new int*[n];
  for(int i=1;i<=n;i++)
  {
    adj[i]=new int[n];
    for(int j=1;j<=n;j++)
    {
      adj[i][j]=0;
    }

  }
  for(int i=0;i<n;i++)
  { //int c=0;
   // for(int j=0;j>n;j++)

      adj[u[i]][v[i]]=1;
      adj[v[i]][u[i]]=1;


  }
  int c=0;
  vector<bool> visited(n,false);
  for(int i=1;i<=n;i++)
  {
    if(visited[i]==false)
    {
      connectedcomponents2(adj,n,i,visited);
     // c++;
    }
      c++;
  }
	return c;
}// Write your code here .
int main()
{
	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		u.push_back(x);
	}
	for(int i=0;i<m;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(n,m,u,v)<<endl;
}
