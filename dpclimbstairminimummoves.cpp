#include <bits/stdc++.h>
using namespace std;
int dp[100000];
int helper(int arr[],int n,int idx)
{
    if(idx>n)
        return 0;
    if(idx==n)
      return 0;

    // if(dp[idx]!=0)
    // return dp[idx];

    int ans=0;
    int val=INT_MAX;
   // cout<<ans<<"\n";
    for(int i=1;i<=arr[idx];i++)
    {
        if(arr[i+idx]>0)
        val=min(val,helper(arr,n,idx+i));
    }

    if(val!=INT_MAX)
    ans=val+1;

    // cout<<ans<<"\n";
 //   dp[idx]=ans;
    return ans;
}
int cs(int arr[], int n){
    // write your code here
    int idx=0;
      return helper(arr,n,idx);
}

int csbottomup(int arr[],int n)
{
    dp[n-1]=0;
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]>0)
        {

        int val=INT_MAX;

        for(int j=1;j<=arr[i]&& i+j<n;j++)
         {
             if(dp[i+j]!=-1)
             val=min(val,dp[i+j]);

         }

        if(val!=INT_MAX)
        dp[i]=1+val;
        }
    }
    // for(int i=0;i<n;i++)
    // cout<<dp[i]<<" ";
    // cout<<"\n";
    return dp[0];
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    memset(dp,-1,sizeof(dp));
    for(int i = 0 ; i < n ;i++){
        cin>>arr[i];
    }
    cout<<csbottomup(arr,n)<<endl;
}
