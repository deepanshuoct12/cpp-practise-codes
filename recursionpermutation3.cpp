class Solution {
public:
//approach1 
    //     void helper(vector<vector<string>> &chess,int tq,int cq,vector<vector<int> > &mat)
//     {
//         if(cq>tq)
//         {    
//            vector<string>v;
//            for(int i=0;i<tq;i++)
//            {    string str;
//                for(int j=0;j<tq;j++)
//                {
//                    if(mat[i][j]==1)
//                    {
//                        str.push_back('Q');
//                    }
//                    else
//                        str.push_back('.');
//                }
//                v.push_back(str);
//            }
//             chess.push_back(v);
//             return;
//         }
        
//         for(int i=0;i<tq;i++)
//         {
//             for(int j=0;j<tq;j++)
//             {  
               
//                 if(mat[i][j]==0 && issafe(mat,i,j,tq))
//                 {           
//                     mat[i][j]=1;
//                     helper(chess,tq,cq+1,mat);
//                     mat[i][j]=0;
//                 }
//             }
//         }
//     }
 vector<vector<string> >chess;
    //approach2
//     bool isafe(int i,int j,vector<string>mat)
//     {
//         int n=mat.size();
        
//         for(int c=0;c<n;c++)
//             if(mat[i][c]=='Q')
//                 return false;
        
//          for(int r=0;r<n;r++)
//             if(mat[r][j]=='Q')
//                 return false;
        
//         for(int r=i,c=j;r>=0 && c>=0 ;c--,r--)
//             if(mat[r][c]=='Q')
//                 return false;
        
//          for(int r=i,c=j;r<n && c<n;c++,r++)
//             if(mat[r][c]=='Q')
//                 return false;
        
//          for(int r=i,c=j;r<n && c>=0 ;c--,r++)
//             if(mat[r][c]=='Q')
//                 return false;
        
//          for(int r=i,c=j;r>=0 && c<n ;c++,r--)
//             if(mat[r][c]=='Q')
//                 return false;
        
//         return true;
        
//     }
//     void helper(int i,vector<string>&mat,int n)
//     {
//         if(i>=n)
//         {
//             chess.push_back(mat);
//             return;
//         }
//         for(int j=0;j<n;j++)
//         {
//             if(mat[i][j]=='.' && isafe(i,j,mat))
//             {
//                 mat[i][j]='Q';
//                 helper(i+1,mat,n);
//                 mat[i][j]='.';
//             }
//         }
//     }
    
    //hash approach
     void helper3(int i,vector<string>&mat,int n,vector<int>&col,vector<int>&diagonal1,vector<int>&diagonal2)
    {
       if(i>=n)
       {
           chess.push_back(mat);
           return;
       }
         
         for(int j=0;j<n;j++)
         {
             if(mat[i][j]=='.' && col[j]==0 && diagonal1[i+j]==0 && diagonal2[n-1+j-i]==0)
             {
                 mat[i][j]='Q';
                 col[j]=1;
                 diagonal1[i+j]=1;
                 diagonal2[n-1+j-i]=1;
                 helper3(i+1,mat,n,col,diagonal1,diagonal2);
                 mat[i][j]='.';
                 col[j]=0;
                 diagonal1[i+j]=0;
                 diagonal2[n-1+j-i]=0;
             }
         }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>mat(n,string(n,'.'));
        //helper(0,mat,n); 
        vector<int>col(n,0),diagonal1(2*n-1),diagonal2(2*n-1);
        helper3(0,mat,n,col,diagonal1,diagonal2);
        return chess;
    }
};