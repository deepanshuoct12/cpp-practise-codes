#include<bits/stdc++.h>
using namespace std;

bool check(int limit,int n,int k,int arr[])
    {
        long long int painters=1;
       long long  int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum>limit)
            {
                painters++;
                sum=arr[i];
            }
        }
        return painters<=k;
    }
    long long minTime(int arr[], int n, int k)
    {

       int lf=-1;
       long long int rt=0;
       for(int i=0;i<n;i++)
       {
           lf=max(lf,arr[i]);
           rt+=arr[i];
       }
       while(lf<rt)
       {
           long long int mid=(lf+rt)/2;

           if(check(mid,n,k,arr))
           rt=mid;
           else
           lf=mid+1;
       }

       return lf;
        // code here
        // return minimum time
    }
int main()
{
   int n,k;
   cin>>n>>k;
   int arr[n];
   for(int i=0;i<n;i++)
    cin>>arr[i];

     cout<<minTime(arr,n,k);
}
