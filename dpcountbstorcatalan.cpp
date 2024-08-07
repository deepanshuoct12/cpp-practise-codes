#include<bits/stdc++.h>
using namespace std;

//BOTTOMUP
int bstbu(int n){
int dp[100]={0};
dp[0]=1;
dp[1]=1;

for(int i=2;i<=n;i++){
    int sum=0;
  for(int j=1;j<=i;j++)
    sum+=dp[j-1]*dp[i-j];
    dp[i]=sum;

}
return dp[n];
}

//TOPDOWN  // wrong
int bsttd(int n){

if(n==0 || n==1)
    return 1;

    if(dp[n]!=0)
        return dp[n];

     int sum=0;
    for(int i=2;i<=n;i++)
        sum+=bsttd(i-1)*bsttd(n-i);

     return dp[n]=sum;
}
int main(){

int n;
cin>>n;
cout<<bst(n);
return 0;
}

