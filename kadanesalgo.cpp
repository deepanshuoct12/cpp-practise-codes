#include<bits/stdc++.h>
using namespace std;

int kadanes(int arr[],int n){

int curr =arr[0]>0?arr[0]:0 ;
int maxsum =0 ;
int mx=arr[0];
for(int i=1;i<n;i++){

    curr = curr + arr[i];
    if(curr<0)
        curr=0;

        if(arr[i]<0)
        {
            mx = max(mx,arr[i]);
        }
     if(curr>maxsum)
     {
         maxsum = curr;
         //ans.push_back(arr[i]);
     }
   // maxsum = max(maxsum,curr);
}

if(maxsum==0)
return mx;

return maxsum;
}

int main(){

int n;
cin>>n;

int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}

cout<<kadanes(arr,n)<<"\n";
return 0;
}
