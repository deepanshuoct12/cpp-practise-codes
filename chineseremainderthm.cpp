#include<bits/stdc++.h>
using namespace std;
#define ll long long


ll x,y,Gcd;
void extendedeuclid(ll a,ll b)
{

    if(b==0)
    {
        x=1;
        y=0;
        Gcd=a;
        return;
    }

    //recursive
    extendedeuclid(b,a%b);
    int cx=y;
    int cy=x-(a/b)*y;

    x=cx;
    y=cy;
}
// inverse modulo
ll inversemodulo(ll a,ll m)
{

    extendedeuclid(a,m);
    return(x+m)%m;  // we add m so that answer is positive .as extendedeuclid can return answer in negative also
}

ll  crt(vector<ll>num ,vector<ll>rem)
{
    ll prod=1ll;

    for(ll i=0;i<num.size();i++)
    {
        prod*=num[i];
    }
    vector<ll>pp;
    vector<ll>inv;
     for(ll i=0;i<num.size();i++)
    {
        pp.push_back(prod/num[i]);
        inv[i]=inversemodulo(pp[i],num[i]);

    }


    ll ans=0ll;

    for(ll i=0;i<rem.size();i++)
    {
        ans=ans+(((rem[i]*inv[i])%prod)*pp[i])%prod;
        ans=ans%prod;
    }

 return ans;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll t;

    cin>>t;
    while(t--)
    {
        vector<ll>num;
        vector<ll>rem;
        ll n,r;
        ll s;
        cin>>s;
        for(ll i=0;i<s;i++)
        {
            cin>>n>>r;
            num.push_back(n);
            rem.push_back(r);

        }

        cout<<crt(num,rem);


    }
}
