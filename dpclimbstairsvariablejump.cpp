#include <bits/stdc++.h>
using namespace std;
int dp[100000];
int helper(int arr[],int n,int idx)
{
     if(idx>n)
    return 0;

    if(idx==n)
      return 1;

    if(dp[idx]!=0)
    return dp[idx];

    int ans=0;
    for(int i=1;i<=arr[idx] ;i++)
    {
        ans+=helper(arr,n,idx+i);
    }
    dp[idx]=ans;
    return ans;
}
int cs(int arr[], int n){
    // write your code here
    int idx=0;
      return helper(arr,n,idx);
}

int csbottomup(int arr[],int n)
{
    dp[n]=1;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=1;j<=arr[i]&& i+j<n;j++)
        dp[i]+=dp[i+j];
    }

    return dp[0];
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    memset(dp,0,sizeof(dp));
    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }
    cout<<csbottomup(arr,n)<<endl;
}
