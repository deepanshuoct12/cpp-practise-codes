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

void multiply(int *arr,int &digit,int no)
{

    int carry=0;
    for(int i=0;i<digit;i++)
    {
        int p = arr[i]*no+carry;
        arr[i]=p%10;
        carry = p/10;
    }

    while(carry)
    {
        arr[digit]=carry%10;
        carry = carry/10;
        digit++;
    }
}

void factorial(int n)
{

   int arr[1000];
   for(int i=0;i<1000;i++)
    arr[i]=0;

   arr[0]=1;
   int digit = 1;
   for(int i=2;i<=n;i++)
   {
       multiply(arr,digit,i);
   }

   reverse(arr,arr+digit);
   for(int i=0;i<digit;i++)
   {
       cout<<arr[i];
   }
}
int32_t main()
{
	fast;
	int n;
    cin>>n;
    factorial(n);
	return 0;
}

