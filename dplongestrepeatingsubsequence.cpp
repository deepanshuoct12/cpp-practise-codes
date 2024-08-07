#include<bits/stdc++.h>
#include<cstring>
using namespace std;
string s="";
int findLongestRepeatingSubSeq(string str)
{
    int n = str.length();
 
    // Create and initialize DP table
    int dp[n+1][n+1];
    for (int i=0; i<=n; i++)
        for (int j=0; j<=n; j++)
            dp[i][j] = 0;
 
    // Fill dp table (similar to LCS loops)
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            // If characters match and indexes are
            // not same
            if (str[i-1] == str[j-1] && i != j)
                dp[i][j] =  1 + dp[i-1][j-1];         
                      
            // If characters do not match
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[n][n];
}
 

int main()
{
     string s1,s2;
     cin>>s1;
     s2=s1;
    cout<<findLongestRepeatingSubSeq(s1)<<"\n";

    return 0;
}