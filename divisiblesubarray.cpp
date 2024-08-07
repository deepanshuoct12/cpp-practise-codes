#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[1000005],prefixsum[1000005];
int main()
{

 ios_base::sync_with_stdio(false);
 cin.tie(NULL);cout.tie(NULL);
 ll t,n;

 cin>>t;
 while(t>0)
 {

     cin>>n;

     memset(prefixsum,0,sizeof prefixsum);
     prefixsum[0]=1;
    ll sum=0;
     for(ll i=0;i<n;i++)
     {
         cin>>a[i];
         sum+=a[i];
         sum%=n;//
         sum=(sum+n)%n;// for negative no.
         prefixsum[sum]++;
     }
  ll ans=0;


     for(ll i=0;i<n;i++)
     {

         ll no =prefixsum[i];
         ans+=no*(no-1)/2;

     }
     cout<<ans;
     cout<<"\n";
         t--;
 }

}
