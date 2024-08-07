#include<bits/stdc++.h>
using namespace std;

bool issafeplace(int row,int col,vector<vector<int> > chess)
{
    int n=chess.size();
    for(int i=row;i>=0;i--)
    {
        if(chess[i][col])
        return false;
    }

     for(int j=col;j>=0;j--)
    {
        if(chess[row][j])
        return false;
    }

    for(int i=row,j=col;i>=0&&j>=0;i--,j--)
    {
        if(chess[i][j])
        return false;
    }
     for(int i=row,j=col;i>=0&&j<n;i--,j++)
    {
        if(chess[i][j])
        return false;
    }
    return true;
}
void fun( vector<vector<int> >chess,int cq,int tq,int lc)
{
    if(cq>tq)
    {
        for(int i=0;i<chess.size();i++)
        {
            for(int j=0;j<chess[0].size();j++)
            {
                if(chess[i][j])
                cout<<"q"<<"\t";
                else
                cout<<"-"<<"\t";
            }
            cout<<"\n";
        }
        cout<<"\n";
        return;
    }

     for(int cell=lc+1;cell<chess.size()*chess.size();cell++)
     {
         int row=cell/chess.size();
         int col=cell%chess.size();

        if(issafeplace(row,col,chess)){
         chess[row][col]=1;
         fun(chess,cq+1,tq,cell);
         chess[row][col]=0;
        }
     }
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int> >chess(n,vector<int>(n,0));
    fun(chess,1,n,-1);
    return 0;
}
