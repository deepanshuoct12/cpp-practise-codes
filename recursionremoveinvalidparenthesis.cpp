#include<bits/stdc++.h>
using namespace std;

int fun(string str)
{
    stack<char>st;

    for(auto x:str)
    {
        if(x=='(')
        st.push(x);
        else {
          // char ch=st.top();
            if(!st.empty() && st.top()=='(')
            st.pop();
            else
            st.push(')');
        }
    }
    return st.size();
}

void sol(string str, set<string> &st,int mr)
{
    if(mr==0)
    {
        if(fun(str)==0)
        {
            if(st.find(str)==st.end())
            {
                cout<<str<<"\n";
                st.insert(str);
            }
        }
        return;
    }

    for(int i=0;i<str.length();i++)
    {
        string left=str.substr(0,i);
        string right=str.substr(i+1);
        sol(left+right,st,mr-1);
    }
}
int main(){
    string str;
    cin>>str;
    int mr=fun(str);
     set<string>st;
    sol(str,st,mr);


    return 0;
}
