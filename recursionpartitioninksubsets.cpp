#include<bits/stdc++.h>
using namespace std;
int cnt=1;
void fun(int n,int k,vector<vector<int> >&ans,int ssf,int i)
{
    if(i>n)
    {
        if(ssf==k)
        {
            cout<<cnt<<"."<<" ";
                 cnt++;
            for(auto vec:ans)
            {

                for(auto x:vec)
                {
                   cout<<x<<" " ;
                }
            }
            cout<<"\n";
        }
        return;
    }
    for(int j=0;j<k;j++)
    {
        if(ans[j].size()>0)
        {
            ans[j].push_back(i);
            fun(n,k,ans,ssf,i+1);
            ans[j].pop_back();
        }else
        {
             ans[j].push_back(i);
            fun(n,k,ans,ssf+1,i+1);
            ans[j].pop_back();
            break;
        }
    }
}
int main()
{
    int n,k;
    cin>>n>>k;

    vector<vector<int> >ans(k);

    fun(n,k,ans,0,1);
}
