#include<iostream>
using namespace std;
int arr[100];
int dp[100][100]={0};
int maxmargin(int i,int j)
{
    if(i>j)
        return 0;

        if(dp[i][j]!=0)
        return dp[i][j];

        int x = min(maxmargin(i+2,j),maxmargin(i+1,j-1));
        int y = min(maxmargin(i,j-2),maxmargin(i+1,j-1));

        int ans=max(arr[i]+x,arr[j]+y);

    return dp[i][j] = ans;
}

int main()
{
    int n;
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++)
       cin>>arr[i];
    int score1 = maxmargin(0,n-1);
    cout<<score1;
}
