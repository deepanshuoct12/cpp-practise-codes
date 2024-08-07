#include<iostream>

#include<vector>

using namespace std;

void floodfill(vector<vector<int> >maze,int i,int j,int n,int m,vector<vector<bool> >&visited,string s)
{
 if(i<0 || i>=n || j<0 || j>=m ||maze[i][j] || visited[i][j])
 return;

 if(i==n-1 && j==m-1)
 {
     cout<<s<<"\n";
 }
 visited[i][j]=true;
 floodfill(maze,i-1,j,n,m,visited,s+"t");
  floodfill(maze,i,j+1,n,m,visited,s+"r");
   floodfill(maze,i+1,j,n,m,visited,s+"d");
    floodfill(maze,i,j-1,n,m,visited,s+"l");
    visited[i][j]=false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector < int > (m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];


    vector<vector<bool> >visited(n,vector<bool>(false));

    floodfill(arr,0,0,n,m,visited,"");
}
