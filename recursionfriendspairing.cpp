#include<bits/stdc++.h>
using namespace std;
int cnt = 1;
void fun(int n,vector<bool>& visited,string ans,int i)
{
	if(i>n)
	{
		cout<<cnt<<"."<<ans<<"\n";
		cnt++;
		return;
	}

	if(visited[i]==true){
		fun(n,visited,ans,i+1);
	}
	else {
	visited[i]=true;
	string t=to_string(i);
	fun(n,visited,ans+"("+t+") ",i+1);
	for(int j=i+1;j<=n;j++)
	{
		if(visited[j]==false){
			visited[j]=true;
			string t2=to_string(j);
			fun(n,visited,ans+"("+t+","+t2+") ",i+1);
			visited[j]=false;
		}
	}
	visited[i]=false;
	}
}
int main(){
	int n;
	cin>>n;


	vector<bool>visited(n+1,false);
	string ans="";
	fun(n,visited,ans,1);
	return 0;
}
