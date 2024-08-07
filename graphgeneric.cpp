//https://ide.geeksforgeeks.org/yJSlJBlBk1//url
#include<iostream>
#include<list>
#include<map>
#include<iterator>
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
};

int main()
{

    Graph<string> g;
    g.addedge("puttin","trump",false);
    g.addedge("puttin","modi",false);
    g.addedge("puttin","pope",false);
    g.addedge("modi","trump",true);
    g.addedge("modi","yogi",true);
    g.addedge("prabhu","modi",false);

     g.print();

}
