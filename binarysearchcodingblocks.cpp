#include<bits/stdc++.h>
using namespace std;


float squareroot(int n,int p)   // sqrt of n upto p places
{

  //  int s=0,e=n;
    //int ans,mid;
      int f=0,l=n,mid=0;
      int x;
      float ans;
     while(f<l)
     {
         //cout<<f<<":"<<l;

         mid=(f+l)/2;
          x=mid*mid;
          // cout<<":"<<mid<<"\n";
          //cout<<x<<"\n";

          if(x==n)
          {
              cout<<"answer"<<":"<<mid<<"\n";
              break;
          }

        else if(x<n)
         {

             f=mid+1;
             ans=mid;
         }
       else
         {

             l=mid-1;
         }


      /*   if(f==l)
         {  int p = f*f;
              if(p>n)
                cout<<"answer"<<":"<<(f-1);

              cout<<"answer"<<":"<<f;
            break;
         }*/
     }

     float inc=0.1;

     for(int i=0;i<p;i++)
     {
         while(ans*ans<=n)
         {
             ans+=inc;
         }
         ans=ans-inc;
         inc=inc/10;
     }

    return ans;
}

// first occurance,last occurance
int focc(int *a,int n,int key)
{
    int s=0;
    int e=n-1;
    int ans=-1;

    while(s<=e)
    {

        int mid=(s+e)/2;

        if(a[mid]==key)
        {

            ans=mid;
          //  e=mid-1;   // we do e=mid-1 as we want to search in left part for first occurance

            s=mid+1;  // to find last occurance of key
        }

        else if(a[mid]>key)
        {

            e=mid-1;
        }

        else{
            s=mid+1;
        }
    }
    return ans;
}

// pivot

int pivot(int *a,int n)
{

    int s=0;
    int e=n-1;
    int ans;
    while(s<=e)
    {

        int mid=(s+e)/2;


        if(mid>s && a[mid]<a[mid-1])  //we chk this  as if mid=0 then we cant compute mid-1
        {
            ans=mid-1;
            break;
        }
        else if(mid<e && a[mid]>a[mid+1])  // we chk this as if mid =e then  mid+1 cant be computed
        {
            ans=mid;
            break;
        }


        else if(a[e]<=a[mid])
        {                            // right part  is unsorted
            s=mid+1;
        }

        else if(a[mid]<=a[s])
        {
                                     // left part   is unsorted
            e=mid-1;
        }

        if(s>e)
        {

            return -1;
        }
    }

    return ans;
}
int main()
{
  //  int n,p;
 //   cin>>n;


 /*int arr[]={1,2,2,2,2,4,4};

 cout<<focc(arr,7,2);
  */
  int a[]={6,7,1,2,3,4,5};

  cout<<a[pivot(a,7)];
  /*cout<<squareroot(10,3)<<"\n";
  cout<<squareroot(47,5)<<"\n";
  cout<<squareroot(49,1);

*/

}
