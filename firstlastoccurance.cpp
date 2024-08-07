#include<bits/stdc++.h>
using namespace std;

int lasttocc(int *arr,int n,int key)
{
    if(n==0)
    return -1;

    int i=lasttocc(arr+1,n-1,key);

    if(i==-1)
    {
        if(arr[0]==key)
            return 0;
        return -1;
    }
    return i+1;
}
int firstocc(int *arr,int n,int key)
{
    if(n==0)
        return -1;

    if(arr[0]==key)
        return 0;
    int i=firstocc(arr+1,n-1,key);

    if(i==-1)
        return -1;
    return i+1;
}

void allocc(int* arr,int i,int n,int key)
{
    if(i==n)
        return ;

    if(arr[i]==key)
        cout<<i<<" ";

    allocc(arr,i+1,n,key);

}
int storeocc(int *arr,int i,int *out,int n,int key,int j)
{
    if(i==n)
        return j;
  //   cout<<i<<":"<<j<<"\n";
    if(arr[i]==key)
    {
        out[j]=i;
     //   cout<<":"<<j<<"\n";
       return storeocc(arr,i+1,out,n,key,j+1);
    }

     return storeocc(arr,i+1,out,n,key,j);
}
int main()
{
    int arr[]={1,2,9,7,8,4,7,0,3};
    cout<<firstocc(arr,9,7)<<":"<<lasttocc(arr,9,7)<<"\n";
    allocc(arr,0,9,7);
    cout<<"\n";
    int out[23];
    int x=storeocc(arr,0,out,9,7,0);
    cout<<x<<"\n";
}

