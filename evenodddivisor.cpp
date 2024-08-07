#include<bits/stdc++.h>
using namespace std;
#define ll long long
/*
// brute force
int main()
{

    ll q;
    cin>>q;
      ll n;
    while(q--)
    {
        cin>>n;
         ll e=0,o=0;
        for(ll i=1;i<=n;i++)
        {
            if(n%i==0)
            {

                if(i%2==0)
                    e++;
                else
                    o++;
            }
        }

        cout<<e-o<<"\n";
    }
}
*/
//sieve method
ll sum[100005];
void sieve()
{

    for(ll i=1;i<=100000;i++)
    {

        for(ll j=i;j<=100000;j+=i)
        {
            if(i%2==0)
                sum[j]+=i;
            else
                sum[j]-=i;
        }
    }
}
int main()
{

    ll q;
    cin>>q;
    ll n;
    sieve();

    while(q--)
    {

        cin>>n;
        if(n==0)
            cout<<0;

        cout<<sum[n]<<"\n";
    }
}
