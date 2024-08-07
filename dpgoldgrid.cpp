#include<bits/stdc++.h>
using namespace std;
int dp[100][100];

int solve(int n){

for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
       int val=dp[i][j];
     dp[i][j]=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]+val;
    }
}


 int ans=0;
for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++){
        int r1=dp[i][j];
        int r2=dp[i][n-1]-dp[i][j];
        int r3=dp[n-1][j]-dp[i][j];
        int r4=dp[n-1][n-1]-(r1+r2+r3);

        ans = max(  ans,min(r1,min(r2,min(r3,r4)))  );
    }
}


return ans;

}


int main(){
int n,g;
cin>>n>>g;

memset(dp,0,sizeof dp);
for(int i=0;i<g;i++)
{
    int x,y;
    cin>>x>>y;
    dp[x-1][y-1]=1;
}

cout<<solve(n);
return 0;

}
//custom
// 6 13
// 1 2
// 1 3
// 2 1
// 2 4
// 2 5
// 3 2
// 4 2
// 4 3
// 4 6
// 5 1
// 5 4
// 5 5
// 6 2
