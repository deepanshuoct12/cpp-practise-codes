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
             cout<<i.first;
               for(T entry : i.second)
                     {cout<<entry<<",";
                     }
        }
        cout<<"\n";
    }

     bool dfscycle(T src, map<T,bool> &visited,T parent)
     {
         visited[src]=true;

         for(auto neighbour : adjlist[src])
         {
             if(!visited[neighbour])
             {
                bool cycle=dfscycle(neighbour,visited,src);
                if(cycle)
                    return true;
             }

             else if(visited[neighbour] && neighbour!=parent)
             {  return true;

             }
         }
          return false;
     }
    void dfsdetectcycle()
     {

         map<T,bool> visited;

         for(auto i:adjlist)
         {
             T node = i.first;
             if(!visited[node])
             {
                 bool ans =dfscycle(node,visited,node);
                 if(ans)
                    cout<<"true"<<"\n";
                  else
                    cout<<"false"<<"\n";
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

    bool bfscycle(T src)
    {
         queue<T>q;
        map<T,bool> visited;
        map<T,int>distance;
        map<T,T>parent;
        q.push(src);
        visited[src]=true;
        parent[src]=src;
        while(!q.empty())
        {
            T node=q.front();
            //cout<<node<<" ";
            q.pop();

            for(auto neighbour: adjlist[node])
            {
                if(visited[neighbour]==true && parent[node]!=neighbour)
                {
                    return true;

                }
                else if(visited[neighbour]==false)
                {
                    parent[node]=neighbour;
                     q.push(neighbour);
                    visited[neighbour]=true;
                }
            }
        }

        return false;
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

    g.addedge(1,2);
   g.addedge(1,4);
   g.addedge(4,3);
   g.addedge(2,3);

     g.dfsdetectcycle();

}

