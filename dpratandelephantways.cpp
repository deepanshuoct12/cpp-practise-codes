#include<bits/stdc++.h>
using namespace std;
int grid[100][100];
int dp[100][100];

int solve(int r,int c){

    dp[0][0]=1;

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++){
            if(i==0)
                dp[i][j]+=dp[i][j-1];

            else if(j==0)
                dp[i][j]+=dp[i-1][j];

            else
                dp[i][j]+=dp[i-1][j]+dp[i][j-1];

        }
    }
    return dp[r-1][c-1];

}

int solveelephant(int r,int c){

dp[0][0]=1;

for(int i=0;i<r;i++){

    for(int j=0;j<c;j++){
             int rsum=0,csum=0;
        for(int k=0;k<=j-1;k++)
            rsum+=dp[i][k];

        for(int k=0;k<=i-1;k++)
            csum+=dp[k][j];

         if(i==0&j!=0)
         dp[i][j]=rsum;


        else if(j==0&i!=0)
         dp[i][j]=csum;


        else if(i!=0 && j!=0)
         dp[i][j]=rsum+csum;
    }
}

// for(int i=0;i<r;i++)
// {
//     for(int j=0;j<c;j++)
//     cout<<dp[i][j]<<" ";

//      cout<<"\n";
// }
return dp[r-1][c-1];

}
int main(){

int r,c;
cin>>r>>c;
memset(dp,0,sizeof dp);
cout<<solveelephant(r,c);
return 0;
}
