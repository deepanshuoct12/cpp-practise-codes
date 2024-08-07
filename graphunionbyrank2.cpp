#include<bits/stdc++.h>
using namespace std;
int parent[200001],Rank[200001];
int findparent(int x){
	return x==parent[x]?x:parent[x]=findparent(parent[x]);
}

void unite(int x,int y){
	x=findparent(x);
	y=findparent(y);
	if(x==y) return;
	if(Rank[x]<Rank[y])
    {
        parent[x]=y;
        Rank[y]++;
    }
    else {
	++Rank[x];
	parent[y]=x;
    }
	return;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i) parent[i]=i,Rank[i]=0;

    return 0;
}
