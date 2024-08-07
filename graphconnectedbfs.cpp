#include<bits/stdc++.h>
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool isvalid(int x,int y,int n,int m)
{
    if(x<0 || x>=n || y<0 || y>=m)
    return false;

    return true;
}
void BFS(int i,int j,vector<string>& vec,int n,int m)
{
    queue<pair<int,int> >q;
    q.push(make_pair(i,j));
    while(!q.empty())
    {
        pair<int,int> p=q.front();
        q.pop();
        vec[p.first][p.second]='O';
        for(int i=0;i<4;i++)
        {
            int x=p.first+dx[i];
            int y=p.second+dy[i];

            if(isvalid(x,y,n,m) && vec[x][y]=='X')
            {
                q.push(make_pair(x,y));
            }
        }

    }
}
int Red(vector<string> &vec){
    int n=vec.size();
    int m=vec[0].size();
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(vec[i][j]=='X')
            {
                ans++;
                BFS(i,j,vec,n,m);
            }
        }
    }
    return ans;
}

int main(){
	vector<string> v;
	int n;
	cin>>n;
	string empty;
	getline(cin,empty);
	for(int i=0;i<n;i++)
	{
		string inp;
		getline(cin,inp);
		v.push_back(inp);
	}

	int ans = Red(v);
	cout<<ans;

	return 0;
}

