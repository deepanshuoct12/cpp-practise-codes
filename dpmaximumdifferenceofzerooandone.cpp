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
 //  init_code();
   int n;
    string str;
    cin>>str;
    n=str.length();
    vector<int>v;
    for(auto ch:str)
    { 
        if(ch=='1')
         v.pb(-1); 
         else 
         v.pb(1);
    }
    int mxsum=0;
    int sum=0;
    
   
    for(int i=0;i<n;i++)
    {
        sum+=v[i];
        if(sum<0)
        {
            sum=0;
        }
        mxsum=max(mxsum,sum);
    }
    int allzero=1,allone=1;
    for(auto x:str)
    {
        if(x=='0')
        allone=0;
    }
    
     for(auto x:str)
    {
        if(x=='1')
        allzero=0;
    }
    if(allzero || allone)
    mxsum=-1;
  //  cout<<allzero<<" "<<allone<<"\n";
    cout<<mxsum;
   return 0;
}