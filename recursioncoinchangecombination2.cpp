#include<bits/stdc++.h>
using namespace std;
void fun(vector<int>coins,int cc,int sum,vector<int>&ans,int s)
{
    if(cc==coins.size())
    {
        //cout<<sum<<"\n";
        if(sum==s)
        {
            for(auto x:ans)
            cout<<x<<"-";
             cout<<"."<<"\n";
        }

       return;
    }
    for(int i=1;i<=(s-sum)/coins[cc];i++){

    for(int k=0;k<i;k++)
    ans.push_back(coins[cc]);
    fun(coins,cc+1,sum+coins[cc]*i,ans,s);

    for(int k=0;k<i;k++)
    ans.pop_back();
    }
     // ans.pop_back();
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

