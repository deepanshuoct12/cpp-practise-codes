#include<bits/stdc++.h>
using namespace std;
void fun(string nstr,int ci,int ti,vector<bool>&visited,string ans)
{
    if(ci>ti)
    {

        cout<<ans;
        cout<<"\n";
        return;
    }
    for(int i=0;i<nstr.length();i++)
    {

        if(visited[i]==0)
        {
            char ch=nstr[i];
            visited[i]=1;
            fun(nstr,ci+1,ti,visited,ans+ch);
             visited[i]=0;
        }
    }
}
int main()
{
    string str;
    cin>>str;
    int k;
    cin>>k;
    map<char,int>mp;
    string nstr;
    for(auto x:str)
    {
        if(mp.find(x)==mp.end())
         {
             mp[x]++;
             nstr.push_back(x);
         }
    }
     vector<bool>visited(nstr.length(),false);
    fun(nstr,1,k,visited,"");
    return 0;
}
