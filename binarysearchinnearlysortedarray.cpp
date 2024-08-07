#include <bits/stdc++.h>
using namespace std;

int main() {
	int arr[]={10, 3, 40, 20, 50, 80, 70};
	int key=20;
	int st=0;
	int en=6;
	int ans=-1;
	while(st<=en)
	{
	    int mid=st+(en-st)/2;
	    
	    if(mid>st && arr[mid-1]==key)
	    {
	        ans=mid-1;
	        break;
	    }
	    if( arr[mid]==key)
	    {
	        ans=mid;
	        break;
	    }
	    if(mid<en && arr[mid+1]==key)
	    {
	        ans=mid+1;
	        break;
	    }
	    
	    if(key<arr[mid])
	    en=mid-2;
	    else 
	    st=mid+2;
	    
	}
	
	cout<<ans;
	return 0;
}