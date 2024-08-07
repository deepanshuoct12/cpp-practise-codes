#include<bits/stdc++.h>
using namespace std;

 vector<int>parent;
    vector<vector<int> > edges;
    int find(int x)
    {
        return parent[x]=parent[x]==x?x:find(parent[x]);
    }
    void Union(int x,int y)
    {
        int p1=find(x);
        int p2=find(y);

        if(p1!=p2)
            parent[p1]=p2;
    }
    bool comp(vector<int>&a,vector<int>&b)
    {
        return a[2]<b[2];
    }
    vector<vector<int> > kruskal(int n)
    {
        sort(edges.begin(),edges.end(),comp);
        int i=0;
        int ans=0;
        int cnt=0;
        vector<vector<int> > output;
        while(cnt<n-1)
        {
            vector<int>curr=edges[i];

            int p1=find(curr[0]);
            int p2=find(curr[1]);

            if(p1!=p2)
            {
                Union(p1,p2);
                output.push_back(curr);
                cnt++;
            }
            i++;
        }
        return output;
}

int main(){
    int n,e;
    cin>>n>>e;

    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }

    vector<int> ans=kruskal(n);

    for(auto x:ans)
    cout<<x<<" ";

return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
/*int findparent(int i,int parent[])
{
    if(parent[i]==-1)
        return i;
    return parent[i]=findparent(parent[i],parent);
}
void Union(int x,int y,int parent[],int Rank[])
{
    int p1=findparent(x,parent);
    int p2=findparent(y,parent);
    if(p1!=p2)
    {
        if( Rank[p1]< Rank[p2])
        {
            parent[p1]=p2;
             Rank[p2]++;
        }
        else
        {
            parent[p2]=p1;
            Rank[p1]++;
        }

    }
}
bool cmp(vector<int> a,vector<int> b)
{

    return a[2]<b[2];
}
vector<int> kruskal(vector<vector<int> > edge,int n)
{
    int parent[n+1];
    int  Rank[n+1];
    for(int i=1;i<=n;i++)
    {
        parent[i]=-1;
        Rank[i]=1;
    }

    sort(edge.begin(),edge.end(),cmp);
    int cnt=0;
    int i=0;
    vector<int>output;

    while(cnt<n-1)
    {
        int u=edge[i][0];
        int v=edge[i][1];
        int w=edge[i][2];
        int p1=findparent(u,parent);
        int p2=findparent(v,parent);

        if(p1!=p2)
        {
            output.push_back(w);
            Union(p1,p2,parent,Rank);
            cnt++;
        }
        i++;
    }
    return output;
}*/
