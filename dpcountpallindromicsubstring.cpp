class Solution {
public:
    //top down
//     int dp[1001][1001];
//     bool pallindrome(int st,int en,string s)
//     {
//        while(st<=en)
//        {
//            if(s[st]!=s[en])
//                return false;
//            st++;
//            en--;
//        }
//         return true;
//     }
//     int solve(int i,int j,string s)
//     {
//         if(i>j)
//             return 0;
//         if(i==j)
//             return 1;
        
//         if(dp[i][j]!=-1)
//             return dp[i][j];
        
//         if(pallindrome(i,j,s))
//         {
//             dp[i][j]=1+solve(i+1,j,s)+solve(i,j-1,s)-solve(i+1,j-1,s);
//         }
//         else 
//         dp[i][j]=solve(i+1,j,s)+solve(i,j-1,s)-solve(i+1,j-1,s);
        
//         return dp[i][j];
//     }
    int countSubstrings(string s) {
        // memset(dp,-1,sizeof(dp));
        // int  n=s.length();
        // return solve(0,n-1,s);
        
        //bottom up
        
        int n=s.length();
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        int cnt=0;
        for(int gap=0;gap<n;gap++)
        {
            for(int i=0;i<n-gap;i++)
            {
                int j=i+gap;
                if(gap==0)
                    dp[i][j]=1;
                else if(gap==1)
                {
                    if(s[i]==s[j])
                        dp[i][j]=1;
                }
                else if(s[i]==s[j] && dp[i+1][j-1]==1)
                {
                    dp[i][j]=1;
                }
            
                if(dp[i][j])
                    cnt++;
                    
            }
        }
        return cnt;
    }
};