#include<bits/stdc++.h>
using namespace std;
#define int long long int

int n=4;
int dist[10][10] = { {0,20,42,25},{20,0,30,34},{42,30,0,10},{25,34,10,0}};  // adj matrtix

int visited_all = (1<<n)-1;
int dp[16][4];
int tsp(int mask,int pos){

    if(mask == visited_all){
        return dist[pos][0];
    }

    if(dp[mask][pos]!=-1)
    {

        return dp[mask][pos];
    }

    int ans = INT_MAX;
    for(int city = 0 ;city<n;city ++){
        if((mask & (1<<city) )==0)
        {
            int newans = dist[pos][city] + tsp(mask | (1<<city),city);
            ans = min(ans , newans);
        }
    }

    return dp[mask][pos] = ans;
}


int32_t main(){

for(int i=0;i<(1<<n);i++)
{
    for(int j=0;j<n;j++)
        dp[i][j]=-1;
}

cout<<tsp(1,0);      // mask is initially 0001 bcz city 1 is visited as we start from this city
}

