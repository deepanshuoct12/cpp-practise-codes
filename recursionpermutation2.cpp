#include<bits/stdc++.h>
using namespace std;

void fun(vector<int>&items,int cb,int tb,int ci,int ti,string ans)
{
    if(cb>tb)
    {
        if(ci==ti)
        {
            cout<<ans<<"\n";
        }
        return;
    }
    for(int i=0;i<ti;i++)
    {
        if(items[i]==0)
        {
            items[i]=1;
            string t=to_string(i+1);
            fun(items,cb+1,tb,ci+1,ti,ans+t);
            items[i]=0;
        }
    }
       fun(items,cb+1,tb,ci,ti,ans+"0");
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>items(k,0);
    fun(items,1,n,0,k,"");
}
