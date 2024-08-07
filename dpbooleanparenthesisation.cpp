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
int solve(string str1,string str2)
{
	int n=str1.length();
	int dpt[n][n];
	int dpf[n][n];
     memset(dpt,0,sizeof(dpt));
     memset(dpf,0,sizeof(dpf));
	for(int len=0;len<n;len++)
	{
		for(int i=0,j=len;j<n;i++,j++)
		{
			if(len==0)
			{
				char ch=str1[i];
				//cout<<ch<<" ";
				if(ch=='T')
				{
                   dpt[i][j]=1;
                   dpf[i][j]=0;
				}
				else{
                   dpt[i][j]=0;
                   dpf[i][j]=1;
				}
			}
			else{
				for(int k=i;k<j;k++)
				{
					char op=str2[k];
					//cout<<op<<" ";
					int ltc=dpt[i][k];
					int lfc=dpf[i][k];
					int rtc=dpt[k+1][j];
					int rfc=dpf[k+1][j];

					if(op=='&')
					{
						dpt[i][j]+=ltc*rtc;
						dpf[i][j]+=lfc*rtc+lfc*rfc+ltc*rfc;
					}
					else if(op=='|')
					{
                       dpt[i][j]+=ltc*rtc+ltc*rfc+rtc*lfc;
                       dpf[i][j]+=lfc*rfc;
					}
					else{
						dpt[i][j]+=ltc*rfc+lfc*rtc;
						dpf[i][j]+=ltc*rtc+lfc*rfc;
					}
				}
			}
		}
	} 

	// for(int i=0;i<n;i++)
	// {
	// 	for(int j=0;j<n;j++)
	// 		cout<<dpt[i][j]<<" ";
	// 	cout<<"\n";
	// }

	return dpt[0][n-1];
}
int32_t main()
{
   fast;
   init_code();
    string str1,str2;
    cin>>str1>>str2;
    cout<<solve(str1,str2);
	return 0;
}