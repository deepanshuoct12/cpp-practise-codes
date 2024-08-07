#include<bits/stdc++.h>
using namespace std;

int fun(vector<string>&v,vector<int>farr,vector<int>score,int idx)
{

    if(idx==v.size())
    {
        return 0;
    }
    int sno=0+fun(v,farr,score,idx+1);

    string word=v[idx];
    int sco=0;
    bool flag=true;
    for(int i=0;i<word.length();i++)
    {
        char ch=word[i];
        if(farr[ch-'a']==0)
        {
            flag=false;
        }
        sco+=score[ch-'a'];
        farr[ch-'a']--;
    }

    int sin=0;
    if(flag)
    {
         sin=sco+fun(v,farr,score,idx+1);
    }

   for(int i=0;i<word.length();i++)
    {
        char ch=word[i];
        farr[ch-'a']++;
    }
    return max(sin,sno);
}
int main(){
    int n;
    cin>>n;
    vector<string>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];

    int m;
    cin>>m;
    vector<int>farr(26,0);
    for(int i=0;i<m;i++)
    {
        char ch;
        cin>>ch;
        farr[ch-'a']++;
    }
    vector<int>score(26);
    for(int i=0;i<26;i++)
    cin>>score[i];

    cout<<fun(v,farr,score,0);
    return 0;
}
