#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007
int dp[1001][1001];

int noofways(int m,int n)
{

    if(dp[0][0]==-1)
    return 0;

    for(int i=0;i<n;i++)
    {
        if(dp[0][i]==-1)
        break;

        dp[0][i]=1;      // fill first row
    }
     for(int i=0;i<m;i++)
     {
         if(dp[i][0]==-1)
         break;

         dp[i][0]=1;  // fill first col.
     }

     for(int i=1;i<m;i++)
     {
         for(int j=1;j<n;j++)
         {


             if(dp[i][j]==-1)
             {
                 continue;
             }

            dp[i][j]=0; // IF BOX IS BLOCKED THEN AFTER THAT BLOCKED BOX  EVERY BOX CONTAINS 0 AS THERE IS NO WAY TO REACH THEM

             if(dp[i][j-1]!=-1)
             {
                 dp[i][j]=dp[i][j-1];
             }

             if(dp[i-1][j]!=-1)
             {
                 dp[i][j]=(dp[i][j] + dp[i-1][j])%mod;
             }
         }
     }

     if(dp[m-1][n-1]==-1)   // if the final answer is blocked then no way to reaCH IT
        return 0;


        return dp[m-1][n-1]; // IT CONTAINS no. of was to reach the final answer

}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int m,n,p;// m= rows,n=col.s p=no. of boxes to be blocked



    cin>>m>>n>>p;

    memset(dp,0,sizeof dp);
    for(int i=0;i<p;i++)
        {
            int x,y;
            cin>>x>>y;

           dp[x-1][y-1]=-1;      // -1 represent that box is blocked
    }
    cout<<noofways(m,n)<<"\n";
    return 0;


}
