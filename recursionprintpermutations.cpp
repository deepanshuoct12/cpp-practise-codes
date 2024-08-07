#include <iostream>
using namespace std;

void printPermutations(string str, string asf){
    // write your code here
  if(str.length()==0)
  {
      cout<<asf<<"\n";
      return;
  }
  for(int i=0;i<str.length();i++)
  {
      char ch=str[i];
      string l=str.substr(0,i);
      string r=str.substr(i+1);
      string temp=l+r;
      printPermutations(temp,asf+ch);
  }
}

int main(){
    string str;
    cin>>str;
    printPermutations(str,"");

}
