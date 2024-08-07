#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
#define test ll t;cin>>t;while(t--)
#define f first
#define s second
#define pb push_back
#define pop pop_back
#define int long long int
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define mod 1000000007
#define inf 1LL<<60

bool prime[1000007];
int pre[1000007]={0};
int v[1000007]={0};
void sieve()
{
    memset(prime, true, sizeof(prime));
    prime[1]=false;
    for (int p=2; p*p<=1000007; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=1000007; i += p)
                prime[i] = false;
        }
    }
    // for (int p=2; p<=n; p++)
    //   if (prime[p])
    //       cout << p << " ";
}
int digitsum(int n)
{
    int sum=0;
    while(n)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}
void digit_prime()
{
    for(int i=0;i<=1000001;i++)
    {
        int dsum=digitsum(i);
        if(prime[dsum] && prime[i])
        v[i]=1;

    }

    for(int i=1;i<=1000001;i++)
    pre[i]=pre[i-1]+v[i];

}
int32_t main()
{
	fast;
	 sieve();
	 digit_prime();
   test
   {
      int t1,t2;
      cin>>t1>>t2;
      cout<<pre[t2]-pre[t1]+v[t1]<<"\n";

   }
	return 0;
}

