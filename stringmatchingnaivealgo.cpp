#include<bits/stdc++.h>
using namespace std;

void naive(string str,string pattern)
{   int n = str.length();
    int m=pattern.length();

    for(int i=0;i<n-m+1;i++)
    {   int k=0;
        for(int j=i;j<i+m;j++){
            if(str[j]==pattern[k])
              k++;
            else
                break;
        }
            if(k==m)
                cout<<i<<" ";
    }
}

int main()
{
    string str;
    string pattern;

    cin>>str>>pattern;
    naive(str,pattern);
    return 0;
}
