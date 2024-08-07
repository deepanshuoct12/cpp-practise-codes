#include<bits/stdc++.h>
#define ll long long
using namespace std;


bool isodd(int n)
{
    return (n&1);
}
int getbit(int n,int i)
{
    int mask = (1<<i);
    int ans=(n&mask)>0 ? 1:0;
    return ans;
}
int setbit(int n,int i)
{
    int mask=(1<<i);

    int ans=(n|mask);
    return ans;
}
void clearbit(int &n,int i)
{
    int mask=~(1<<i);

    n=n&mask;

}

void updatebit(int &n,int i,int v)
{
    clearbit(n,i);
    int mask=(v<<i);
    n=n|mask;


}
int clearlastbits(int n,int i)
{

    int mask=(-1<<i);
    return(n&mask);
}

int clearrangeitoj(int n,int i,int j)
{
    int ones = ~(0);
    int a=ones<<(j+1);
    int b=(1<<i)-1;
    int mask=a|b;
    return(n&mask);
}
//ques.  m and n no. .........
int replacebits(int n,int m,int i,int j)
{

    int n_=clearrangeitoj(n,i,j);
    int mask = (m<<i);
    return (n_|mask);
}
int countbits(int n)
{
    int ans=0;
    while(n>0)
    {
        ans+=(n&1);
        n=n>>1;
    }

    return ans;
}
//second method fast
int countbitsfast(int n)
{

    int ans=0;
    while(n>0)
    {
        n=n&(n-1);
        ans++;
    }
    return ans;
}
//decimal o binary

int decimaltobinary(int n)
{
    int p=1;
    int ans=0;

    while(n>0)
    {
        int l=(n&1);
        ans+=p*l;
        p=p*10;
        n=n>>1;
    }

    return ans;
}

//2 unique no.

void uniquetwo()
{
    int arr[]={3,1,2,1,5,2,7,7};
    int size=8;
    int x=0;

    for(int i=0;i<size;i++)
    {
        x=x^arr[i];
    }
    int temp=x;
    int pos=0;
    while((temp&1)!=1)
    {
        pos++;
        temp=(temp>>1);

    }

    // first set bit in xor is at pos

    int mask=(1<<pos);
 //   int *a=new int[100000];
  //  int k=0;
  int a=0;
    for(int i=0;i<size;i++)
    {
        if((arr[i]&mask)>0)
        {
            a^=arr[i];
        }
       // a[k++]=arr[i];
    }

    int b=0;
    b= a^x;

    cout<<min(a,b)<<" "<<max(a,b);
}
// 3 unique no.

void uniquethree()
{
     int arr[64]={0};
     int n;
     int no;
     cin>>n;
     for(int i=0;i<n;i++)
     {
           int j=0;
         cin>>no;
         while(no>0)
         {
             int l=(no&1);
             arr[j]+=l;
             j++;
             no=(no>>1);
         }
     }

     int p=1;
     int ans=0;
     for(int i=0;i<64;i++)
     {

         arr[i]%=3;
         ans+=arr[i]*p;
         p=p<<1;// p*2;

     }

     cout<<ans;
}
// power of a no.

int exp(int a,int n)
{

    int ans=1;

    while(n>0)
    {
        int l=(n&1);
        if(l)
        {
            ans=ans*a;
        }
        a=a*a;
        n=n>>1; // n=n/2;

    }
    /*

    while(n)
    {

    if(n&1)
    {ans=ans*a;
    ans%=mod;
    }

    a*=a;
    a%=mod;
    n=n>>1;// n=n/2;
    */
}
// subsets

void filter(int n,char a[])
{
    int i=0;

    while(n>0)
    {

        int l=(n&1);
        if(l)
        {
            cout<<a[i];

        }
        i++;
        n=n>>1;
    }
}

void printsubset(char a[])
{
    int len=strlen(a);

    for(int i=0;i<(1<<len);i++)
    {
        filter(i,a);
        cout<<"\n";
    }
}
// avenger problem


void avenger()
{
    ll t;
    ll n;
    cin>>t;
    ll prime[]={2,3,5,7,11,13,17,19};
    while(t>0)
    {
         cin>>n;
         ll subsets = (1<<8)-1;  // 2^n -1 subsets ignorin null subset
         ll ans =0;
        for(ll i=1;i<=subsets;i++)
        {
           ll deno = 1ll;
           ll setbits = __builtin_popcount(i);

           for(ll j=0 ;j<=7;j++)  // j denotes the positipon
           {
               if(i&(1<<j))
               {
                   deno=deno*prime[j];
               }

           }
               if(setbits&1)
                   ans=ans+(n/deno);
               else
                ans=ans-(n/deno);

           }



        cout<<ans<<"\n";

        t--;
    }

}

int main()
{
    int n=15;
    int i=1 ,j=3;
    int m=2;

  /*  cout<<"f1"<<isodd(n)<<"\n";
    cout<<"f2"<<" "<<getbit(n,i)<<"\n";
   cout<<"f3"<<setbit(n,i)<<"\n";*/
  // clearbit(n,i);
    //cout<<n;
  // updatebit(n,i,1);
   //cout<<"\n"<<n;
   //cout<<clearrangeitoj(n,i,j)<<"\n";
   //cout<<replacebits(n,m,i,j);

   //cout<<decimaltobinary(n);

   uniquetwo();
 // uniquethree();

// cout<<exp(2,6)<<"\n";
//char a[]="abc";
 // printsubset(a);
//avenger();


}
