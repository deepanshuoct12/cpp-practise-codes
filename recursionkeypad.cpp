#include<bits/stdc++.h>
using namespace std;
vector<string>mp={".;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};
vector<string>fun(string n)
{
    if(n.length()==0)
    return {""};

    char ch=n[0];
    vector<string>subans=fun(n.substr(1));
    vector<string>ans;
    for(int i=0;i<mp[ch-'0'].length();i++)
    {
        for(auto str:subans)
        {
            ans.push_back(mp[ch-'0'][i]+str);
        }
    }
    return ans;
}
int main(){
    string n;
    cin>>n;
    vector<string>v=fun(n);
    cout<<"[";
   for(int i=0;i<v.size();i++)
   {
       cout<<v[i];
      if(i!=v.size()-1)
       cout<<", ";

   }
    cout<<"]";

    return 0;
}
