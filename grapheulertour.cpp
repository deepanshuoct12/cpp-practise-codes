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

vector<int> graph[1000];
int timein[1000],timeout[1000],timer;
void  eulertour1(int curr,int par)
{
  // cout<<curr<<" ";
   //enter a node
   timein[curr]=timer++;
    for(auto x:graph[curr])
    {
        if(x!=par)
          {
              eulertour1(x,curr);
             //cout<<curr<<" ";
           timeout[curr]=timer++;
         //comeback to that node
          }
    }
    return;
}

void  eulertour2(int curr,int par)
{
   // cout<<curr<<" ";
   //enter a node
    timein[curr]=timer++;
    for(auto x:graph[curr])
    {
        if(x!=par)
        eulertour2(x,curr);
    }
    //leave a node
     timeout[curr]=timer++;
    // cout<<curr<<" ";
    return;
}

void  eulertour3(int curr,int par)
{
    //cout<<curr<<" ";
    //enter a node
    timein[curr]=timer++;
    for(auto x:graph[curr])
    {
        if(x!=par)
        eulertour3(x,curr);
    }
    //leave a node
    timeout[curr]=timer;
    return;
}
//chk if x is ancestor of y or not
bool isancestor(int x,int y)
{
    return (timein[x]<=timein[y] && timeout[y]<=timeout[x]);
}
int32_t main()
{
	fast;
	int n;
     cin>>n;
     for(int i=0;i<n-1;i++)
     {
         int x,y;
         cin>>x>>y;
         graph[x].push_back(y);
         graph[y].push_back(x);
     }
     timer=1;
    //  eulertour1(1,0);
    //  cout<<"\n";
     eulertour2(1,0);
     cout<<"\n";
    //  //timer=0;
    //  eulertour3(1,0);

    if(isancestor(1,7))
    cout<<"yes";
    else
    cout<<"no";
    //  for(int i=1;i<=n;i++)
    //  {
    //      cout<<i<<" "<<timein[i]<<" "<<timeout[i]<<"\n";
    //  }
	return 0;
}

