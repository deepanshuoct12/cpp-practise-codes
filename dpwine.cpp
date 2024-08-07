#include<iostream>
#include<cstring>
using namespace std;

int cnt=0; //  coumt no. of calls

int memo[100][100];

int maxprofit(int arr[], int be, int en ,int year)
{
    ++cnt;

    if(be>en)
        return 0;

    if(memo[be][en]!=-1)return memo[be][en];

    int q1=arr[be]*year+maxprofit(arr,be+1,en ,year+1);
    int q2=arr[en]*year+maxprofit(arr,be,en-1,year+1);
    int ans=max(q1,q2);
    memo[be][en]=ans; // record answer for particular range [be,en
    return ans;
}

int main()
{
    int arr[5]={2,3,1,4,5};


    memset(memo ,-1 , sizeof(memo));
    cout<<maxprofit(arr,0,4,1)<<"\n";
    cout<<cnt;


}
