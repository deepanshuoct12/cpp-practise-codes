#include <bits/stdc++.h>
using namespace std;

void computelps(string pat,int m,vector<int>&lps)
{
    int i=1;
    int len=0;
    lps[0]=0;
    while(i<m)
    {
        if(pat[i]==pat[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0)
            len=lps[len-1];
            else{
                lps[i]=0;
                i++;
            }
            
        }
    }
}
void kmp(string str,string pat)
{
    int n=str.length();
    int m=pat.length();
    vector<int>lps(m);
    computelps(pat,m,lps);
    
    int i=0;
    int j=0;
    while(i<n)
    {
        if(str[i]==pat[j])
        {
            i++;
            j++;
        }
        if(j==m)
        {
            cout<<"pattern found at"<<" "<<i-j<<"\n";
            j=lps[j-1];
        }
        else {
            if(i<n && str[i]!=pat[j])
             {
                 if(j!=0)
                  j=lps[j-1];
                  else 
                  i++;
             }
            
        }
    }
}
int main() {
  string str,pat;
  cin>>str>>pat;
  
  kmp(str,pat);
    return 0;
}















// #include<bits/stdc++.h>
// using namespace std;
// #define MAX_N 100005
// int reset[MAX_N];

// void kmppreprocess(string pat){
// int i=0,j=-1;
// reset[i]=j;

// while(i<pat.length()){
// while(j<pat.length() && pat[i]!=pat[j])
// {
//     j=reset[j];
// }
// i++;
// j++;
// reset[i]=j;
// }

// }

// void kmpsearch(string str,string pat){

//   kmppreprocess(pat);
//   int i=0,j=0;
//   while(i<str.size()){
//     while(j>=0 && str[i]!=pat[j])
//         j=reset[j];

//      i++;
//      j++;
//     if(j==pat.length())
//         {
//         cout<<"pattern found at"<<" "<<i-j<<"\n";
//           j=reset[j];
//         }

//  }

// }


// int main()
// {
// string str,pat;

// for(int i=0;i<MAX_N;i++)
//     reset[i]=-1;

// cin>>str>>pat;
// kmpsearch(str,pat);
// return 0;
// }
