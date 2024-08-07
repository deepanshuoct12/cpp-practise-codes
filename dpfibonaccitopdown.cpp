#include<bits/stdc++.h>
using namespace std;


//Top down
int fibTD(int n,int dp[]){

if(n==0 || n==1){

    return n;
}
if(dp[n]!=0)
    return dp[n];

    int ans = fibTD(n-1,dp)+fibTD(n-2,dp);

    return dp[n]=ans;

}

//Bottom up
int fibBU(int n){
    int dp[1000]={0};
    dp[1]=1;

    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main(){

    int dp[100]={0};

    cout<<fibTD(5,dp);
    cout<<"\n";
    cout<<fibBU(6);

return 0;
}
