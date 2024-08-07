#include<bits/stdc++.h>
using namespace std;

vector<int>fun(vector<int> &v,vector<pair<int,int> > &freq)
{
    stack<pair<int,int> >s;
    vector<pair<int,int> >rev=freq;
   // reverse(rev.begin(),rev.end());
    vector<int>ans;
    int n=freq.size();
     for(int i=n-1;i>=0;i--)
     {
         while(!s.empty() && freq[i].second>=s.top().second)
            s.pop();

         if(s.empty())
            ans.push_back(-1);
         else
            ans.push_back(s.top().first);

         s.push(freq[i]);
     }
     reverse(ans.begin(),ans.end());
     return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    unordered_map<int,int> mp;

    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        mp[v[i]]++;
    }

    vector<pair<int,int> > freq;
    for(int i=0;i<n;i++)
    {
        freq.push_back({v[i],mp[v[i]]});
    }

    vector<int>ans = fun(v,freq);

     for(auto x:ans)
        cout<<x<<" ";
    return 0;
}
