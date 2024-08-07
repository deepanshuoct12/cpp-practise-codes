#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll fastexp(ll a,ll b,ll mod)
{

    if(b==0)
    {

        return 1;
    }
    ll res=1;
    while(b>0)
    {

        if(b&1)
        {
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        b=b>>1;
    }

    return res;
}


//
ll solve(ll n,ll p){


ll ans=-1;
ll temp;
for(ll i=(n+1);i<=(p-1);i++)
{
     temp=fastexp(i,p-2,p);
    ans=(ans*temp)%p;

}

return(ans+temp);  // make answer positive as it is negative
}
int main()
{
    ll t,n,p;
    cin>>t;
    while(t--)
    {


        cin>>n>>p;
        if(n>=p)
        {

            cout<<"0";
        }

        else{

            cout<<solve(n,p)<<"\n";
        }
    }




}
