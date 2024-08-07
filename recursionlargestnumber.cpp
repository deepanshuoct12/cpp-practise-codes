#include<bits/stdc++.h>
using namespace std;
void fun(string &str,int idx,int swaps,int k)
{
    if(idx==str.length())
    {
        cout<<str<<"\n";
        return;
    }
    char ch=str[idx];
    int index;
    int mx=INT_MIN;
    for(int i=idx;i<str.length();i++)
    {
        if(str[i]-'0'>mx)
           {
               mx=str[i]-'0';
               index=i;
           }
    }
    if(index==idx)
    fun(str,idx+1,swaps,k);
    else{
       if(swaps<k){
       swap(str[idx],str[index]);
           swaps=swaps+1;
       }
       fun(str,idx+1,swaps,k);
    }
}
int main()
{
    string str;
    cin>>str;
    int k;
    cin>>k;
    fun(str,0,0,k);
    return 0;
}
