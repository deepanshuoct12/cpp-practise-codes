#include<bits/stdc++.h>
using namespace std;
int cost[100][100];
int dp[100][100];

int solve(int r,int c){

dp[0][0]=cost[0][0];
for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
       if(i==0)
            dp[i][j]=dp[i][j-1]+cost[i][j];

            else if(j==0)
            dp[i][j]=dp[i-1][j]+cost[i][j];

            else
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+cost[i][j];
    }


}
return dp[r-1][c-1];

}
int main(){

    int r,c;
    cin>>r>>c;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>cost[i][j];
        }
    }
    cout<<solve(r,c);

    memset(dp,0,sizeof dp);
return 0;
}
