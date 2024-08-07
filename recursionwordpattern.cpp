#include<bits/stdc++.h>
using namespace std;

void fun(string str,string pattern,unordered_map<char,string>&mp,string op)
{
    if(pattern.length()==0)
    {
       // cout<<pattern<<"\n";
         unordered_map<char,int>mp2;
        if(str.length()==0)
        {
            for(auto x:op)
            {
                if(mp2.find(x)==mp2.end())
                {cout<<x<<"-> "<<mp[x]<<","<<" ";mp2[x]++;}
            }
            cout<<".";
        }
        return;
    }
    char ch=pattern[0];
    string rop=pattern.substr(1);
    if(mp.find(ch)!=mp.end())
    {
        string prevstr=mp[ch];
       if(str.length()>=prevstr.length())
       {
          string left=str.substr(0,prevstr.length());
          string right=str.substr(prevstr.length());

          if(prevstr==left)
          fun(right,rop,mp,op);

       }

    }
    else {
        for(int i=0;i<str.length();i++)
        {
            string left=str.substr(0,i+1);
             mp[ch]=left;
             string rostr=str.substr(i+1);
             fun(rostr,rop,mp,op);
             mp.erase(ch);
        }
    }
}

int main(){
    string str,pattern;
    cin>>str>>pattern;
    unordered_map<char,string>mp;
    fun(str,pattern,mp,pattern);
    return 0;
}
