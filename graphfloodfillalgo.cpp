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

int n,m;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
void floodfill(int input[50][50],int i,int j,int character,int color)
{
    if(i<0||j<0||i>=n||j>=m)
        return;

    if(input[i][j]!=character)
        return;

    input[i][j]=color;

    for(int k=0;k<4;k++)
    {
        floodfill(input,i+dx[k],j+dy[k],character,color);
    }
}
int32_t main()
{
	fast;

	cin>>n>>m;
    int input[50][50];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>input[i][j];
    }
    int character;
    cin>>character;
    int color;
    cin>>color;
    floodfill(input,2,1,character,color);

     for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<input[i][j];

            cout<<"\n";
    }
	return 0;
}


