#include<bits/stdc++.h>
using namespace std;
#define prime 7
#define int long long int
void init_code(){
   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
int hashval(string s)
{
    int val=0;
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        val+=(int)(s[i] * (int)pow(prime,i));
    }
    return val;
}

int recalculatehash(string str,int oldindex,int newindex,int oldhash,int patlength)
{
    int newhash = oldhash - str[oldindex];
    newhash/=prime;
    newhash += (int)(str[newindex]*(int)(pow(prime,patlength-1)));
    return newhash;

}

bool checkequal(string str1,string str2,int start1,int end1,int start2,int end2){

if(end1-start1!=end2-start2)
    return false;

    while(start1<=end1 && start2<=end2)
    {
        if(str1[start1]!=str2[start2])
            return false;

        start1++;
        start2++;
    }
   return true;
}

int rabincarp(string str,string pattern)
{

    int n= str.length();
    int m = pattern.length();
    string s = str.substr(0,m);
    int strhash = hashval(s);//hash value of first window in text 
    int pathash = hashval(pattern);


    for(int i=0;i<=n-m;i++)
    {  cout<<strhash<<" "<<pathash<<"\n";
           if(strhash==pathash && checkequal(str,pattern,i,i+m-1,0,m-1))
           {
               return i;
           }

           if(i<n-m) // to avoid runtime error
           strhash = recalculatehash(str,i,i+m,strhash,m);
    }
  return -1;
}

int32_t main()
{
    init_code();
    string str;
    string pattern;
    cin>>str>>pattern;
    cout<<rabincarp(str,pattern);

    return 0;
}
