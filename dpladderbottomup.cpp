#include<bits/stdc++.h>
using namespace std;


int ladderbottomup(int n,int k){

int dp[100]={0};

dp[0]=1;
for(int i=1;i<=n;i++){
        int sum=0;
    for(int j=1;j<=k;j++)
    {
        if(i-j>=0)
            sum+=dp[i-j];
    }
    dp[i]=sum;
}

return dp[n];
}
int main(){

int n,k;
cin>>n>>k;

cout<<ladderbottomup(n,k)<<"\n";

return 0;
}
