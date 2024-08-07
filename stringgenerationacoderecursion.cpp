#include<bits/stdc++.h>
using namespace std;
void generatestrings(char *in,char *op,int i,int j)
{
    if(in[i]=='\0')
    {
        op[j]='\0';
        cout<<op<<"\n";
        return ;
    }
    int digit=in[i]-'0';
    if(digit==0)
        return;

    char ch=digit+'A'-1;
    op[j]=ch;
    generatestrings(in,op,i+1,j+1);

    if(in[i+1]!='\0')
    {  // digit=in[i];
        int seconddigit=in[i+1]-'0';
        int finaldigit;

        finaldigit=digit*10+seconddigit;

        if(finaldigit<=26)
        {
            char ch=finaldigit+'A'-1;
            op[j]=ch;
              generatestrings(in,op,i+2,j+1);
        }
    }
    return;
}
int main()
{

    int n;
    cin>>n;
    char in[n];
    for(int i=0;i<n;i++)
        cin>>in[i];
    char op[100];
    generatestrings(in,op,0,0);
    return 0;
}

/*
class compare{
  public :
    bool operator()(string &s1, string &s2) {
        return s1.compare(s2);
    }
};

vector<string>arr;
void solve(string &s, int i, string &temp) {

    if(i==s.length()) {
        arr.push_back(temp);
        return;
    }

    if(i+1<s.length()) {
        if(s[i+1]=='0') {
            int n = (s[i]-'0')*10;
            if(n==10) {
                temp.push_back('j');
                solve(s, i+2, temp);
                temp.pop_back();
            }
            else if(n==20) {
                temp.push_back('t');
                solve(s, i+2, temp);
                temp.pop_back();
            }
            else if(n==30) {
                temp.push_back('D');
                solve(s, i+2, temp);
                temp.pop_back();
            }
            else if(n==40) {
                temp.push_back('N');
                solve(s, i+2, temp);
                temp.pop_back();
            }
        }
        else {
            int n = (s[i]-'0')*10 + (s[i+1]-'0');
            if(n>=1 && n<=26) {
                char c = n-1+'a';
                temp.push_back(c);
                solve(s, i+2, temp);
                temp.pop_back();
            }
            else if(n>=27 && n<=52) {
                char c = n-27+'A';
                temp.push_back(c);
                solve(s, i+2, temp);
                temp.pop_back();
            }
        }
    }

    if(s[i]!='0') {
        int n = (s[i]-'0')-1;
        char c = n+'a';
        temp.push_back(c);
        solve(s, i+1, temp);
        temp.pop_back();
    }


}



int main() {
    string s;
    cin>>s;

    arr.clear();
    string temp = "";

    solve(s, 0, temp);

    sort(arr.begin(), arr.end(), compare());

    for(int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    }

}
*/
