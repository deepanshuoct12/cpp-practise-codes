#include<bits/stdc++.h>
using namespace std;


void fun(vector<int>v,int n,int r,int c)
{
    if(c>r)
    {
        for(auto x:v)
        cout<<x;
        cout<<"\n";
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(v[i]==0){
        v[i]=c;
        fun(v,n,r,c+1);
        v[i]=0;
        }
    }
}
int main()
{
    int n,r;
    cin>>n>>r;
    vector<int>v(n,0);
    fun(v,n,r,1);
    return 0;
}
