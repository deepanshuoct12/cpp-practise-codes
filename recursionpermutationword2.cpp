#include<bits/stdc++.h>
using namespace std;

void fun(string str,vector<char>&box,int ci,int ti,unordered_map<char,int>&mp)
{
    if(ci>=ti)
    {
        for(auto x:box)
        cout<<x;
        cout<<"\n";
        return;
    }
    
    char item=str[ci];
    int lastidx=mp[item];
    for(int i=lastidx+1;i<str.length();i++)
    {
        if(box[i]=='-')
        {
            box[i]=item;
            mp[item]=i;
            fun(str,box,ci+1,ti,mp);
            box[i]='-';
            mp[item]=-1;
        }
    }
}
int main()
{
    string str;
    cin>>str;
    int n=str.length();
    vector<char>box(n,'-');
    unordered_map<char,int>mp;
    for(auto x:str)
    mp[x]=-1;

    fun(str,box,0,n,mp);
}
