#include<iostream>
#include<string>
using namespace std;

int main()
{

    string s="deepanshu";
    cout<<s<<"\n";
       s+= "is a bad guy";
       cout<<s<<"\n";
       cout<<s.size()<<"\n";
       s.erase(1,0);
       cout<<s<<"\n";
      // s.clear();
       cout<<s.size()<<"\n";
       cout<<s.empty()<<"\n";
       cout<<s.find("is")<<"\n";
}
