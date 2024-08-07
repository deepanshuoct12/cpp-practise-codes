#include<bits/stdc++.h>
using namespace std;

#define ll long long
 vector<ll>primes(1000001,0);
// sieve

void sieve()
{
      primes[2]=1;


        for(ll i=3;i<=100000;i+=2)
            primes[i]=1;

    for(ll i=3;i<=100000;i+=2)
    {
        if(primes[i])  // if no. is prime
       {

        for(ll j=i*i;j<=100000;j+=2*i)
        {
            primes[j]=0;
        }

       }
    }


}

// prime no. upto n
// prime no. upto n

vector<ll> prime(ll n)
{
    sieve();
     vector<ll>p;
     p.push_back(2);
     for(ll i=3;i<=1000001 && p.size()!=n ;i++)
     {
         if(primes[i])
            p.push_back(i);
     }
    return p;
}
// segmented sieve

void segmentedsieve(ll a,ll b)
{

    sieve();
    vector<ll>pp(b-a+1,1);  // pp is array that contains 0 or 1

    for(ll i=2;i*i<=b;i++)
    {

        for(ll j=a;j<=b;j++)
        {
            if(primes[i])
            {
                if(j==i)  // avoid overlap
                    continue;

                if(j%i==0)
                {
                    pp[j-a]=0;
                }
            }
        }
    }
    // print

    for(ll i=a;i<=b;i++)
    {

        if(pp[i-a])
        {
            cout<<i<<" ";
        }
    }

}
//factorize

vector<pair<ll,ll> >factorize(vector<ll> v,ll n)
{

    vector< pair<ll,ll> >factors;

    ll p1 =v[0];
    ll i=0,c;
    while(p1*p1<n)
    {

        if(n%p1==0)
        {
         c=0;

        while(n%p1==0)
        {
            n=n/p1;
            c++;
        }
        }
         factors.push_back({p1,c});
        i++;
        p1=v[i];
    }

    if(n>1)  // if n is prime
        factors.push_back({n,1});
    return factors;
}

int main()
{

 //   segmentedsieve(25,36);
    ll n;
    cin>>n;

     vector<ll> v;
     v.clear();
     v=prime(100);

     vector<pair<ll,ll> >f;
     f=factorize(v,n);

     for(ll i=0;i<f.size();i++)
        cout<<f[i].first<<" "<<f[i].second<<"\n" ;

    /* for(ll i=0;i<v.size();i++)
     {

         cout<<v[i]<<" ";
     }*/

     // print sieve
   /* for(ll i=0;i<=n;i++)
    {

        if(primes[i])
            cout<<i<<" ";
    }*/
     /*
    int n,f=0;

    cin>>n;

    for(int i=2;i*i<=n;i+=2  )
    {

        if(n%i==0)
        {
            f=1;
            break;
        }
    }
    if(f==1)
        cout<<"not prime";
    else
        cout<<" prime";
*/

}
