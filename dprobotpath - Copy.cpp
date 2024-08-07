//#include<bits/stdc++>
#include<iostream>
using namespace std;

int dp[100][100];

int noofways(int m,int n)
{

    if(dp[0][0]==-1)return 0;  // if first element is blocled then no way to reach further

    //base case
    for(int i=0;i<n;i++)
    {
        if(dp[0][i]!=-1)
        dp[0][i]=1;      // fill first row
    }
     for(int i=0;i<m;i++)
     {
         if(dp[i][0]!=-1)
         dp[i][0]=1;  // fill first col.
     }

     for(int i=1;i<m;i++)
     {
         for(int j=1;j<n;j++)
         {


             if(dp[i][j]==-1)  //IF BOX IS BLOCKED THEN leavi it
             {
                 continue;
             }

        //     dp[i][j]=0; // IF BOX IS BLOCKED THEN AFTER THAT BLOCKED BOX  EVERY BOX CONTAINS 0 AS THERE IS NO WAY TO REACH THEM

             if(dp[i-1][j]!=-1)     // CHK WETHER  FROM UP I.E TOP BOX  WE ARE COMING IS BLOCKED OR NOT
             {
                 dp[i][j]+=dp[i-1][j];
             }
             if(dp[i][j-1]!=-1)       // CHK WETHER  FROM LEFT WE ARE COMING IS BLOCKED OR NOT
             {
                 dp[i][j]+=dp[i][j-1];
             }
         }
     }
     if(dp[m-1][n-1]==-1)   // if the final answer is blocked then no way to reaCH IT
        return 0;


        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<"\n";
        }
        return dp[m-1][n-1]; // IT CONTAINS no. of was to reach the final answer

}

int main()
{
   //  memset(dp, 0 , sizeof dp );

    int m,n,p;// m= rows,n=col.s p=no. of boxes to be blocked



    cin>>m>>n>>p;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            dp[i][j]=0;

    }
    for(int i=0;i<p;i++)
        {
            int x,y;
            cin>>x>>y;
            dp[x][y]=-1;         // -1 represent that box is blocked
           // dp[x-1][y-1]=-1;      // -1 represent that box is blocked
    }
    cout<<noofways(m,n)<<"\n";
    return 0;


}
