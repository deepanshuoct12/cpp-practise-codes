#include<bits/stdc++.h>
using namespace std;

void fun(string str,int ci,int ti,string ans,int lidx)
{
  if(ci>ti)
  {
      cout<<ans<<"\n";
      return;
  }
    for(int i=lidx+1;i<str.length();i++)
    {
        char ch=str[i];
      fun(str,ci+1,ti,ans+ch,i);
    }
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
    fun(nstr,1,k,"",-1);
    return 0;
}
