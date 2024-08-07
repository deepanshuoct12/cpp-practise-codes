#include<bits/stdc++.h>
using namespace std;
int Partition(int *arr,int s,int e)
{
   int pivot=arr[e];
   int i=0;
   int j=0;
   while(i<=e)
   {
       if(arr[i]<=pivot)
       {
           swap<int>(arr[i],arr[j]);
           i++;
           j++;
       }
       else
       i++;
   }
   return j-1;
}
void quicksort(int *arr,int s,int e)
{

    if(s<e)
    {
        int p=Partition(arr,s,e);
        quicksort(arr,s,p-1);
        quicksort(arr,p+1,e);
    }
}

void print(int *arr,int n)
{

    for(int i=0;i<n;i++)
    {

        cout<<arr[i]<<" ";
    }
}
int main()
{

    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    quicksort(arr,0,n-1);
     print(arr,n);
}
