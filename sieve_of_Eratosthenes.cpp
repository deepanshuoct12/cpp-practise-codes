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
#define mod 1000000007
#define inf 1LL<<60
#define N 100005
int pr[N+2];
vector<int>primes;
void sieve()
{
    memset(pr,1,sizeof(pr));
    primes.pb(2);
   for(int i=3;i<=N;i+=2)
   {
       if(pr[i])
       {
           primes.pb(i);
           for(int j=i*i;j<=N;j+=i)
           {
               pr[j]=0;
           }
       }
   }
}

///second sieve

void sieve()
{   bool prime[10000008];
    memset(prime, true, sizeof(prime));
    vector<int>primes;
    for (int p=2; p<=10000005; p++)
    {
        if (prime[p] == true)
        {
		//	primes.pb(p);
            for (int i=p*p; i<=10000005; i += p)
                prime[i] = false;
        }
    }
}


//FOR PRIMES NUMBERS LESS THAN N
void SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p greater than or
            // equal to the square of it
            // numbers which are multiple of p and are
            // less than p^2 are already been marked.
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for (int p=2; p<=n; p++)
       if (prime[p])
          cout << p << " ";
}

int32_t main()
{
	fast;
	int n;
      cin>>n;
      sieve();
      for(int i=0;i<n;i++)
        cout<<primes[i]<<" ";

	return 0;
}


