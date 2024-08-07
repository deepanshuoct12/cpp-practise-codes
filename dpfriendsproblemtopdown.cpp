#include<iostream>
#include<algorithm>
using namespace std;
int memo[100];

int noofways(int n)
{


  if(n==0)     // if no person go then o ways to go
        return 0;

    if(n==1) // if onr person then only one way to go
        return 1;

        if(n==2)   // if 2 persons are there then 2 ways to go as either both alone can go or both in pairs
            return 2;
   if(memo[n]!=-1)
    return memo[n];


  int ans= noofways(n-1) + (n-1)*noofways(n-2);
    memo[n]=ans;

    return memo[n];

}
int main()
{
    int n;
    cin>>n;

  fill(memo,memo+n+1,-1);
    cout<<noofways(n);
    return 0;
}

