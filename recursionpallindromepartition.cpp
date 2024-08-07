#include<bits/stdc++.h>
using namespace std;

bool ispallindrome(string s)
{
    string t=s;
    reverse(t.begin(),t.end());
    return t==s;
}
void fun(string str,string ans)
{

    if(str.size()==0)
    {
        cout<<ans<<"\n";
    }
    for(int i=0;i<str.length();i++)
    {
        string prefix=str.substr(0,i+1);
        string rem=str.substr(i+1);
        if(ispallindrome(prefix))
        {
            fun(rem,ans+"("+prefix+") ");
        }
    }
}

int main(){
    string str;
    cin>>str;
    fun(str,"");

    return 0;
}
