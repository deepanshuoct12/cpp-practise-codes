#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;

#define f first
#define s second
#define pb push_back
#define pop pop_back
#define int long long int



int32_t main()
{
	fast;
	int n,d;

	cin>>n>>d;
	vector<int>v(n);

	for(int i=0;i<n;i++)cin>>v[i];

	sort(v.begin(),v.end());
	int c=0;

	for(int i=0;i<n-1;i++)
    {
    if(v[i+1]-v[i]<=d)
        {
            c++;
            i+=1;
        }
    }

        cout<<c<<"\n";


	return 0;
}

