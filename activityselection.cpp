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


bool compare(pair<int,int> a,pair<int,int> b){

return a.s < b.s;

}

int32_t main()
{
	fast;
	int n;
  vector<pair<int,int> >v;
	test
	{
	    cin>>n;
	    for(int i=0;i<n;i++){

            int st,e;
            cin>>st>>e;
            v.push_back(make_pair(st,e));

	    }

	    sort(v.begin(),v.end(),compare);

	    int fin = v[0].s;

	    int res=1;
	    for(int i=1;i<n;i++){
            if(v[i].f>=fin)
            {
                fin = v[i].s;
                res++;
            }
	    }
	    cout<<res<<"\n";
	    v.clear();

	}
	return 0;
}
