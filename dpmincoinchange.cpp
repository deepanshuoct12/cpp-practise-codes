#include<bits/stdc++.h>
using namespace std;

int coinchangetd(int n,int coins[],int m,int dp[]){


   if(n==0)
    return 0;

    if(dp[n]!=0)
        return dp[n];

    int ans = INT_MAX;
   for(int i=0;i<m;i++)
   {
       if(n-coins[i]>=0)
       {
           int sub = coinchangetd(n-coins[i],coins,m,dp);
           ans = min(ans,sub+1);

       }
   }
   dp[n]=ans;
   return dp[n];
}

int coinchangebu(int n,int coins[],int m){

    int dp[100]={0};
    for(int i=1;i<=n;i++){
          dp[i]= INT_MAX;
        for(int j=0;j<m;j++){
            if(i-coins[j]>=0){
             if(dp[i-coins[j]]==INT_MAX)
             continue;
            dp[i] = min(dp[i],dp[i-coins[j]]+1);
            }
        }

    }

    return dp[n];
}


int main(){
int n,m;
cin>>n>>m;
int coins[m];

for(int i=0;i<m;i++)
    cin>>coins[i];

  int dp[1000]={0};
  cout<<coinchangetd(n,coins,m,dp)<<"\n";

  cout<<coinchangebu(n,coins,m);



return 0;
}
