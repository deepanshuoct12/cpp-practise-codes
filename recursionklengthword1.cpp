#include<bits/stdc++.h>
using namespace std;

void fun(string str,int cb,int ci,int ti,vector<char>&items){
    if(cb==str.length())
    {
        if(ci==ti)
        {
            for(auto x:items)
            cout<<x;
              cout<<"\n";
        }


        return;
    }
    char ch=str[cb];
    for(int i=0;i<items.size();i++)
    {
        if(items[i]=='-')
        {
            items[i]=ch;
            fun(str,cb+1,ci+1,ti,items);
            items[i]='-';
        }
    }
      fun(str,cb+1,ci,ti,items);
}
int main()
{
    string str;
    cin>>str;
    int k;
    cin>>k;
   map<char,int>mp;
    string nstr="";
    for(int i=0;i<str.length();i++)
    {
        if(mp.find(str[i])==mp.end())
        {
            mp[str[i]]++;
            nstr+=str[i];
        }
    }
    vector<char>items(k,'-');
    // for(auto x:items)
    //         cout<<x;

         //   cout<<nstr;
   fun(nstr,0,0,k,items);
    return 0;
}
