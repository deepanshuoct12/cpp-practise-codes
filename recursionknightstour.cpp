#include<bits/stdc++.h>
using namespace std;
 int arr[6][6];
 int n;
void print(int r,int c,int moves)
{

    if(r<0 || r>=n || c<0 || c>=n || arr[r][c]!=0)
    return;
    else if(moves==n*n)
    {
        arr[r][c]=moves;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
            cout<<"\n";
        }
        cout<<"\n";
        arr[r][c]=0;
        return;
    }
    arr[r][c]=moves;
    print(r-2,c+1,moves+1);
    print(r-1,c+2,moves+1);
    print(r+1,c+2,moves+1);
    print(r+2,c+1,moves+1);

    print(r+2,c-1,moves+1);
    print(r+1,c-2,moves+1);
    print(r-1,c-2,moves+1);
    print(r-2,c-1,moves+1);
    arr[r][c]=0;
}
int main(){

    cin>>n;

    memset(arr,0,sizeof(0));
    int r,c;
    cin>>r>>c;
    print(r,c,1);
}
