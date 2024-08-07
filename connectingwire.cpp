#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main(){


int n;
cin>>n;

vector<int>b(n);
vector<int>w(n);

for(int i=0;i<n;i++){
    cin>>b[i];
}
for(int i=0;i<n;i++){

    cin>>w[i];
}
sort(b.begin(),b.end());

sort(w.begin(),w.end());
int res=0;

for(int i=0;i<n;i++){
 res+=fabs(b[i]-w[i]);
}
cout<<res<<"\n";

}
