#include<bits/stdc++.h>
using namespace std;


void helper(vector<vector<int>> &graph,int n,string str,vector<string>&ans,int i,int j)
    {
        if(i<0 ||i>=n ||j<0 ||j>=n || graph[i][j]==0)
        return;
        
        if(i==n-1 && j==n-1)
        {
            ans.push_back(str);
            return;
        }
        graph[i][j]=0;
        helper(graph,n,str+"R",ans,i,j+1);
        helper(graph,n,str+"U",ans,i-1,j);
        helper(graph,n,str+"L",ans,i,j-1);
        helper(graph,n,str+"D",ans,i+1,j);
        graph[i][j]=1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        helper(m,n,"",ans,0,0);
        sort(ans.begin(),ans.end());
        return ans;
        // Your code goes here
    }
// void print(int sol[][10],int m,int n)
// {
//     for(int i=0;i<=m;i++)
//     {
//         for(int j=0;j<=n;j++)
//         {
//             if(sol[i][j]==1)
//             {
//                 cout<<"*";
//             }
//             else
//                 cout<<"_";
//         }
//         cout<<"\n";
//     }
//     cout<<"\n";
// }

// bool ratinamaze(char maze[][10],int sol[][10],int i,int j,int m,int n)
// {
//     if(i==m&&j==n)
//     {
//         sol[m][n]=1;
//         print(sol,m,n);
//         return true;
//     }

//     if(i>m || j>n)
//     return false;

//     if(maze[i][j]=='X')
//     {
//         return false;
//     }
//  // asssume ans exist through current cell
//     sol[i][j]=1;

//     bool rightans= ratinamaze(maze,sol,i,j+1,m,n);
//     bool downans= ratinamaze(maze,sol,i+1,j,m,n);
//            sol[i][j]=0;   // backtrack
//     if(rightans || downans)
//     {
//         return true;
//     }

//     return false;
// }
// int main()
// {

//     char maze[][10]={"0000",
//                      "00X0",
//                      "000X",
//                      "0X00"
//     };

//     int sol[10][10]={0};
//     int m,n;
//     cin>>m>>n;
//    bool ans=ratinamaze(maze,sol,0,0,m-1,n-1);
//    if(ans==false)
//     cout<<"path dosent exist";
// }
