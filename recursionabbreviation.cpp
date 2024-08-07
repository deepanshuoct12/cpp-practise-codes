#include<bits/stdc++.h>
using namespace std;

void fun(string str,string ans,int pos,int count)
{
    if(pos==str.length())
    {
        if(count==0)
        cout<<ans<<"\n";
        else
        cout<<ans<<count<<"\n";

        return;
    }

    string t=to_string(count);
    if(count>0)
    fun(str,ans+t+str[pos],pos+1,0);
    else
    fun(str,ans+str[pos],pos+1,0);

    fun(str,ans,pos+1,count+1);

}
int main()
{
    string str;
    cin>>str;
    fun(str,"",0,0);
}
