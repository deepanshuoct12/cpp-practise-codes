#include<bits/stdc++.h>
using namespace std;

void fun(string str,int cb,string ans,int ci,int ti)
{
    if(cb==str.length())
    {
        if(ci==ti)
        cout<<ans<<"\n";
        return;
    }
    //string ch=str.substr(cb,1);
    char ch=str[cb];
    fun(str,cb+1,ans+"",ci,ti);
    fun(str,cb+1,ans+ch,ci+1,ti);
}
int main()
{
    string str;
    cin>>str;
    int k;
    cin>>k;

    map<char,int>mp; string nstr="";
    for(auto x:str)
    {
       if(mp.find(x)==mp.end()){
        mp[x]++;
        nstr+=x;
       }

    }
    fun(nstr,0,"",0,k);
}
