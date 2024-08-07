#include<bits/stdc++.h>
using namespace std;
#define int long long int
int calorie[100][100];
int dp1[100][100];
int dp2[100][100];
int dp3[100][100];
int dp4[100][100];

int solve(int m,int n){


for(int i=1;i<=m;i++)
{
    for(int j=1;j<=n;j++)   //boy start
    {
        dp1[i][j]=calorie[i][j]+max(dp1[i-1][j],dp1[i][j-1]);
    }
}

for(int i=m;i>=1;i--)
{
    for(int j=1;j<=n;j++)   //girl start
    {
        dp2[i][j]=calorie[i][j]+max(dp2[i][j-1],dp2[i+1][j]);
    }
}

for(int i=m;i>=1;i--)
{
    for(int j=n;j>=1;j--)   //boy end
    {
        dp3[i][j]=calorie[i][j]+max(dp3[i+1][j],dp3[i][j+1]);
    }
}

for(int i=1;i<=m;i++)
{
    for(int j=n;j>=1;j--)   //girl end
    {
        dp4[i][j]=calorie[i][j]+max(dp4[i-1][j],dp4[i][j+1]);
    }
}
//DP
// cout<<"dp1"<<"\n";
// for(int i=1;i<=m;i++)
// {
//     for(int j=1;j<=n;j++)
//     cout<<dp1[i][j]<<" ";

//     cout<<"\n";
// }

// cout<<"dp2"<<"\n";
// for(int i=1;i<=m;i++)
// {
//     for(int j=1;j<=n;j++)
//     cout<<dp2[i][j]<<" ";

//     cout<<"\n";
// }

// cout<<"dp3"<<"\n";
// for(int i=1;i<=m;i++)
// {
//     for(int j=1;j<=n;j++)
//     cout<<dp3[i][j]<<" ";

//     cout<<"\n";
// }
// cout<<"dp4"<<"\n";
// for(int i=1;i<=m;i++)
// {
//     for(int j=1;j<=n;j++)
//     cout<<dp4[i][j]<<" ";

//     cout<<"\n";
// }

int ans = 0;
for(int i=2;i<m;i++)
{
    for(int j=2;j<n;j++)
    {
        int one  = dp1[i-1][j] + dp2[i][j-1] + dp3[i+1][j] + dp4[i][j+1];

        int two = dp1[i][j-1] + dp2[i+1][j] + dp3[i][j+1] + dp4[i-1][j];

        ans  = max(ans,max(one,two));
    }
}

return ans;

}


int32_t main(){

ios_base:: sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);

int m,n;
cin>>m>>n;

memset(dp1,0,sizeof dp1);
memset(dp2,0,sizeof dp1);
memset(dp3,0,sizeof dp1);
memset(dp4,0,sizeof dp1);
memset(calorie,0,sizeof calorie);

for(int i=1;i<=m;i++)
{
    for(int j=1;j<=n;j++)
    {
        cin>>calorie[i][j];
    }
}

cout<<solve(m,n)<<"\n";
return 0;
}

