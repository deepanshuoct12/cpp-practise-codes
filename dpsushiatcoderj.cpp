#include<bits/stdc++.h>
using namespace std;
double dp[301][301][301];

double solve(int x,int y,int z,int &n) //expected no.of operations
{
    if(x<0 || y<0 || z<0)  // to stop infinite recursion
        return 0;

    if(x==0 && y==0 && z==0)
        return 0;

    if(dp[x][y][z]>-0.9)
        return dp[x][y][z];

        double exp = n + x*solve(x-1,y,z,n) + y*solve(x+1,y-1,z,n) + z*solve(x,y+1,z-1,n);

        return dp[x][y][z] = exp/(x+y+z);

}

int main()
{
ios_base:: sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
    int n,x;
    cin>>n;
    memset(dp,-1,sizeof dp);
    int one=0,two=0,three=0;
    for(int i=1;i<=n;i++)
    {

        cin>>x;

        if(x==1)
            one++;

        else if(x==2)
            two++;

        else
            three++;
    }

    cout<<fixed<<setprecision(10)<<solve(one,two,three,n)<<"\n";
    return 0;
}
