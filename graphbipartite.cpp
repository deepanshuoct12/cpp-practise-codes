#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph{

int V;
list<int>*l;
public:
Graph(int v)
{   V=v;
    l=new list<int>[v];
}

void addedge(int u,int v,bool bidir=true)
{
    l[u].push_back(v);
    if(bidir)
    {
        l[v].push_back(u);
    }
 //   cout<<u<<":"<<v<<"\n";
}

void print()
{

    for(int i=0;i<V;i++)
    {
        cout<<i<<"->";

        for(int vertex : l[i])
        {
            cout<<vertex<<",";
        }
        cout<<"\n";
    }

}

bool isbipartite(int src)
{

    int *color =new int[V];

    for(int i=0;i<V;i++)
        color[i]=-1;

    color[src]=0;

    queue<int> q;

    q.push(src);
    while(!q.empty())
    {

        int u =q.front();
        q.pop();

        for(auto v : l[u])
        {
            if(color[v]==-1)
            {

                color[v]=1-color[u];
                q.push(v);
            }
            else if(color[u]==color[v])
            {
                return false;

            }
        }

    }
        return true;
}

};

int main()
{

    Graph g(4);

   g.addedge(0,1);
   g.addedge(2,0);
   g.addedge(1,3);
   g.addedge(2,3);

   bool ans=g.isbipartite(0);
   if(ans==true)
    cout<<"yes";
   else if(ans==false)
    cout<<"no";
}

