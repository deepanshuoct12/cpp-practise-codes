#include<iostream>
#include<cstring>
using namespace std;

int lcs(char X[ ] ,char Y[ ])           // WRONG ANSWER AARHA HAIN;
{
    int m=strlen(X);
    int n=strlen(Y);

    int dp[100][100];
    // base case
    for(int i=0;i<=m;i++)dp[i][0]=0;         // DP TABLE
    for(int j=0;j<=n;j++)dp[0][j]=0;


    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int q=0;
            if(X[i-1]==Y[j-1]) // WE DOSEN'T DO X[I]==Y[J] AS IN DP TABLE DP TABLE INDEXES ARE 1 LESS THAN M*N TABLE
            {
                q=1+dp[i-1][j-1];
            }
            else
            {
                q=max(dp[i-1][j],dp[i][j-1]);
            }
            dp[i][j]=q;

        }
    }
    return dp[m][n];
}
int main()
{
    char X[]="GXTGTAB";

    char Y[]="AGGTAB";

    cout<<"\n";

    cout<<lcs(Y,X);

    return 0;
}
