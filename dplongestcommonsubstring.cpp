#include<bits/stdc++.h>
using namespace std;

int lcs(string a,string b)
{
    int n=a.length();
    int m=b.length();

    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));

    int mx=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
           if(a[i-1]==b[j-1])
           {
               dp[i][j]=dp[i-1][j-1]+1;
           }
            mx=max(mx,dp[i][j]);
        }
    }
    return mx;
}

int lcstopdown(string str1,string str2,int i,int j,int count)
{
    if(i==0 || j==0)
        return count;

    if(str1[i-1]==str2[j-1])
        count=1+lcstopdown(str1,str2,i-1,j-1,count+1);
    count=max(lcstopdown(str1,str2,i-1,j,0),lcstopdown(str1,str2,i,j-1,0));

    return count;
}
int main()
{
    string a,b;
    cin>>a>>b;
    cout<<lcs(a,b);
    return 0;
}

