#include<bits/stdc++.h>
using namespace std;
#define inf 1000
void init_code(){
   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
vector<vector<int> >floydwarshall(vector<vector<int> >graph)
{
    int n=graph.size();
    int k=0;
    vector<vector<int> > dist(graph);
     // vector<vector<int> > dp(graph);
    while(k<n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
             if(i==k||j==k)
                continue;
              dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
        k++;
    }


    for(int i=0;i<n;i++)
    {
        if(dist[i][i]<0)
        {
            cout<<"Negative Cycle";
            exit(0);
        }
    }
  return dist;
}
int main()
{
    init_code();
    vector<vector<int> >graph={{0,inf,-2,inf},{4,0,3,inf},{inf,inf,0,2},{inf,-1,inf,0}};

    vector<vector<int > > ans=floydwarshall(graph);

    int n=ans.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<ans[i][j]<<" ";

        cout<<"\n";
    }

    return 0;
}
