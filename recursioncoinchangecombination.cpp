#include<bits/stdc++.h>
using namespace std;
void fun(vector<int>coins,int cc,int sum,vector<int>&ans,int s)
{
    if(cc==coins.size())
    {
        if(sum==s)
        {
            for(auto x:ans)
            cout<<x<<"-";
             cout<<"."<<"\n";
        }
       return;
    }
    ans.push_back(coins[cc]);
    fun(coins,cc+1,sum+coins[cc],ans,s);
    ans.pop_back();
    fun(coins,cc+1,sum,ans,s);
}
int main()
{
    int n;
    cin>>n;
    vector<int>coins(n);
    for(int i=0;i<n;i++)
    cin>>coins[i];
    int s;
    cin>>s;
    vector<int>ans;
    fun(coins,0,0,ans,s);
}
