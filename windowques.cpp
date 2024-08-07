#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a[]={1,5,9,2,4,7};
      int k,n;
      cin>>k;

    deque<int>q;
    for(int i=0;i<k;i++)
    {
        while(!q.empty() && a[q.back()]>a[i])q.pop_back();
        q.push_back(i);
    }

cout<<q.front()<<" ";

for(int k=0;k<n;k++)
{
    while(!q.empty() && a[q.back()]>a[i])q.pop_back();
    q.push_back(i);
    if(q.front()==i-k)q.pop_front();
    cout<<q.front()<<" ";
}
}
