#include <bits/stdc++.h>
#define inf 1000000000
#define ll long long int
using namespace std;
int main()
{
int t;
cin >> t;
while(t--)
{
int n, k;
cin >> n >> k;
int ans = inf;
int mp = 1;
for(int i=2; i*i<=k; i++)
{
if(k % i == 0) // a prime factor is i.
{
mp = 0; // number of occurences of i in k.
while(k % i == 0)
{
mp++;
k /= i;
}
int tmp = 0;
ll p = i;
while(p <= n)
{
tmp += n / p;
p*=i;
}
ans = min(ans, tmp / mp);
}
}
if(k > 1) // prime factor greater than sqrt(k).
{
int tmp = 0;
ll p = k;
while(p <= n)
{
tmp += n / p;
p *= k;
}
ans = min(ans, tmp);
}
if(ans == inf)
ans = 0;
cout << ans << endl;
}
return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{

     ll t;
     cin>>t;
     while(t--){

        ll n,k;
        cin>>n>>k;
          ll c=1;
          ll p,i;
          ll c2,ans=100005;
        for(i=2;i*i<=k;i++)
        {

            if(k%i==0)
            {
                 c=0;

                while(k%i==0)
                {
                     c++;
                    k/=i;

                }

                p=i;
                 c2=0;
                while(p<=n)
                {
                    c2+=n/p;

                    p*=i;
                }

                   // cout<<c2<<":"<<c<<"\n";
                ans = min(ans , c2/c);
            }
        }

        if(k>1)
        {

            ll p=k;

            while(p<=k)
            {

                c2+=n/p;
                p*=k;
            }
            ans = min(ans,c2);
        }


     //   cout<<ans<<"\n";
     }
}
*/
