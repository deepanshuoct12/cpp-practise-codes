#include<bits/stdc++.h>
using namespace std;
void init_code(){
   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
int solve(int n,int k)
{
    int same=k;
    int diff=k*(k-1);
    int total=same+diff;
    for(int i=3;i<=n;i++)
    {
        same=diff;
        diff=total*(k-1);
        total=same+diff;
    }
    return total;
}
int main()
{
    int n,k;
    init_code();
    cin>>n>>k;
    cout<<solve(n,k);
}