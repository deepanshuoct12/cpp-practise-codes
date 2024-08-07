#include<bits/stdc++.h>
using namespace std;

double dp[3001][3001];

double solve(vector<double>& ar,int i,int x)
{
    if(x==0)  // no matter how many coins we can get 1 head
        return 1;
    if(i==0)//0 coind
        return 0;

    if(dp[i][x]>-0.9)
       return dp[i][x];

       return dp[i][x] = ar[i]*solve(ar,i-1,x-1)+ (1-ar[i])*solve(ar,i-1,x);

}
int main()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof dp);
     vector<double>ar(n+1);

     for(int i=1;i<=n;i++)
        cin>>ar[i];

       cout<<solve(ar,n,(n+1)/2);
        return 0;
}
