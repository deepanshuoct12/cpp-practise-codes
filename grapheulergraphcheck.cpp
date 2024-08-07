#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int>adj[100000];

void dfs(int curr,vector<int>&visited)
{
    visited[curr]=1;

    for(auto nbr:adj[curr])
    {
        if(!visited[nbr])
            dfs(nbr,visited);
    }
}
bool connected(int n)
{
      int node=-1;
    for(int i=0;i<n;i++)
    {
      if(adj[i].size()>0)
        {
            node=i;
            break;
        }
    }
    if(node==-1)
        return true;
    vector<int>visited(n,0);
    dfs(node,visited);

    for(int i=0;i<n;i++)
    {
        if(!visited[i] && adj[i].size()>0)
        return false;

    }
  return true;

}
int findeuler(int n)
{

    if(!connected(n))
        return 0;
        int odd=0;
   for(int i=0;i<n;i++)
   {
       if(adj[i].size()&1)
        odd++;
   }

   if(odd>2)
    return 0; //not euler

   if(odd=0)
    return 2;  // euler

    return 1; // semi euler

}
void findEuler_Path_Cycle(int n)
{
    int res=findeuler(n);

    if(res==0)
        cout<<"Not euler";
    else if(res==1)
        cout<<"Semi euler";
    else
        cout<<"euler";

}
int main()
{
    adj[0].pb(1);
	adj[1].pb(0);
	adj[0].pb(2);
	adj[2].pb(0);
	adj[2].pb(1);
	adj[1].pb(2);
	adj[0].pb(3);
	adj[3].pb(0);
	adj[3].pb(4);
	adj[4].pb(3);
	int n=5;
	findEuler_Path_Cycle(n);

	return 0;
}
