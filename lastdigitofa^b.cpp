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

int modulo(string b,int m)
{
    reverse(b.begin(),b.end());
    int prod=0;
    for(int i=0;i<b.length();i++)
    {
        prod=(prod*10 + b[i]-'0')%m;
    }
    return prod;
}
int fun(string a,string b)
{

    int lena=a.length();
    int lenb=b.length();

    if(lenb==1 && b[0]==0)
        return 1;
    if(lena==1 && a[0]==0)
        return 0;

    int exp = (modulo(b,4)==0)?4:modulo(b,4);

    int res=pow(a[lena-1]-'0',exp);

    return res%10;
}
int32_t main()
{
	fast;
	string a,b;
	cin>>a>>b;
	cout<<fun(a,b);
	return 0;
}

