#include<bits/stdc++.h>
using namespace std;

int main()
{  ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

////////////first method//////////////
 map<int,int>mp;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
         mp[arr[i]]++;
    }
    int idx=1;
    for(auto x:mp) //coordintae compression
    {
        mp[x.f]=idx;
        idx++;
    }
    for(int i=1;i<=n;i++)
    {
         arr[i]=mp[arr[i]];
    }

    //////////////////second method////////
 //   map<int,int> m;
	// int n;
	// cin>>n;
	//  int a[100005];
	//  set <int, greater <int> > s;
	// for(int i=0;i<n;i++)
 //       {
 //           cin>>a[i];
 //           s.insert(a[i]);

 //       }

 //       int index=1;
 //       set <int, greater <int> > :: iterator itr;
 //    for (itr = s.begin(); itr != s.end(); ++itr)
 //    {
 //        m.insert(pair<int, int>(*itr, index));
 //        s.erase(*itr);
 //       //map[*itr]=index;
 //       index++;
 //    }
 //    for(int i=0;i<n;i++)
 //    {

 //        a[i]=m[a[i]];
 //    }
 //    cout<<"\n";
 //   for(int i=0;i<n;i++)
 //   {

 //       cout<<a[i]<<" ";
 //   }



}
