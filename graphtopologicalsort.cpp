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

        for(auto i:adjlist)
        {
             cout<<i.first<<"-->";
               for(T entry : i.second)
                     {cout<<entry<<",";
                     }
                     cout<<"\n";
        }

    }

     void dfshelper(T src, map<T,bool> &visited,list<T> &ordering)
     {
         visited[src]=true;
         cout<<src<<" ";

         for(auto i : adjlist[src])
         {
             if(!visited[i])
             {
                 dfshelper(i,visited,ordering);
             }
         }

         ordering.push_front(src);
     }


     void dfstopologicalsort()
     {

         list<T>ordering;
         map<T,bool> visited;
         for(auto i : adjlist)
         {  T node = i.first;
             if(!visited[node])
             {
                 dfshelper(node ,visited,ordering);
             }
         }

         for(auto element : ordering)
           {
               cout<<element<<"-->";
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

