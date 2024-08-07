#include <bits/stdc++.h>
using namespace std;

int solve(int arr[],int n,int key)
{
    int pivot=0;
    int st=0,en=n-1;
    while(st<=en)
    {
        int mid=st+(en-st)/2;
        if(mid>0 && mid<n-1 && arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
        {
            pivot=mid;
            break;
        }
        else if(arr[mid]>arr[st] && arr[mid]<arr[en])
        st=mid+1;
        else 
        en=mid-1;
    }
    
    st=0;
    en=pivot;
    while(st<=en)
    {
        int mid=st+(en-st)/2;
        if(arr[mid]==key)
        return mid;
        
        else if(key>arr[mid])
        st=mid+1;
        else 
        en=mid-1;
    }
    st=pivot+1;
    en=n-1;
    while(st<=en)
    {
        int mid=st+(en-st)/2;
        if(arr[mid]==key)
        return mid;
        
        else if(key<arr[mid])
        st=mid+1;
        else 
        en=mid-1;
    }
    return -1;
}
int main() {
	int arr[]={10, 20, 40, 50, 40, 30,10};
	int key=50;
   cout<<solve(arr,7,key);
	return 0;
}