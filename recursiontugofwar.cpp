#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > arr(2);
int ans=INT_MAX;
void fun(vector<int>v,vector<int>s1,vector<int>s2,int sos1,int sos2,int idx)
{
    if(idx==v.size())
    {
        int d=abs(sos1-sos2);
        if(d<ans){
            ans=d;
            // for(auto x:s1)
            // cout<<x<<" ";

            arr[0]=s1;
            arr[1]=s2;
        }
        return;
    }
    if(s1.size()<(v.size()+1)/2){
    s1.push_back(v[idx]);
    fun(v,s1,s2,sos1+v[idx],sos2,idx+1);
    s1.pop_back();
    }

    if(s2.size()<(v.size()+1)/2)
    {
        s2.push_back(v[idx]);
        fun(v,s1,s2,sos1,sos2+v[idx],idx+1);
        s2.pop_back();
    }


}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];

    vector<int>s1,s2;

    fun(v,s1,s2,0,0,0);

    for(auto vec:arr)
    {
        cout<<"[";
        for(int i=0;i<vec.size();i++)
        {

            cout<<vec[i];
            if(i!=vec.size()-1)
            cout<<", ";
        }
        cout<<']'<<" ";

    }
    return 0;
}
