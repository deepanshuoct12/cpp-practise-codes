#include<bits/stdc++.h>
using namespace std;

int lis(int A[],int n){
   int dp[2600]={0};
    int ans=0;
    for(int i=0;i<n;i++)
    {  int m=0;
        for(int j=0;j<i;j++)
        {
            if(A[j]<A[i])
            m=max(m,dp[j]);
        }
        dp[i]=m+1;
        ans=max(ans,dp[i]);
    }

    return ans;
}

int main(){

int n;cin>>n;

int arr[n];

for(int i=0;i<n;i++){

    cin>>arr[i];
}
cout<<lis(arr,n);
return 0;
}
