#include<bits/stdc++.h>
using namespace std;

void subsequence(char *in,char *out,int i,int j)
{

    if(in[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<"\n";
        return;
    }
    out[j]=in[i];
    subsequence(in,out,i+1,j+1);
    subsequence(in,out,i+1,j);
    return;

}
int main()
{
    char in[100];
    cin>>in;
    int i=0,j=0;
    char out[100];
    subsequence(in,out,i,j);
    return 0;
}
