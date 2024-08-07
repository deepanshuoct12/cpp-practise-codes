#include<iostream>
#include<list>
#include<map>
#include<iterator>
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

    void addedge(T u,T v,bool value = true)
    {
        if(value==true)
        adjlist[u].push_back(v);

        else if(value == false)
        {
            adjlist[v].push_back(u);
        }
    }

    void print()
    {

        for(auto i:adjlist)
        {
             cout<<i.first<<"-->";
               for(T entry : i.second)
                     {
                         cout<<entry<<",";
                     }
                     cout<<"\n";
        }

    }

     void dfshelper(T src, map<T,bool> &visited)
     {
         visited[src]=true;
         //cout<<src<<" ";

         for(auto i : adjlist[src])
         {
             if(!visited[i])
             {
                 dfshelper(i,visited);
             }
         }


     }

    void dfs(T src)
     {
           int components = 1;
         map<T,bool> visited;
         dfshelper(src,visited);
         cout<<"\n";

         for(auto i : adjlist)
         {
             if(!visited[i.first]){
                dfshelper(i.first,visited);
                components++;
                }

         }
         cout<<"\n The no. of components are: "<<components<<"\n";
     }



};

int main()
{

    Graph<int> g;

   g.addedge(0,1,true);
   g.addedge(0,4,true);
   g.addedge(4,3,true);
   g.addedge(1,4,true);
   g.addedge(1,2,true);
   g.addedge(2,3,true);
   g.addedge(5,6,true);

g.dfs(0);

}
