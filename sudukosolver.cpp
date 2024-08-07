#include<bits/stdc++.h>
#include<vector>

using namespace std;
void init_code(){
   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
void print(int grid[9][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        cout<<grid[i][j]<<" ";
        cout<<"\n";
    }
}
bool canplace(int grid[9][9],int i,int j,int n)
{
    for(int k=0;k<9;k++)
    {
        if(grid[i][k]==n || grid[k][j]==n)
         return false;
    }
    int s=sqrt(9);
    int si=(i/s)*s;
    int sj=(j/s)*s;

    for(int I=si;I<si+s;I++)
    {
        for(int J=sj;J<sj+s;J++)
        {
            if(grid[I][J]==n)
            return false;
        }
    }
    return true;
}
bool solve(int grid[9][9],int i,int j){
    if(i==9)
    {
        return true;
    }
    if(j==9)
    {
        return solve(grid,i+1,0);
    }
    if(grid[i][j]>0)
    {
        return solve(grid,i,j+1);
    }

    for(int n=1;n<=9;n++)
    {
        if(!canplace(grid,i,j,n))
        continue;

        grid[i][j]=n;

        if(solve(grid,i,j+1))
        return true;

        grid[i][j]=0;
    }

    return false;
}
void sudoku_solve(int grid[9][9]) {
    //your logic here

    if(solve(grid,0,0))
    cout<<1;//print(grid);
    else {
    cout<<0;
    }
    cout<<"\n";
}

int main(void) {
    init_code();
    int n, board[9][9];
    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<9;j++) {
            for(int k=0;k<9;k++) {
                board[j][k] = 0;
                cin >> board[j][k];
            }
        }
        sudoku_solve(board);
    }
    return 0;
}
