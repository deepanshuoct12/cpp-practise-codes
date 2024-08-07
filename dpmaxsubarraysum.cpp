#include<bits/stdc++.h>
using namespace std;

int maxsum(int arr[],int n){


int dp[100]={0};

dp[0] = arr[0]>0?arr[0]:0;

int m = dp[0];
int mx = arr[0];

for(int i=1;i<n;i++){

    dp[i] = arr[i]+dp[i-1];

    if(arr[i]<0){                // if all elements are negative
        mx = max(mx,arr[i]);

    }

    if(dp[i]<0)
        dp[i]=0;

    m = max(dp[i],m);
}


if(m==0)
return mx;

return m;

}


int main(){

int n;
cin>>n;

int arr[n];

for(int i=0;i<n;i++)
cin>>arr[i];

cout<<maxsum(arr,n)<<"\n";
return 0;

}
