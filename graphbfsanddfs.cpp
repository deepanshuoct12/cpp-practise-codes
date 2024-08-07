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
             cout<<i.first<<"-->";
               for(T entry : i.second)
                     {cout<<entry<<",";
                     }
                     cout<<"\n";
        }

    }


    void dfs(T src)
     {

         map<T,bool> visited;
         int componenet =1;
          list<T> ordering;
         dfshelper(src,visited,ordering);

         for(auto i:adjlist)
         {
             T city = i.first;
             if(!visited[city])
             {
                 dfshelper(city,visited,ordering);
             }
         }
     }

     void dfstopologicalsort()
     {

         list<T>ordering;
         map<T,bool> visited;
         for(auto i : adjlist)
         {  T node = i.first;
             if(visited[node]==false)
             {
                 dfshelper(node ,visited,ordering);
             }
         }

         for(auto element : ordering)
           {
               cout<<element<<"-->";
           }

     }

    void bfs(T src)
    {
         queue<T>q;
        map<T,bool> visited;
        map<T,int>distance;
        map<T,T>parent;
        q.push_back(src);
        visited[src]=true;

        while(!q.empty())
        {
            T node=q.front();
            cout<<node<<" ";
            q.pop();

            for(auto neighbour: adjlist[node])
            {
                if(!visited[neighbour])
                {
                    q.push_back(neighbour);
                    visited[neighbour]=true;
                }
            }
        }
    }

      void bfstopologicalsort()
      {
          map<T,bool>visited;
          queue<T>q;
          map<T,int>indegree;

          for(auto i:adjlist)
          {    T node = i.first;
              indegree[node]=0;
          }

          for(auto i: adjlist)
          {
              T u=i.first;
              for(T v:adjlist[u])
                indegree[v]++;
          }

          for(auto i :adjlist)
          {
              if(indegree[i.first]==0)
                q.push(i.first);
          }
          while(!q.empty())
          {

              T node = q.front();
              cout<<node<<"-->";
              q.pop();

              for(auto i: adjlist[node])
              {
                  indegree[i]--;

                  if(indegree[i]==0)
                    q.push(i);
              }
          }
      }
};

int main()
{

    Graph<int> g;

    g.addedge(0,1,false);
   g.addedge(0,4,false);
   g.addedge(4,3,false);
   g.addedge(1,4,false);
   g.addedge(1,2,false);
   g.addedge(2,3,false);

     g.dfs(0);
     g.print();

}

