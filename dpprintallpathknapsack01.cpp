#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
//bottom up
void knapsack(vector<int> &profit, vector<int> &wt, int C)
{
    int dp[1001][1001];
    memset(dp,0,sizeof(dp));
    int n=profit.size();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=C;j++)
        {
            if(j<wt[i-1])
            dp[i][j]=dp[i-1][j];
            else
            dp[i][j]=max( dp[i-1][j] , dp[i-1][j-wt[i-1]]+profit[i-1] );
        }
    }
   cout<<dp[n][C]<<"\n";
   queue< pair<string,pair<int,int> > > q;
   string psf="";

   q.push({psf,{n,C}});

   while(!q.empty())
   {
     pair<string,pair<int,int> >curr=q.front();
     q.pop();

     string str=curr.first;
     int i=curr.second.first;
     int j=curr.second.second;
  //  cout<<str<<" "<<i<<" "<<j<<"\n";
     if(i==0 || j==0)
     {
         cout<<str<<"\n";
     }
     else
    {

   if(j>=wt[i-1])
    {
        int inc=dp[i-1][j-wt[i-1]]+profit[i-1];

        if(dp[i][j]==inc)
        {   string temp=to_string(i-1);
            q.push({temp+" "+str,{i-1,j-wt[i-1]}});
            temp.clear();
        }
     }

    int exc=dp[i-1][j];
    if(exc==dp[i][j])
    {
        q.push({str,{i-1,j}});
    }

    }

  }

}

int main(){
    int n;
    memset(dp,-1,sizeof(dp));
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    vector<int>v2(n);
    for(int i=0;i<n;i++)
    cin>>v2[i];

    int sum;
    cin>>sum;
     knapsack(v,v2,sum);

}
