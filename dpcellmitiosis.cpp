#include<iostream>

using namespace std;

long long solvecellproblem(int n,int x,int y,int z)
{
    long long *dp=new long long[n+1];
      //bottom up
    dp[0]=0;    // base case
    dp[1]=0;

    for(int i=2;i<=n;i++)
    {
        if(i%2==0)
          {

              dp[i]=min(dp[i-1]+y, dp[i/2]+x);

          }

          else
          {
              dp[i]=min( dp[i-1]+y , dp[(i+1)/2]+x+z);


          }
    }

    return dp[n];

}

int main()
{
   /*nt n,x,y,z;
    cin>>n>>x>>y>z;*/
    cout<<"\n";

    cout<<solvecellproblem(5,2,1,3);
}
