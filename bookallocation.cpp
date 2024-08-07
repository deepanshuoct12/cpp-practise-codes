#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;

bool func(ll *arr,ll num)
{

    ll c=1;
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
/*
        if(sum+arr[i]>num)
        {
            c++;
            sum=arr[i];
            if(c>m)
                return false;
        }
        else
        {
            sum+=arr[i];
        }*/
       if(sum<=num)
        {
            continue;
        }
        c++;
        if(c>m)
            return false;
        sum=arr[i];
    }

    return true;
}
ll ba(ll *arr)
{
    ll sum=0;
    ll s=0;
    for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            s=max(s,arr[i]);
        }


    ll e=sum;
    ll mid,ans=INT_MAX;


    while(s<=e)
    {


        mid=(s+e)/2;

        if(func(arr,mid))
        {   // left part
            e=mid-1;
           // if(mid<ans)
                ans=min(ans,mid);
        }
        else
        {
            s=mid+1;
        }
    }

    return ans;
}
int main()
{


    cin>>n>>m;
    ll arr[n];
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<ba(arr);

}
