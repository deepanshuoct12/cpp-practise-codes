#include<bits/stdc++.h>
using namespace std;
#define ll long long int


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
    ll cx=y;
    ll cy=x-(a/b)*y;

    x=cx;
    y=cy;
}

ll fastexp(ll a,ll b , ll mod)
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
        b>>1;
    }

    return res;
}

int main()
{
    ll n;
    string m;
    cin>>n>>m;
      // m%n;
      ll sum=0;
      reverse(m.begin(),m.end());
       cout<<m;
      for(ll i=0;i<m.length();i++)
      {

         //  cout<<fastexp(10,i,n)<<"\n";
//         sum+=((pow(10,i)%n)*(m[i]-'0')%n);
          sum+=(fastexp(10,i,n)*((m[i]-'0')%n));
//cout<<fastexp(10,i,n)<<"\n";


      }
       cout<<sum<<"\n";
      extendedeuclid(n,sum);
      cout<<Gcd;


}

