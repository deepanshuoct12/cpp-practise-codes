#include<bits/stdc++.h>
using namespace std;

void fun(int i,int len, map<char,int>freq,string ans,char odd)
{

    if(i>len)
    {
        string temp=ans;
        reverse(temp.begin(),temp.end());
        string asf=ans;
        if(odd!='#')
        {
            asf+=odd;
        }
        asf+=temp;
        cout<<asf<<"\n";
    }
    for(auto x:freq)
    {
        char ch=x.first;
        int f=x.second;
        if(f>0){
        freq[ch]--;
        fun(i+1,len,freq,ans+ch,odd);
        freq[ch]=f;
        }
    }
}
int main(){
    string str;
    cin>>str;
map<char,int>freq;
    char odd='#';
    for(auto x:str)
     freq[x]++;

     int odds=0;
     int len=0;
     for(auto x:freq)
     {
         char ch=x.first;
         int f=x.second;
         if(f%2)
         {
             odd=ch;
             odds++;
         }
         freq[ch]=f/2;
         len+=(f/2);
     }
     if(odds>1)
     {
         cout<<-1;
     }
     else
     fun(1,len,freq,"",odd);

    return 0;
}
