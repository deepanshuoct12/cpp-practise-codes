#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int grid[1005][1005];
int dp[1005][1005];

int solve(int r,int c)
{


        for(int i=1;i<=r;i++)
            {
                if(grid[1][i])
                dp[1][i]=1;

                else
                break;
            }

        for(int i=1;i<=r;i++)
            {
                if(grid[i][1])
                dp[i][1]=1;

                else
                break;
            }


    dp[1][1]=1;
    for(int i=2;i<=r;i++)
    {
        for(int j=2;j<=c;j++)
        {
            if(!grid[i][j])
              continue;
            else
            {
                dp[i][j]= (dp[i-1][j])%mod + (dp[i][j-1])%mod;
            }

        }
    }



  return (dp[r][c])%mod;
}

int main(){
ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    int r,c;
    cin>>r>>c;
    memset(dp,0,sizeof dp);

    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {  char c;
            cin>>c;
            if(c=='#')
                grid[i][j]=0;

            else
            grid[i][j]=1;

        }
    }

    cout<<solve(r,c)<<"\n";
return 0;
}
