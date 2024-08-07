#include<bits/stdc++.h>
using namespace std;

void bubblesort(int *arr,int n,int j)
{
    if(n==1)
        return;

    if(j==n-1)
    {
        bubblesort(arr,n,0);
    }
    if(arr[j]>arr[j+1])
    {
        swap(arr[j],arr[j+1]);
    }
    bubblesort(arr,n,j+1);
    return;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    bubblesort(arr,n,0);
    for(int i=0;i<n;i++)
        cout<<arr[i];
}
