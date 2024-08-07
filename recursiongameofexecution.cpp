#include<bits/stdc++.h>
using namespace std;

int fun(int n,int k)
{
    if(n==1)
    return 0;

    int x=fun(n-1,k);
    return (x+k)%n;
}
int main()
{
    int n,k;
    cin>>n>>k;
    cout<<fun(n,k);
    return 0;
}
