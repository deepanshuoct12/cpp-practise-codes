#include<bits/stdc++.h>
using namespace std;

void fun( vector<vector<int> > &chess,int ti,int ci,int i,int j)
{
    if(i==ti)
    {
        if(ci==ti){
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
        }
        return;
    }
    int nr=0;
    int nc=0;
    if(j==chess.size()-1)
    {
        nr=i+1;
        nc=0;
    }
    else{
        nr=i;
        nc=j+1;
    }
    chess[i][j]=1;
    fun(chess,ti,ci+1,nr,nc);
    chess[i][j]=0;
    fun(chess,ti,ci,nr,nc);
}
int main(){
    int n;
    cin>>n;
    vector<vector<int> >chess(n,vector<int>(n,0));
    fun(chess,n,0,0,0);
    return 0;
}
