#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>v,int n)
{
    int dp[n+1];
    int mx=-1;
    for(int i=0;i<n;i++)
    {
        int m=0;
        for(int j=0;j<i;j++)
        {
            if(v[j]<v[i])
            {
                m=max(m,dp[j]);
            }
        }
        dp[i]=m+1;
        mx=max(mx,dp[i]);
    }
    
    queue<pair<int,string> >q;
    string psf=to_string(v[0]);

    for(int i=0;i<n;i++)
    {
        if(dp[i]==1)
        q.push({i,psf});
    }

    while(!q.empty())
    {
        pair<int,string>curr=q.front();
        q.pop();
        
        int i=curr.first;
        string s=curr.second;
      //   cout<<s;
        if(dp[i]==mx)
        {
            cout<<s<<"\n";
        }
        for(int j=i+1;j<n;j++)
        {
            if(dp[j]==dp[i]+1)
            {
                string temp=" ";
                temp.push_back('-');
                temp.push_back('>');
                temp+=" ";
                temp+=to_string(v[j]);
                 q.push({j,s+temp});
                 temp.clear();
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    solve(v,n);
}