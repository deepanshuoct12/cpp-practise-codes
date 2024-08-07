#include<bits/stdc++.h>
using namespace std;

void fun(string asf,int cb,int tb,int cr,int tr)
{
    if(cb>tb)
    {
        if(cr==tr)
        {
            cout<<asf<<"\n";
        }
        return;
    }
    fun(asf+"i",cb+1,tb,cr+1,tr);
    fun(asf+"-",cb+1,tb,cr,tr);
}
int main(){
    int n,r;
    cin>>n>>r;
    fun("",1,n,0,r);
    return 0;
}
