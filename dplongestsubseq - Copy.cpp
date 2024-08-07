#include<iostream>
using namespace std;

int lss(int arr[],int n)
{
    int dp[100];


    for(int i=0;i<n;i++)       // initially fill  dp with 1;
    dp[i]=1;

    int best=-1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]<=arr[i])         // chking weather arr[j]can be absorbed by arr[i] or not
            {
                    int curlen=1+dp[j];
                    dp[i]=max(curlen,dp[i]);

            }
        }
        best=max(best,dp[i]);
    }

    for(int i=0;i<n;i++)
        cout<<dp[i]<<" ";
    cout<<"\n";
    return best;

}
int main()
{
    int arr[]={ 3,2,10,1,20};

    int ans=lss(arr ,5);
    cout<<"\n"<<ans;
    return 0;
}
