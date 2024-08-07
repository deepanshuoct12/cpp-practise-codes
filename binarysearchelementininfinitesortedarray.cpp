#include <bits/stdc++.h>
using namespace std;

int search(int l,int h,int arr[],int key)
{
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        
        if(arr[mid]==key)
        return mid;
        
        else if(key>arr[mid])
        l=mid+1;
        else 
        h=mid-1;
    }
    return -1;
}
int solve(int arr[],int key)
{
    int l=0;
    int h=1;
    while(arr[h]<key)
    {
        l=h;
        h=2*h;
    }
    return search(l,h,arr,key);
}
int main() {
	int arr[]={ 3,10,20,40, 50, 80, 90};
	int key=50;
	cout<<solve(arr,key);

	return 0;
}