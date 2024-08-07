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
    bool dfs(T src)
     {

         map<T,bool> visited;
        //  visited[src]=false;
         for(auto i : adjlist)
         {
             visited[i.first]=false;
             cout<<i.first<<","<<" ";
             cout<<visited[i.first]<<"\n";
           /*  if(i.second!=1)
                return false;*/
         }
         cout<<"\n";
         dfshelper(src,visited);

         /*for(auto i:adjlist)
         {
             T city = i.first;
             if(!visited[city])
             {
                 dfshelper(city,visited);
             }
         }*/

         for(auto i : visited)
         {
             cout<<i.second<<"::";
             if(i.second==0)
                return false;
         }
        return true;
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

template<typename T>
 bool strongconnected(T src,Graph<T> g,Graph<T> g2){

     bool ans=true,ans2 = true;
     ans = g.dfs(src);
     //  cout<<ans<<"}"<<false;
      if(ans==false)
            return false;
       cout<<"\n";
      ans2 = g2.dfs(src);

      if(ans2==false)
        return false;

      return true;
}
int main()
{

    Graph<int> g,g2;

   g.addedge(0,1,true);
   g.addedge(0,4,true);
   g.addedge(4,3,true);
   g.addedge(1,4,true);
   g.addedge(1,2,true);
   g.addedge(2,3,true);

   g2.addedge(0,1,false);
   g2.addedge(0,4,false);
   g2.addedge(4,3,false);
   g2.addedge(1,4,false);
   g2.addedge(1,2,false);
   g2.addedge(2,3,false);

   bool ans = strongconnected(0,g,g2);
   if(ans==true)
   cout<<"YES";

   else if(ans==false)
   cout<<"False";


}
