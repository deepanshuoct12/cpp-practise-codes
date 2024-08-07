#include <iostream>
#include<algorithm>
#include<vector>
//#include<iostream>
using namespace std;

int *connectedcomponents2(int **adj,int V,int start,vector<bool>visited,int*arr,int size, int k=0)
{
  if(visited[start])
    return NULL;
 // int k=0;
  arr[k++]=start;
  visited[start]=true;

  for(int i=0;i<V;i++)
  {
    if(adj[start][i]==1&&visited[start]==false)
    {
      visited[start]=true;
     // int *ans=new int [V];
    arr=connectedcomponents2(adj,V,i,visited,arr,size,k);
    }

  }
  arr[k]=NULL;
  return arr;
}


 int*connectedcomponents(int **adj,int V,int *arr,int size)
 {
     vector<bool>visited(V,false);
  // int size2=V;
   //int *arr=new int[size2];
 //  int *arr=new int[size2];
 //  int j=0;

   for(int i=0;i<V;i++)
   {
     if(visited[i]==false)
   arr = connectedcomponents2(adj,V,i,visited,arr,size);
     int j=0;
     if(*arr!=NULL)
     { sort(arr, arr+size);

     while(arr[j]!=NULL)
     {
       cout<<arr[j];
       j++;
     }
      cout<<endl;
    // ans[j]=nullptr;
     //j++;
     }
   }
   //return ans;

 }


int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;

  int **adj=new int*[V];

  for(int i=0;i<V;i++)
  {
    adj[i]=new int[V];
    for(int j=0;j<V;j++)
    {
      if(i==j)
        adj[i][j]=1;
      else
      adj[i][j]=0;

    }

  }
  for(int i=0;i<E;i++)
  {
    int a,b;
    cin>>a>>b;
    adj[a][b]=1;
    adj[b][a]=1;
  }

 // vector<bool>visited(V,false);
  int *ans=new int[V];
 int size=V;
 connectedcomponents(adj,V,ans,size);

 /* for(int i=0;i<V;i++)
  {
    if(ans[i]==nullptr)
      cout<<endl;
    else
      cout<<ans[i]<<" ";

  }

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself

  */

  return 0;
}
