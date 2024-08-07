#include<bits/stdc++.h>
using namespace std;
int ladder(int n,int k,int dp[]){

if(n==0)
    return 1;

    if(dp[n]!=0)
        return dp[n];

        int sum=0;

        for(int i=1;i<=k;i++)
        {
            if(n-i>=0)
           sum+=ladder(n-i,k,dp);

        }

       dp[n]=sum;
       return dp[n];

}
int main(){
int n,k;
int dp[100]={0};
cin>>n>>k;

cout<<ladder(n,k,dp);
return 0;
}
