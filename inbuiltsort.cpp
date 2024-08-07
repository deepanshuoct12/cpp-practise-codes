#include<bits/stdc++.h>
using namespace std;
bool compare(int a,int b)
{

    cout<<"compare"<<a<<" "<<"and"<<" " <<b<<"\n";
    return a>b;
}

int main()
{

    int arr[]={5,4,3,2,1,7,8};


    int n=7;
    sort(arr,arr+n,compare);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
