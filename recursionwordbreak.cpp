#include<bits/stdc++.h>
using namespace std;

void fun(string s,unordered_map<string,int>dict,string ans)
{
    if(s.length()==0)
    {
        cout<<ans<<"\n";
    }

    for(int i=0;i<s.size();i++)
    {
        string prefix=s.substr(0,i+1);
        string rem=s.substr(i+1);
        if(dict.find(prefix)!=dict.end())
        {
            fun(rem,dict,ans+prefix+" ");
        }
    }
}

int main(){
    int n;
    cin>>n;
    unordered_map<string,int>dict;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        dict[str]++;
    }
    string s;
    cin>>s;
    fun(s,dict,"");
    return 0;
}
