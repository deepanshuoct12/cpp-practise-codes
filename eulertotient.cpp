#include<bits/stdc++.h>
using namespace std;
#define int long long int

int32_t main()
{
    int t;
    cin>>t;while(t--){
    int n;
    cin>>n;
    int *phi=new int[n+1];

    for(int i=2;i<=n;i++)
        phi[i]=i;

    for(int i=2;i<=n;i++)
    {
        if(phi[i]==i)
        {

            for(int j=i;j<=n;j+=i)
            {
                phi[j]=(phi[j]/i)*(i-1);
            }
        }
    }
    cout<<phi[n]<<"\n";
    }
}
