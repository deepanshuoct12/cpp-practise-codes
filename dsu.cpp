
#include<bits/stdc++.h>
using namespace std;
void init_code(){
   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
int findparent(int i,int parent[])
{
   // if(parent[i]==-1)
      if(parent[i]==i)
        return i;
    return parent[i]=findparent(parent[i],parent);
}
void Union(int x,int y,int parent[],int rank[])
{
    int p1=findparent(x,parent);
    int p2=findparent(y,parent);

    //if(p1!=p2)
    //{
      if(rank[p1]<rank[p2])
        {
            parent[p1]=p2;
            rank[p2]++;
        }
      else
        {
            parent[p2]=p1;
            rank[p1]++;
        }
//    }
}
bool containcycle(vector<pair<int,int> >graph,int n,int e)
{
    int parent[n+1];
    int rank[n+1];
    bool ans=false;
    for(int i=1;i<=n;i++)
    {
        //    parent[i]=-1;
              rank[i]=1;
              parent[i]=i;
    }
    for(int i=0;i<e;i++)
    {
        int x=graph[i].first;
        int y=graph[i].second;
            int p1=findparent(x,parent);   //doubt
            int p2=findparent(y,parent);
            if(p1==p2)
            ans=true;
            else
                Union(x,y,parent,rank);
    }
    for(int i=1;i<=n;i++)
        cout<<parent[i]<<" ";
   return ans;//false;
}

int main()
{
    init_code();
    int n,e;
    cin>>n>>e;
    vector<pair<int,int> >graph;
    for(int i=0;i<e;i++)
    {
       int x,y;
       cin>>x>>y;
      graph.push_back({x,y});
    }

    bool ans=containcycle(graph,n,e);
     if(ans)
        cout<<"yes";
      else 
        cout<<"no";

    return 0;
}
////////////////////apaaaaaar///////////////
struct dsu {
    vector<int> p, sz;
    int comp;
    void init(int NN) {
        sz.clear(); p.clear();
        p.resize(NN); sz.resize(NN, 1);
        iota(p.begin(), p.end(), 0);
        comp = NN;
    }
    int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }
    void unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            p[x] = y;
            sz[y] += sz[x];
            sz[x] = 0;
            comp--;
        }
    }
} G;
