#include<bits/stdc++.h>
using namespace std;

void fun(vector<char>&boxes,map<char,int>mp,int cb,int tb)
{
    if(cb>=tb)
    {


        for(auto x:boxes)
        cout<<x;
        cout<<"\n";
        return;
    }
    for(auto x:mp)
    {

        char ch=x.first;
        int freq=x.second;

      if(freq>0&& boxes[cb]=='-')
      {
          boxes[cb]=ch;
          mp[ch]--;
          fun(boxes,mp,cb+1,tb);
          mp[ch]=freq;
          boxes[cb]='-';
      }
    }
}
int main(){
    string str;
    cin>>str;
    map<char,int>mp;
    for(auto x:str)
    mp[x]++;
    int n=str.length();
    vector<char>boxes(n,'-');
    fun(boxes,mp,0,n);
    return 0;
}
