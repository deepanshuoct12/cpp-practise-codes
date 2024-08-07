#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
#define prDouble(x) cout<<fixed<<setprecision(10)<<x
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
void init_code(){
   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
int32_t main()
{
   fast;
   //init_code();
   int n;
   test
   {
   	string str;
   	cin>>str;
   	int i0=INT_MAX;
   	int i5=INT_MAX;
   	for(int i=str.length()-1;i>=0;i--)
   	{
   		if(str[i]=='0')
   		{
   			i0=i;
   			break;
   		}
   	}

   	for(int i=str.length()-1;i>=0;i--)
   	{
   		if(str[i]=='5')
   		{
   			i5=i;
   			break;
   		}
   	}
   	int sf=INT_MAX;
   	int tf=INT_MAX;
   	
   	if(i5!=INT_MAX)
   	{
   	int i7=i5-1;
   	int i2=i5-1;
   	while(i2>=0)
   	{
   		if(str[i2]=='2')
   			break;
   		i2--;
   	}

   	while(i7>=0)
   	{
   		if(str[i7]=='7')
   			break;
   		i7--;
   	}
   	

   	 sf=i5-i7-1+(str.length()-i5-1);
   	 tf=i5-i2-1+(str.length()-i5-1);
   	
   	}
   	
   	int zz=INT_MAX,ff=INT_MAX;

    if(i0!=INT_MAX)
    {
     int i00=i0-1;
     int i55=i0-1;
    while(i00>=0)
   	{
   		if(str[i00]=='0')
   			break;
   		i00--;
   	}

   	while(i55>=0)
   	{
   		if(str[i55]=='5')
   			break;
   		i55--;
   	}

   	 ff=i0-i55-1+(str.length()-i0-1);
   	 zz=i0-i00-1+(str.length()-i0-1);
   	
    }

   //cout<<ff<<" "<<zz<<" "<<sf<<" "<<tf<<"\n";
   	cout<<min(min(ff,zz),min(sf,tf))<<"\n";

   }
   
	return 0;
}