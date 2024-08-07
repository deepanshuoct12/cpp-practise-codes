#include<bits/stdc++.h>
using namespace std;

 int getnum(string s,unordered_map<char,int>&mp)
 {   string temp="";
     for(int i=0;i<s.length();i++){
         temp+=to_string(mp[s[i]]);
     }

     int num=stoi(temp);
     return num;//10;
 }
void fun(vector<char>v,int idx,vector<bool>visited,unordered_map<char,int> &mp,string s1,string s2,string s3){

    if(idx==v.size())
    {
        //cout<<sum1<<" "<<sum2<<" "<<sum3<<"\n";
         int num1,num2,num3;
         num1=getnum(s1,mp);
         num2=getnum(s2,mp);
         num3=getnum(s3,mp);

        if(num1+num2==num3)
        {
            for(int i=0;i<26;i++)
            {
                char ch=(char)('a'+i);
                if(mp.find(ch)!=mp.end())
                {
                    cout<<ch<<"-"<<mp[ch]<<" ";
                }
            }
            cout<<"\n";
        }
        return;
    }
    char ch=v[idx];
    for(int i=0;i<=9;i++)
    {
      if(!visited[i])
       {
           mp[ch]=i;
           visited[i]=true;
           fun(v,idx+1,visited,mp,s1,s2,s3);
           visited[i]=false;
           mp[ch]=-1;
       }
    }
}
int main(){
  unordered_map<char,int>mp;
 string s1,s2,s3;

    cin>>s1>>s2>>s3;
    for(auto x:s1)
    mp[x]=-1;
    for(auto x:s2)
    mp[x]=-1;
    for(auto x:s3)
    mp[x]=-1;

    vector<char>v;

    for(auto x:mp)
    v.push_back(x.first);
//   for(auto x:v)
//   cout<<x<<" ";
    vector<bool>visited(10,false);
    fun(v,0,visited,mp,s1,s2,s3);

    return 0;
}
