#include<iostream>
using namespace std;

int board[10][10]={0};
 int c=0;
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


  if(board[i-1][j+2]==1||board[i+1][j+2]==1||board[i+2][j+1]==1||board[i+2][j-1]==1||board[i+1][j-2]==1||board[i-1][j-2]==1||board[i+2][j-1]==1||board[i-2][j+1]==1)
      return false;
	 /*
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
  */
     return true;
 }


bool nqueen(int i,int n)
{


  if(i==n)
    {
			c+=1;
        print(n);

       // return true;
       return false;//for all possible config.
    }

    for(int j=0;j<n;j++)
    {
        if(issafeplace(i,j,n))
        {
            board[i][j]=1;

        }
			/*if(j==n && i!=n)
			{
			  bool nextqueen=nqueen(i+1,j,n);
			  if(nextqueen)
			    return true;
			}  */        // placing a queen
			//if(j==n)
            bool nextqueen=nqueen(i+1,n);

            if(nextqueen)  // if all the queen get placed then true
            return true;

            board[i][j]=0;  // backtrack


    }

    return false;

}


int main()
{
    int n;
    cin>>n;

   nqueen(0,n);
    cout<<c<<"\n";
   return 0;

}
