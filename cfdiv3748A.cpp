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
   int n;
   test
   {
      vector<int>v(3);
      cin>>v[0]>>v[1]>>v[2];
      unordered_map<int,int>mp;
      mp[v[0]]++;
      mp[v[1]]++;
      mp[v[2]]++;
      
      int mx=*max_element(v.begin(),v.end());
    //   int fl=1;
    //   for(int i=0;i<3;i++)
    //   {
    //       if(v[i]!=mx)
    //       {
    //           fl=0;
    //           break;
    //       }
    //   }
      
    //   if(fl==1)
    //   cout<<mx+1<<" "<<mx+1<<" "<<mx+1;
    //   else{
      for(int i=0;i<3;i++)
      {
        if(mx==v[i] && mp.find(mx)==mp.end())
        	cout<<0<<" ";
        else 
        	cout<<mx-v[i]+1<<" ";
      }
     // }
      cout<<"\n";
   }
	return 0;
}