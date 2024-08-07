#include<bits/stdc++.h>
using namespace std;

int ladder(int n,int k){

int dp[100]={0};
dp[0]=1;
dp[1]=1;
for(int i=2;i<=k;i++)  // find for 1st k values
{
    dp[i]=2*dp[i-1];
}

for(int i=k+1;i<=n;i++)
{
    dp[i]=2*dp[i-1] - dp[i-k-1];
}

return dp[n];
}


int main(){

int n,k;
cin>>n>>k;

cout<<ladder(n,k)<<"\n";
return 0;

}
