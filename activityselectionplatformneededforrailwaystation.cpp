#include <bits/stdc++.h>
//https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/
using namespace std;

int minplatform(vector<int>arr,vector<int>dep)
{
   int n=arr.size();
   sort(arr.begin(),arr.end());
   sort(dep.begin(),dep.end());

   int i=0,j=0;
   int platform=0;
   int ans=0;
   while(i<n && j<n)
   {
       if(arr[i]<=dep[j])
       {
           i++;
           platform++;
       }
        else if(arr[i]>dep[j])
       {
           j++;
           platform--;
       }
       ans=max(ans,platform);
   }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n),dep(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i]>>dep[i];
    }
    cout<<minplatform(arr,dep);
}

