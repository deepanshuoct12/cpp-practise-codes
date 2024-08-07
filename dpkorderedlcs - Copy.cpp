#include<bits/stdc++.h>
//#include<iostream>
//#include<cmath>
using namespace std;      // this code is giving wronng output
#include<stdio.h>
# define F( i,a,b) for(LL i=a;i<=b;i++)
#define LL long long
#define INF 1000000000009
# define MOD 100000000007
                              // in this programe we ued word string it is actually array only;
LL n,m,a[2005],b[2005];
LL dp[2005][2005][8];

LL f(LL i,LL j,LL k)          // n,m are length of a and b resp.
{
    if(i==n || j==m)     //  if any string is finished then answer is 0
        return 0;         // n and m are declarred globally thererfore can be used here easily

    if(dp[i][j][k]!=-1)   // if current state has already been computed
      return dp[i][j][k];

    LL res=0;

    if(a[i]==b[j])       // is first char. of both string is same then do this
        res=1 + f(i+1,j+1,k);

    else
    {
        if(k>0)   // we have computed the single char. to match with jth of string
        res=1+f(i+1,j+1,k-1);

         res=max( f(i+1,j,k), res );
          res=max( res, f(i,j+1,k) );
    }

      return dp[i][j][k]=res;

}
int main()
{
    memset( dp,-1, sizeof(dp));

    LL k;
    cin>>n>>m>>k;

    F( i,0,n-1)
    cin>>a[i];

    F(i,0,m-1)
    cin>>b[i];

    LL ans=f(0,0,k);

    cout<<"\n";

    cout<<ans;
    return 0;

}

