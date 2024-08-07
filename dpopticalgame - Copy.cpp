//correct output
#include <bits/stdc++.h>
using namespace std;

// Returns optimal value possible that a player can
// collect from an array of coins of size n. Note
// than n must be even
int optimalStrategyOfGame(int* arr, int n)
{
    // Create a table to store solutions of subproblems
    int table[n][n];

    // Fill table using above recursive formula. Note
    // that the table is filled in diagonal fashion (similar
    // to http://goo.gl/PQqoS), from diagonal elements to
    // table[0][n-1] which is the result.
    for (int gap = 0; gap < n; ++gap) {
        for (int i = 0, j = gap; j < n; ++i, ++j) {

            // Here x is value of F(i+2, j), y is F(i+1, j-1) and
            // z is F(i, j-2) in above recursive formula
            int x = ((i + 2) <= j) ? table[i + 2][j] : 0;
            int y = ((i + 1) <= (j - 1)) ? table[i + 1][j - 1] : 0;
            int z = (i <= (j - 2)) ? table[i][j - 2] : 0;

            table[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z));
        }
    }

    return table[0][n - 1];
}


int main()
{
    int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];

   cout<<optimalStrategyOfGame(arr,n);
    return 0;
}

/*#include<iostream>       // WRONG OUTPUT
using namespace std;
int arr[100];
int f[4][4];
int maxmargin(int i,int j)
{
    if(j==i)
      {
          f[i][j]=arr[i];
      }

      if(j==i+1)
     f[i][j]=max(arr[i],arr[j]);

    f[i][j]=max(arr[i]+min(maxmargin(i+2,j),maxmargin(i+1,j-1))  ,  arr[j]+min(maxmargin(i,j-2),maxmargin(i+1,j-1)));

    return f[0][3];
}

int main()
{
    int arr[]={2,4,7,6};

    cout<<maxmargin(0,3);
}
*/
