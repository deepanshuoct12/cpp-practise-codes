#include<bits/stdc++.h>
using namespace std;

int minstepstopdown(int n,int dp[]){

if(n==1)
{
    return 0;
}

int op1,op2,op3;
op1=op2=op3=INT_MAX;

if(n%3==0)
    op1=minstepstopdown(n/3,dp);
if(n%2==0)
    op2=minstepstopdown(n/2,dp);

 op3=minstepstopdown(n-1,dp);

 int ans=min(op1,min(op2,op3))+1;
 return dp[n]=ans;

}

int minstepsbottomup(int n)
{

int dp[1000]={0};
int op1,op2,op3;


for(int i=2;i<=n;i++){

    op1=op2=op3=INT_MAX;

    if(i%2==0)
        op1=dp[i/2];
    if(i%3==0)
        op2=dp[i/3];

        op3=dp[i-1];

    int ans = min(op1,min(op2,op3))+1;
    dp[i]=ans;
}
return dp[n];

}

int main(){

int dp[1000]={0};

cout<<minstepstopdown(5,dp);
cout<<"\n";
cout<<minstepsbottomup(13);
return 0;
}
