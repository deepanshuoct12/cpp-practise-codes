#include<bits/stdc++.h>
using namespace std;
 int graph[11][11];

 void fun(int n,int m,int i,int j,int &ans)
 {
     if(i>=n || j>=m || i<0 || j<0 || graph[i][j]==0)
     return ;

     ans+=graph[i][j];
     graph[i][j]=0;
     fun(n,m,i-1,j,ans);
     fun(n,m,i+1,j,ans);
     fun(n,m,i,j+1,ans);
     fun(n,m,i,j-1,ans);


 }
 int main(){
     int n,m;
     cin>>n>>m;
     memset(graph,0,sizeof(graph));

     for(int i=0;i<n;i++)
     {
         for(int j=0;j<m;j++)
         cin>>graph[i][j];
     }

    int maxans=-1;
     for(int i=0;i<n;i++)
     {

        for(int j=0;j<m;j++)
        {
               int ans=0;
            if(graph[i][j]!=0)
            {
               fun(n,m,i,j,ans);
               cout<<ans<<"\n";
               if(ans>maxans)
               maxans=ans;
            }
        }
     }
     cout<<maxans;
     return 0;
 }
