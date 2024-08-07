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

    bool iscyclehelper(T node,map<T,bool> &visited ,map<T,bool> &instack){
    visited[node]=true;
    instack[node]=true;
    for(auto nbr : adjlist[node]){

        if(!visited[nbr])
        {
            if(iscyclehelper(neighbour,visited,instack))
            return true;
        }
        else if(instack[nbr])
        return true;
      //  if(!visited[neighbour] && iscyclehelper(neighbour,visited,instack)|| instack[neighbour]){
        //    return true;
        //}
    }
    instack[node]=false;
    return false;
    }

    bool iscycle(){
        map<T,bool> visited;
        map<T,bool> instack;


        for(auto i:adjlist){
            T node = i.first;
            if(!visited[node]){
                bool cyclepresent = iscyclehelper(node,visited,instack);
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

if(g.iscycle()){
    cout<<"yes"<<"\n";
}
else
    cout<<"no"<<"\n";

return 0;
}
