#include<bits/stdc++.h>
using namespace std;

void go(string s,int open,int close,int pos,int n)
{
    if(pos==2*n)
    {
        if(open==close)
        {
            cout<<s<<"\n";
        }
        else
            return;
    }
    if(open>close)
    {

        go(s+")",open,close+1,pos+1,n);
    }

    if(open<n)
    {
        go(s+"(",open+1,close,pos+1,n);
    }
}
int main()
{

    int n;
    cin>>n;
    go("(",1,0,1,n);
}
