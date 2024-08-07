#include<bits/stdc++.h>
using namespace std;

void fun( vector<vector<int> >chess,int cq,int tq,int li,int lj)
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

     for(int col=lj+1;col<chess[0].size();col++)
     {
          if(chess[li][col]==0)
            {
                chess[li][col]=1;
                fun(chess,cq+1,tq,li,col);
                chess[li][col]=0;
            }
     }
    for(int row=li+1;row<chess.size();row++)
    {
        for(int col=0;col<chess[0].size();col++)
        {

                chess[row][col]=1;
                fun(chess,cq+1,tq,row,col);
                chess[row][col]=0;

        }
    }
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int> >chess(n,vector<int>(n,0));
    fun(chess,1,n,0,-1);
    return 0;
}
