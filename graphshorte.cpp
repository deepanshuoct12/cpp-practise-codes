#include<iostream>
#include<list>
#include<map>
#include<iterator>
#include<climits>
#include<queue>
using namespace std;
template < typename T>

class Graph
{
    map<T,list<T> >adjlist;

public:

    Graph()
    {
    }

    void addedge(T u,T v,bool bidir = true)
    {
        adjlist[u].push_back(v);

        if(bidir)
        {
            adjlist[v].push_back(u);
        }
    }

    void print()
    {
//        template<typename T>
      /*  map<T,list<T> >::iterator it;
        for(it = adjlist.begin() ;it!=adjlist.end() ;it++)
        {
            cout<<it->first<<"->"<<it->second;
        }*/
        for(auto i:adjlist)
        {
             cout<<i.first;
               for(T entry : i.second)
                     {cout<<entry<<",";
                     }
        }
        cout<<"\n";
    }

    void bfs(T src)
    {
         queue<T>q;
        map<T,bool> visited;
        map<T,T>parent;
        map<T,int>dist;

        q.push(src);
        visited[src]=true;
        parent[src]=src;
         for(auto i:adjlist)
         {
             dist[i.first]=-1;
         }
          dist[src]=0;

        while(!q.empty())
        {
            T node=q.front();
            cout<<node<<" ";
            q.pop();

            for(auto neighbour: adjlist[node])
            {
                if(dist[neighbour]==INT_MAX)
                {
                    q.push(neighbour);
                    dist[neighbour]=dist[node]+1;
                   // visited[neighbour]=true;
                    parent[neighbour]=node;
                }
            }

        }
            for(auto i: adjlist)
            {
                T node = i.first;
                cout<<"distance of  "<<node<<"from "<<src<<"is"<<dist[node]<<"\n";
            }

    }
};

int main()
{

    Graph<int> g;

    g.addedge(0,1);
   g.addedge(0,4);
   g.addedge(4,3);
   g.addedge(1,4);
   g.addedge(1,2);
   g.addedge(2,3);

     g.bfs(0);

}
