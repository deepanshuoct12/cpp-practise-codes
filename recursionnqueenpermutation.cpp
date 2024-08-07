#include<bits/stdc++.h>
using namespace std;
void init_code(){
   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
bool issafeplace(int row,int col,vector<vector<int> > chess)
{
    int n=chess.size();
    for(int i=0;i<n;i++)
    {
        if(chess[i][col])
        return false;
    }

     for(int j=0;j<n;j++)
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

    for(int i=row,j=col;i<n&&j>=0;i++,j--)
    {
        if(chess[i][j])
        return false;
    }
    for(int i=row,j=col;i<n&&j<n;i++,j++)
    {
        if(chess[i][j])
        return false;
    }
    return true;
}
void fun(vector<vector<int> >chess,int tq,int cq)
{
    if(cq>tq)
    {
        for(int i=0;i<chess.size();i++)
        {
            for(int j=0;j<chess[0].size();j++)
            {
                if(chess[i][j])
                {
                    cout<<"q"<<chess[i][j]<<"\t";
                }
                else
                cout<<"-"<<"\t";
            }
            cout<<"\n";
        }

        cout<<"\n"<<"\n"<<"\n";
        return;
    }

    for(int i=0;i<chess.size();i++)
    {
        for(int j=0;j<chess[0].size();j++)
        {
            if(chess[i][j]==0 && issafeplace(i,j,chess))
            {
                chess[i][j]=cq;
                fun(chess,tq,cq+1);
                chess[i][j]=0;
            }
        }
    }
}
int main(){
    init_code();
    int n;
    cin>>n;
    vector<vector<int> >chess(n,vector<int>(n,0));
    fun(chess,n,1);
    return 0;
}
