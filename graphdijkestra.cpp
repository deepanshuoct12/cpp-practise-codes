#include<bits/stdc++.h>
using namespace std;
template <typename T>
class graph{
    unordered_map<T,list<pair<T,int> > > m;

public:
    void addedge(T u ,T v,int dist,bool bidir=true)
    {
        m[u].push_back(make_pair(v,dist));
        if(bidir)
        {
            m[v].push_back(make_pair(u,dist));
        }
    }

    void printadj(){

        for(auto i:m){

            cout<<i.first<<"-->";

            for(auto j:i.second)
            {

                cout<<"("<<j.first<<" ,"<<j.second<<")";

            }
            cout<<"\n";
        }
    }

    void dijkstra(T src){

        unordered_map<T,int> dist;

        for(auto i : m){
            dist[i.first]=INT_MAX;
        }

        set< pair<int ,T> >s;
        dist[src]=0;
        s.insert(make_pair(0,src));

        while(!s.empty())
        {
            auto p = *(s.begin());
            T node = p.second;
            int nodedist = p.first;
            s.erase(s.begin());
            for(auto neighbour : m[node])
            {
                if(dist[neighbour.first]> nodedist + neighbour.second)
                {
                T dest=neighbour.first;
                auto f = s.find(make_pair(dist[dest],dest));
                if(f!=s.end())
                {
                    s.erase(f);
                }
                    dist[neighbour.first]=nodedist+neighbour.second;
                    s.insert(make_pair(dist[dest],dest));
                }

            }
        }
        for(auto d:dist)
        {
            cout<<d.first<<"  is located at "<<d.second<<"\n";
        }
    }
};
int main()
{

    graph<int>g;
    g.addedge(1,2,1);
    g.addedge(1,3,4);
    g.addedge(2,3,1);
    g.addedge(3,4,2);
    g.addedge(1,4,7);
    g.printadj();
    g.dijkstra(1);
    return 0;


}

