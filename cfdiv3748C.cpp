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
   init_code();
   int n,k;
   test
   {
      cin>>n>>k;
      unordered_map<int,int>mp;
      for(int i=0;i<k;i++)
      {
          int x;
          cin>>x;
          mp[x]++;
      }
     vector<int>v;
     for(auto x:mp)
     {
         v.pb(x.f);
     }
     
      sort(all(v));
      int ans=1;
      vector<int>suff;
     for(int i=0;i<v.size();i++)
     {
         suff.pb(n-v[i]);
     }
     
    //   for(auto x:suff)
    //  cout<<x<<" ";
    //  cout<<"\n";
     
     for(int i=suff.size()-2;i>=0;i--)
     {
         suff[i]+=suff[i+1];
     }
      int mx=v[v.size()-1];
    // cout<<mx<<"\n";
     
    //  for(auto x:suff)
    //  cout<<x<<" ";
    //  cout<<"\n";
    
      for(int i=0;i<suff.size();i++)
      {
        if(mx>suff[i])
        {
            ans=suff.size()-(i);
            break;
        }
      }
     cout<<ans<<"\n";
   }
    return 0;
}