#include<bits/stdc++.h>
using namespace std;

unsigned int reverse(unsigned int A) {

  vector<unsigned int >v(32,0);
  int pos=0;
  while(A)
  {
      if(A&1)
      {
          v[32-pos-1]=1;
      }
      A=A>>1;
      pos++;
  }
  unsigned int p = 1;
  unsigned int ans = 0;
  for(int i=0;i<32;i++)
  {
      ans+=p*v[i];
      p=p<<1;
  }

  return ans;
}

int main(){

    unsigned int n;
    cin>>n;
    cout<<reverse(n);

return 0;
}
