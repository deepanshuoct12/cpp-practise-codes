class Solution {
public:
    int partition(vector<int> &v,int l,int r)
    {
        int i=0,j=0;
        int piv=v[r];
        while(i<=r)
        {
            if(v[i]<=piv)
            {
                swap<int>(v[j],v[i]);
                j++;
                i++;
            }
            else 
                i++;
        }
 
        return j-1;
    }
    
    int helper(vector<int> &v,int l,int r,int k)
    {
        int n=v.size();
        int pi=partition(v,l,r);
   
        if(k==pi)
            return v[pi];
        else if(pi<k)
        {
            return helper(v,pi+1,r,k);
        }
        else{
            return helper(v,l,pi-1,k);
        }

       return -1;
    }
    int findKthLargest(vector<int>& nums, int k) {
        
        return helper(nums,0,nums.size()-1,nums.size()-k);
//         if(nums.size()==0)
//         return -1;
        
//        sort(nums.begin(),nums.end(),greater<int>());
//         return nums.at(k-1);
    }
};





















// #include<bits/stdc++.h>
// using namespace std;

// int partition(vector<int> &v,int l,int r)
// {
//     int piv=r;
//     int i=l;
//     for(int j=l;j<r;j++)
//     {
//         if(v[j]<=v[piv])
//         {
//             swap<int>(v[i],v[j]);
//             i++;
//         }
//     }
//     swap<int>(v[i],v[r]);
//     return i;
// }

// int ksmallest(vector<int> &v,int l,int r,int k){

// if(k>0 && k<=r-l+1)
// {
//     int idx=partition(v,l,r);

//     if(idx-l==k-1)
//         return v[idx];

//     else if(idx-l>k-1)
//         return ksmallest(v,l,idx-1,k);
//     else
//         return ksmallest(v,idx+1,r,k-idx+l-1);
// }

// }


// int main(){
// int n;
// cin>>n;
// vector<int>v(n);
// for(int i=0;i<n;i++)
//     {
//         cin>>v[i];
//     }
//     int k;
//     cin>>k;
//     cout<<ksmallest(v,0,n-1,k);
// }
