#include<iostream>
using namespace std;

int fact(int n)
{
    if(n==0 || n==1)
        return 1;

    return fact(n-1)*n;
}
int catalan(int n)      // catlan gives no. of bst's
{
    if(n==0)
        return 1;
int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=catalan(i-1)*catalan(n-i);

    }
    return ans;
}

int main()
{
    cout<<"catlan series is"<<"\n";

    for(int i=0;i<=5;i++)
        cout<<"no. of bst for"<<" "<<i<<" " <<"node"<<" "<<catalan(i)<<"\n ";

        cout<<"\n";

        cout<<"\n no. of binary trees from 10 nodes="<<catalan(10)*fact(10);

    return 0;
}
