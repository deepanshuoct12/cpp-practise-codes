
#include<iostream>
using namespace std;

//
//int memo[100];
int maxprofit(int arr[], int totallen)
{
    int dp[100]={};

    for(int len=1;len<=totallen;totallen++)
    {
        int best=0;
        for(int cut=1;cut<=len;cut++)
        {
             best=max(best, arr[cut]+dp[len-cut]);
            // best=max(best, arr[cut]+dp[totallen-len]);


        }
        dp[len]=best;
    }
    return dp[totallen];
}



/*int maxprofit(int arr[],int totallen)
{
    if(totallen==0)
        return 0;

        if(memo[totallen]!=-1)return memo[totallen]; //memoziation
    int best=0;
    for(int len=1;len<=totallen;len++)
    {

        int netprofit=arr[len]+maxprofit( arr , totallen-len );
        best=max(best,netprofit);

    }
    memo[totallen]=best;       //memoziation
    return best;

}*/

int main()
{
    int priceofeachlen[100];
    int totallen;
    cin>>totallen;

    for(int eachpiece=1;eachpiece<=totallen;totallen++)
    {
        cin>>priceofeachlen[eachpiece];
    }
    cout<<"\n";
    //for(int i=0;i<totallen;i++)
      //  memo[i]=-1;
    int ans= maxprofit(priceofeachlen , totallen);
    cout<<ans;
    return 0;
}
