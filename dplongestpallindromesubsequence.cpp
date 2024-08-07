class Solution {
public:
    int dp[1000][1000];
    //top down 
    int solve(string str,int i,int j)
    {
        // if(i>j)
        //     return 0;
        if(i==j)
            return 1;
        
        if(i+1==j && str[i]==str[j])
            return 2;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(str[i]==str[j])
            dp[i][j]=2+solve(str,i+1,j-1);
        else 
        {
            dp[i][j]=max(solve(str,i+1,j),solve(str,i,j-1));
        }
          return dp[i][j];  
    }
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof(dp));
         return solve(s,0,s.length()-1);
        
        //bottom up
//         string temp=s;
//         int n=temp.length();
//           int dp[1001][1001];
//         memset(dp,0,sizeof(dp));
//         int maxlen=1;
//           for(int len=0;len<n;len++)
//         {
//             for(int start=0;start<n-len;start++)
//             {
//                 int end=start+len;
//                 if(len==0)
//                     dp[start][end]=1;
//                 else if(len==1)
//                 {
//                     if(s[start]==s[end])
//                         dp[start][end]=2;
//                     else 
//                         dp[start][end]=1;
//                 }
//                 else if(s[start]==s[end] )
//                 {
//                     dp[start][end]=dp[start+1][end-1]+2;
                    
//                 }
//                 else if(s[start]!=s[end])
//                 {
//                     dp[start][end]=max(dp[start+1][end],dp[start][end-1]);
//                 }
                

//             }
//         }
     
//         return dp[0][n-1];
       //return maxlen;
//         reverse(temp.begin(),temp.end());
//         int n=s.length();
//         int dp[n+1][n+1];
        
//         for(int i=0;i<=n;i++)
//         {
//             for(int j=0;j<=n;j++)
//             {
//                 if(i==0 || j==0)
//                     dp[i][j]=0;
//                 else if(s[i-1]==temp[j-1])
//                     dp[i][j]=dp[i-1][j-1]+1;
                
//                 else 
//                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    
//             }
//         }
//         return dp[n][n];
    }
};