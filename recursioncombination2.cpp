#include<bits/stdc++.h>
using namespace std;
void fun(vector<char>&boxes,int ti,int ci,int lastidx)
{

    if(ci>ti)
    {
        for(auto x:boxes)
        cout<<x;
        cout<<"\n";

        return;
    }
    // int lastidx=0;
    // for(int i=0;i<boxes.size();i++)
    // {
    //     if(boxes[i]!='-')
    //     lastidx=i;
    // }
    for(int i=lastidx+1;i<boxes.size();i++)
    {
        if(boxes[i]=='-'){
        boxes[i]='i';
        fun(boxes,ti,ci+1,i);
        boxes[i]='-';
        }
    }
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<char>boxes(n,'-');
    fun(boxes,k,1,-1);
    return 0;
}
