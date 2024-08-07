#include<bits/stdc++.h>
using namespace std;

int solve(string str)
{
    int dp[100];
  
    int n=str.length();
    dp[0]=1;
    unordered_map<char,int>last;
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1]*2;
        
        if(last.find(str[i-1])!=last.end())
        {
            dp[i]=dp[i]-dp[last[str[i-1]]-1];
        }
        last[str[i-1]]=i;
    }
    
    return dp[n]-1;
}
int main()
{
    string str;
    cin>>str;
    
    cout<<solve(str);
    return 0;
}