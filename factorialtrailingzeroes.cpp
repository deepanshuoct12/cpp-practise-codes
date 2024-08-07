#include<bits/stdc++.h>
using namespace std;
int solve(int A){
 int count = 0;
    for(int i=5;A/i>=1;i*=5)
    {
        count+=A/i;
    }

    return count;

}

int main()
{

    int n;
    cin>>n;
    cout<<solve(n);
    return 0;
}
