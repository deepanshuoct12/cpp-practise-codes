#include <iostream>
#include <vector>
using namespace std;

vector<string> gss(string s){
    // write your code here

    if(s.length()==0)
    {
        vector<string>t;
        t.push_back("");
        return t;
       // return {""};
    }
    char ch=s[0];
    string str=s.substr(1);
    vector<string>subans=gss(str);
    vector<string>ans;
    for(auto x:subans)
    {
        ans.push_back(""+x);
        ans.push_back(ch+x);
    }

    return ans;
}

///////////////////////bit methid////////////
    vector<string> AllPossibleStrings(string s){
          
          int n=s.length();
          vector<string>ans;
          for(int i=0;i<(1<<n);i++)
          {
              string temp="";
              for(int j=0;j<n;j++)
              {
                  if(i&(1<<j))
                  {
                      temp+=s[j];
                  }
              }
              if(temp.length()>0)
              ans.push_back(temp);
          }
         // return ans;
          //  // Code here
          // vector<string>ans=helper(s);
            sort(ans.begin(),ans.end());
            return ans;
          
        }
int main(){
    string s;
    cin >> s;
    vector<string> ans = gss(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}
