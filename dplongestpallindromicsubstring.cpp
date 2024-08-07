#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
#define prDouble(x) cout<<fixed<<setprecision(10)<<x
#define test ll t;cin>>t;while(t--)
#define f first
#define s second
#define pb push_back
#define pop pop_back
#define int long long int
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define mod 1000000007
#define inf 1LL<<60
void init_code(){
   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
    // bool ispallindrome(string s)
    // {
    //     string revstr=s;
    //     reverse(revstr.begin(),revstr.end());
    //     return s==revstr;
    // }
    
    //top down
// int dp[1000][1000];
// int st=0;
// bool solve(string str,int i,int j,int &ans)
// {
//    if(dp[i][j]!=-1)
//     return dp[i][j];
    
//     if(i>j)
//     return 0;
    
//     if(i==j)
//     return 1;
    
// //    cout<<ans;
     
//     bool found=false;
//  //   cout<<i<<" "<<j<<" "<<ans<<"\n";
//     if(str[i]==str[j])
//     {
//         if(solve(str,i+1,j-1,ans) && (j-i+1>ans))
//         {
//             found=true;
//             st=i;
//             ans=j-i+1;   
//          //   dp[i+1][j+1]=found==true?1:0;
//         }
//         else 
//        {
//        if(solve(str,i,j-1,ans)&& ((j-1)-i+1)>ans)
//         {
//             found =true;
//             ans=(j-1)-i+1;
//             st=i;
//           // dp[i][j-1]=found==true?1:0;
//         }
        
//         if(solve(str,i+1,j,ans) && (j-(i+1)+1>ans))
//         {
//             found = true;
//             ans=j-(i+1)+1;
//             st=i+1;
//            // dp[i+1][j]=found==true?1:0;
//         }
//       }
//     }
//     else 
//     {
//        if(solve(str,i,j-1,ans)&& ((j-1)-i+1)>ans)
//         {
//             found =true;
//             ans=(j-1)-i+1;
//             st=i;
//             dp[i][j-1]=found==true?1:0;
//         }
        
//         if(solve(str,i+1,j,ans) && (j-(i+1)+1>ans))
//         {
//             found = true;
//             ans=j-(i+1)+1;
//             st=i+1;
        
//         //  dp[i+1][j]=found==true?1:0;
//         }
//     }

//      dp[i][j]=found==true?1:0;
//     return found;
// }
    
   //top down
    bool solve(int l, int r, string &s, int memo[][1001], vector<int> &answer) 
    {
        // Check if [ L ... R ] is already calculated before
        if (memo[l][r] != -1) {
            return memo[l][r];         
        }
        
        // Base case, every single letter or empty string is also a palindrome
        if (l >= r) {
            return true;
        }
        
        // Possible palindrome beginning
        bool found = false;
        if (s[l] == s[r]) {
            found = true && solve(l + 1, r - 1, s, memo, answer);
        }
        
        // Try other possibilities
      solve(l + 1, r , s, memo, answer);
       solve(l, r - 1, s, memo, answer);
        
        // Update longest palindrome position and width
        if (found && (r - l + 1) > answer[2]) {
            answer = {l, r, (r - l + 1)};
        }
        
        // Memoization
        memo[l][r] = found;
        
        return found;
    }    
    
    
    string longestPalindrome(string s)
    {
        
        
         int memo[1001][1001];
        memset(memo, -1, sizeof(memo));
        vector<int> answer = {0, 0, 1};
       bool ans= solve(0, s.length() - 1, s, memo, answer);
        return s.substr(answer[0], answer[2]);
        
        //bottom up
//         int dp[1001][1001];
//         memset(dp,0,sizeof(dp));
        
//         int n=s.length();
        
//         int maxlen=1;
//         int str=0;
        
//         for(int i=0;i<n-1;i++)
//         {
//             if(s[i]==s[i+1])
//             {
//                 dp[i][i+1]=1;
//                 maxlen=2;
//                 str=i;
//             }
//         }
        
        
        
        //bottom up
//         for(int len=0;len<n;len++)
//         {
//             for(int start=0;start<n-len;start++)
//             {
//                 int end=start+len;
//                 if(len==0)
//                     dp[start][end]=1;
//                 else if(len==1)
//                 {
//                     if(s[start]==s[end])
//                         dp[start][end]=1;
//                 }
//                 else if(s[start]==s[end] && dp[start+1][end-1]!=0)
//                 {
//                     dp[start][end]=1;
                    
//                 }
                
//                 if(dp[start][end])
//                 {
//                     if(len+1>maxlen){
//                     str=start;
//                    maxlen=len+1;
//                   }
                    
//                 }
//             }
//         }
//         string ans=s.substr(str,maxlen);
//         return ans;
        // string ansstr;
        // string temp;
        // int ans=0;
        // for(int i=0;i<s.size();i++)
        // {
        //     for(int len=1;len<=s.size()-i;len++)
        //     {
        //         string temp=s.substr(i,len);
        //         if(ispallindrome(temp))
        //         {
        //           if(len>ans)
        //           {
        //               ansstr=temp;
        //                ans=len;
        //           }
        //         }
        //     }
        // }
        // return ansstr;
   }
int32_t main()
{
   fast;
   init_code();
   string str;
   cin>>str;
   cout<<longestPalindrome(str);
   return 0;
}