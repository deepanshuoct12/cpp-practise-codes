//https://www.geeksforgeeks.org/find-pair-with-greatest-product-in-array/
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

int32_t main()
{
	fast;
	int n;
      cin>>n;
      int arr[n];
      unordered_map<int,int> mp;
      for(int i=0;i<n;i++)
      {
          cin>>arr[i];
          mp[arr[i]]++;
      }

      sort(arr,arr+n);
      int f=0;
      int ans=0;
      for(int i=n-1;i>=0;i--)
      {
          for(int j=0;j<sqrt(arr[i]);j++)
          {
              if(arr[i]%arr[j]==0)
              {
                  int result=arr[i]/arr[j];
                  if(result!=arr[j] && mp[result]>0)
                    {
                        ans=arr[i];
                        f=1;
                        break;
                    }

                  else if(result==arr[j] && mp[result]>1)
                    {
                        ans=arr[i];
                        f=1;
                        break;
                    }
              }
          }
          if(f==1)
          {
              break;
          }
      }

      cout<<ans<<"\n";
	return 0;
}

