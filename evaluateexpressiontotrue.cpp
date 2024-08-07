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
unordered_map<string,int> mp;

int helper(string str,int i,int j,bool istrue)
{
    if(i>j)
        return 0;
    if(i==j)
    {
        if(istrue==true)
            return str[i]=='T';
        else
            return str[i]=='F';
    }

    string temp=to_string(i);
    temp.pb(' ');
    temp.append(to_string(j));
    temp.pb(' ');
    temp.append(to_string(istrue));

    if(mp.find(temp)!=mp.end())
    return mp[temp];
     int ans=0;
    for(int k=i+1;k<=j-1;k+=2)
    {
        int lt=helper(str,i,k-1,true);
        int lf=helper(str,i,k-1,false);
        int rt=helper(str,k+1,j,true);
        int rf=helper(str,k+1,j,false);

        if(str[k]=='&')
        {
            if(istrue==true)
                ans+=(lt*rt);
            else
                ans+=(lf)*(rt)+(lf)*(rf)+(lt)*(rf);
        }
        else if(str[k]=='|')
        {
            if(istrue==true)
                ans+=lt*rt+lt*rf+lf*rt;
            else
                ans+=lf*rf;
        }
        else if(str[k]=='^')
        {
            if(istrue==true)
            ans+=lt*rf+rt*lf;
            else
            ans+=lt*rt+lf*rf;
        }
    }
    return mp[temp]=ans;
}
int solve(string str)
{
    bool istrue;
    return helper(str,0,str.length()-1,istrue);
}
int32_t main()
{
	fast;
	string str;
	cin>>str;
	cout<<solve(str);
	return 0;
}

