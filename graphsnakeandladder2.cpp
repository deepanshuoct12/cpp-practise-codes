class Solution {
public:
    int bfs(int src,vector<int>graph[],int N)
    {
        queue<int>q;
        q.push(src);
        vector<int>dist(N,-1);
        dist[src]=0;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            for(auto v:graph[curr])
            {
                if(dist[v]==-1)
                {
                  q.push(v);
                  dist[v]=dist[curr]+1;
                }
            }
        }

        return dist[N-1];
    }


    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        int N=n*n;
        vector<int>b(N,0);
        int cnt=0;
        int f=0;
        for(int i=n-1;i>=0;i--)
        {
            if(f==0)
            {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]!=-1)
                {
                       b[cnt]=board[i][j]-1-cnt;
                       //cout<<cnt<<" ";
                }
                cnt++;
            }
                f=1;
           }
            else
            {
            for(int j=n-1;j>=0;j--)
            {
                if(board[i][j]!=-1)
                {
                       b[cnt]=board[i][j]-1-cnt;
                       //cout<<cnt<<" ";
                }
                cnt++;
            }
                f=0;
          }

        }
        vector<int>graph[N];
     //   cout<<N<<"\n";
        for(int u=0;u<N;u++)
        {  //cout<<u<<":"<<" ";
            for(int dice=1;dice<=6;dice++)
            {
                if(u+dice>=N)
                    break;
                 int v=u+dice+b[u+dice];
                //  cout<<v<<" ";
                    graph[u].push_back(v);

            }
        // cout<<"\n";
        }

        return bfs(0,graph,N);
        return -1;
    }
};
