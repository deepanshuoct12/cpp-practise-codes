#include<bits/stdc++.h>
using namespace std;
//top down
int dp[1000][1000];
// int solve(string str,int i,int j)
// {
//     if(i>j)
//     return 0;
//     if(i==j)
//     return 1;
    
//     if(dp[i][j]!=-1)
//     return dp[i][j];
    
//     if(str[i]==str[j])
//     dp[i][j]=1+solve(str,i+1,j)+solve(str,i,j-1);
//     else
//     dp[i][j]=solve(str,i+1,j)+solve(str,i,j-1)-solve(str,i+1,j-1);
    
//     return dp[i][j];
// }
//bottom up
int solve2(string str)
{
    int n=str.length();
   for(int len=0;len<n;len++)
   {
       for(int start=0;start<n-len;start++)
       {
           int end=start+len;
           
           if(len==0)
           {
             dp[start][end]=1;  
           }
           else if(str[start]==str[end])
           {
               dp[start][end]=dp[start+1][end]+dp[start][end-1]+1;
           }
           else if(str[start]!=str[end])
           dp[start][end]=dp[start+1][end]+dp[start][end-1]-dp[start+1][end-1];
       }
   }
   
   return dp[0][n-1];
}
int main()
{
    memset(dp,0,sizeof(dp));
    string str;
    cin>>str;
    cout<<solve2(str);
}