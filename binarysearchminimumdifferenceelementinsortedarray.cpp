#include <bits/stdc++.h>
using namespace std;

int main() {
	int arr[]={10, 3, 40, 20, 50, 80, 70};
	int key=20;
	int st=0;
	int en=6;
	while(st<=en)
	{
	    int mid=st+(en-st)/2;
	   
	  
	    if(key<arr[mid])
	    en=mid-1;
	    else 
	    st=mid+1;
	    
	}
	if(arr[st]-key<key-arr[en])
	cout<<arr[st];
	else
	cout<<arr[en];

	return 0;
}
