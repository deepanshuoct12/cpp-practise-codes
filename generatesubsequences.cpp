#include<bits/stdc++.h>
using namespace std;

void generatesubsequence(char *input,char* output,int i,int j)
{
    if(input[i]=='\0')
    {
        output[j]='\0';
        cout<<output<<"\n";
         return ;
    }

    output[j]=input[i];
    generatesubsequence(input,output,i+1,j+1);
    output[j]='\0';
     generatesubsequence(input,output,i+1,j);

}
int main()
{
    char input[]="abc";
    char output[10];
    generatesubsequence(input,output,0,0);

    return 0;
}
