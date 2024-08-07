#include<bits/stdc++.h>
/*#include<iostream>
#include<stack>
#include<string>*/
using namespace std;
/*int main()
{
    stack<string>s;
    s.push("apple");
    cout<<s.top();
}
*/
bool compare(string a,string b)
{
    return a.length()>b.length(); // increasing order
}
int main()
{

   // string s;
    //getline(cin,s);
    string arr[] ={"apple","banaana","mango","aaalo","matar"};

    sort(arr,arr+5,compare);

    for(int i=0;i<5;i++)
        cout<<arr[i]<<",";
   cout<<"\n";

     string  s1 = "deeepanshu";
      sort(s1.begin(),s1.end());
     cout<<s1;
    bool val=next_permutation(s1.begin(),s1.end());

    if(val==false)
        cout<<"\n"<<"not possible";

    else if(val==true)
        cout<<"\n "<<s1;

}

