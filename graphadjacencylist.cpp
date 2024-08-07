//https://ide.geeksforgeeks.org/o8GBL4GGfZ//url
#include<iostream>
#include<list>
using namespace std;

class Graph{

int V;
list<int> *l;
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

};

int main()
{

    Graph g(5);

   g.addedge(0,1);
   g.addedge(0,4);
   g.addedge(4,3);
   g.addedge(1,4);
   g.addedge(1,2);
   g.addedge(2,3);
   g.print();
}
