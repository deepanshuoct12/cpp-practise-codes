#include<bits/stdc++.h>
using namespace std;

void fun( vector<vector<int> >&chess,int cq,int tq)
{
    if(cq>tq)
    {
       for(int i=0;i<chess.size();i++)
       {
           for(int j=0;j<chess[0].size();j++)
           {
               if(chess[i][j]){
                   cout<<"q"<<chess[i][j]<<"  ";
               }
               else
               cout<<"-   "<<" ";
           }
           cout<<"\n";
       }
       cout<<"\n";
       return;
    }
    for(int i=0;i<chess.size();i++)
    {
        for(int j=0;j<chess[0].size();j++)
        {
            if(chess[i][j]==0)
            {
                chess[i][j]=cq;
                fun(chess,cq+1,tq);
                chess[i][j]=0;
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int> >chess(n,vector<int>(n,0));
    fun(chess,1,n);
    return 0;
}
