#include<bits/stdc++.h>
using namespace std;
//#define int long long int
#define ll long long

struct item{
int wt,val;
};

int solve(vector<item> ar,int n,int w)
{
    ll dp[n+1][w+1];

    for(int i=0;i<=w;i++)
        dp[1][i]=0;

         dp[1][ar[1].wt] = ar[1].val;

        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<=w;j++)
            {
                dp[i][j] = dp[i-1][j];

                if(ar[i].wt>j)
                    continue;

                dp[i][j]=max(dp[i][j],ar[i].val + dp[i-1][j-ar[i].wt]);
            }
        }
    return *max_element(dp[n],dp[n]+w+1);

}

int main(){
    int n,w;
    cin>>n>>w;
    vector<item> ar(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>ar[i].wt>>ar[i].val;
    }

    cout<<solve(ar,n,w);

return 0;
}

