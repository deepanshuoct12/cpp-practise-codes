#include<bits/stdc++.h>
using namespace std;
#define int long long int

template<typename T>
class graph{
map< T ,list <T> >adjlist;

public :
    graph(){
    }

    void addedge(T u,T v,bool bidir=true){
    adjlist[u].push_back(v);
    if(bidir){
        adjlist[v].push_back(u);
    }
    }

    void cycle(T src,T n,T ans)
    {
         queue<T>q;
         vector<T>distance(n+1,INT_MAX);
        q.push(src);
        distance[src]=0;

        while(!q.empty())
        {
            T node=q.front();
            q.pop();

            for(auto neighbour: adjlist[node])
            {
                if(distance[neighbour]==INT_MAX)
                {
                    distance[neighbour]=distance[node]+1;
                    q.push(neighbour);

                }

                else if(distance[neighbour]>=distance[node])
                    ans=min(ans,distance[neighbour]+distance[node]+1);
            }
        }

    }
};

int32_t main(){

graph<int>g;
g.addedge(0,2,false);
g.addedge(0,1,false);
g.addedge(2,3,false);
g.addedge(2,4,false);
g.addedge(3,0,false);
g.addedge(4,5,false);
g.addedge(1,5,false);
 int n=5;
 int ans=n;
 for(int i=0;i<n;i++)
 {
     g.cycle(i,n,ans);
 }
 cout<<ans<<"\n";
return 0;
}

