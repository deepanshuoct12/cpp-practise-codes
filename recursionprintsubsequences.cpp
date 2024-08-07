#include <bits/stdc++.h>
using namespace std;

void printSS(string ques, string ans){
    // write your code here
    if(ques.length()==0)
    {
        cout<<ans<<"\n";
        return;
    }
    char ch=ques[0];
    string s=ques.substr(1);
    //printSS(s,ans);

     printSS(s,ans+ch);
    printSS(s,ans+"");

}

int main(){
    string str;
    cin >> str;
    printSS(str, "");
}
