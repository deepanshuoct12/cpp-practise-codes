#include<bits/stdc++.h>
using namespace std;

void printsum(vector<int>&v,int i,int s,vector<int>&subset,int sum){
    if(i==v.size())
    {
        if(s==sum)
        {
            for(auto x:subset)
            cout<<x<<","<<" ";
            cout<<"."<<"\n";

        }
          return;
    }

    subset.push_back(v[i]);
    printsum(v,i+1,s+v[i],subset,sum);
    subset.pop_back();
    printsum(v,i+1,s,subset,sum);
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    int sum;
    cin>>sum;
    vector<int>subset;
    printsum(v,0,0,subset,sum);

    return 0;
}
