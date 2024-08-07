#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
//bottom up
void subsetsum(vector<int>&v,int n,int sum)
{
    for(int i=0;i<sum;i++)
    dp[0][i]=0;

    for(int i=0;i<n;i++)
    dp[i][0]=1;

    dp[0][0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(v[i-1]>j)
            dp[i][j]=dp[i-1][j];
            else
            dp[i][j]=dp[i-1][j]||dp[i-1][j-v[i-1]];
        }
    }
   cout<<dp[n][sum]<<"\n";
   queue< pair<string,pair<int,int> > > q;
   string psf="";

   q.push({psf,{n,sum}});
   while(!q.empty())
   {
     pair<string,pair<int,int> >curr=q.front();
     q.pop();

     string str=curr.first;
     int i=curr.second.first;
     int j=curr.second.second;
   // cout<<str<<" "<<i<<" "<<j<<"\n";
     if(i==0 || j==0)
     {
         cout<<str<<"\n";
     }
     else
    {

   if(j>=v[i-1])
    {
        bool inc=dp[i-1][j-v[i-1]];
        if(inc)
        {   string temp=to_string(i-1);
            q.push({temp+" "+str,{i-1,j-v[i-1]}});
            temp.clear();
        }
     }
    // if(i>0){
    bool exc=dp[i-1][j];
    if(exc)
    {
        q.push({str,{i-1,j}});
    }
   // }


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

    int sum;
    cin>>sum;
    subsetsum(v,n,sum);

}
