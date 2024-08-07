#include <iostream>
#include<string>
using namespace std;

void printEncoding(string str, string asf){
    // write your code here
    if(str.length()==0)
    {
        cout<<asf<<"\n";
        return;
    }
    else if(str.length()==1)
    {
        char ch=str[0];
        if(ch=='0')
        return;
        char code=char('a'+(ch-'0')-1);
        string roq=str.substr(1);
        printEncoding(roq,asf+code);
    }
    else {
        char ch=str[0];
        if(ch=='0')
        return;
        char code=char('a'+(ch-'0')-1);
        string roq=str.substr(1);
        printEncoding(roq,asf+code);

        string ch12=str.substr(0,2);
        string roq12=str.substr(2);
        int val=stoi(ch12);
        if(val>26)
        return;
        char code12=char('a'+val-1);
        printEncoding(roq12,asf+code12);

    }

}

int main(){
    string str;
    cin>>str;
    printEncoding(str,"");

}
