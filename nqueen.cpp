#include<iostream>
using namespace std;
void init_code(){
   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
int board[10][10]={0};
 void print(int n)
 {
     for(int i=0;i<n;i++)
     {

         for(int j=0;j<n;j++)
          {
              if(board[i][j]==1)
                cout<<"Q";
                else
                cout<<"-";

          }
         cout<<"\n";
     }
       cout<<"\n";
 }

 bool issafeplace(int i,int j,int n)
 {
     //chking in that column
     for(int row=0;row<i;row++)
     {
         if(board[row][j]==1)
            return false;
     }

     // left diagonal
     int x=i,y=j;
     while(x>=0&&y>=0)
     {

         if(board[x][y]==1)
            return false;

         x--;
         y--;
     }
     // right diagonal
     x=i;
     y=j;
     while(x>=0 && y<n)
     {
         if(board[x][y]==1)
            return false;

         x--;
         y++;
     }

     return true;
 }


bool nqueen(int i,int n)
{

  if(i==n)
    {

        print(n);
      //  return true;//it means we got our config. so return true
       return false;//for all possible config.
    }

    for(int j=0;j<n;j++)
    {
        if(issafeplace(i,j,n))
        {
            board[i][j]=1;
              // placing a queen
               bool nextqueen=nqueen(i+1,n);

            if(nextqueen)  // if all the queen get Nplaced then true
            return true;

            board[i][j]=0;  // backtrack
        }

    }

    return false;//it means we had tried all possible positions but we are not able to place queen;

}


int main()
{
	init_code();
    int n;
    cin>>n;

   nqueen(0,n);

   return 0;

}

/*
#include<bits/stdc++.h>
using namespace std;
int grid[10][10];
void print(int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		cout<<grid[i][j]<<" ";
		cout<<"\n";
	}
}

bool issafe(int i,int j,int n)
{
	for(int I=0;I<n;I++)
	{
		if(grid[I][j])
		return false;

	}

	int x=i,y=j;
	while(x>=0 && y>=0)
	{
		if(grid[x][y])
		return false;

		x--;
		y--;
	}

	x=i;
	y=j;
	while(x>=0 && y<n)
	{
     	if(grid[x][y])
		return false;

		x--;
		y++;
	}

	return true;
}
bool nqueen(int n,int q)
{
	if(q==n)
	{
		return true;
	}

		for(int j=0;j<n;j++)
		{
			if(!issafe(q,j,n))
			continue;

			grid[q][j]=1;

			if(nqueen(n,q+1))
			return true;

			grid[q][j]=0;
		}

	return false;
}

int main()
{
	int n;
	cin>>n;
	memset(grid,0,sizeof(grid));
	int q=0;
	if(nqueen(n,q))
	{
		cout<<"YES"<<"\n";
		print(n);
	}
	else
	cout<<"NO";
	return 0;
}
*/
