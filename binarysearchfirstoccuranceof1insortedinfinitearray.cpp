#include <bits/stdc++.h>
using namespace std;

int search(int l,int h,int arr[])
{
    int ans=-1;
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        
        if(arr[mid]==1)
        {
            ans=mid;
            h=mid-1;
        }
        else 
        l=mid+1;
    }
    return ans;
}
int solve(int arr[])
{
    int l=0;
    int h=1;
    while(arr[h]==0)
    {
        l=h;
        h=2*h;
    }
    return search(l,h,arr);
}
int main() {
	int arr[]={0,0,0,0,1,1,1,1,1,1,1,1,1,1,1};

	cout<<solve(arr);

	return 0;
}