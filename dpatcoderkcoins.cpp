#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&v,int k)
{
    bool dp[k+1];
    memset(dp,0,sizeof dp);

    for(int i=1;i<=k;i++)
    {
        for(int x:v)
        {
            if(x>i)
                continue;

            if(dp[i-x]==0)
                dp[i]=1;
        }
    }


}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

     if(solve(v,k))
        cout<<"First"<<"\n";

     else
        cout<<"Second"<<"\n";

    return 0;
}
