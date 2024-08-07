#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;cin>>t;
    while(t--){
    string s;
    cin>>s;
    int o=0,e=0;
    for(int i=0;i<s.length();i++)
    {
        if(i%2==0  && s[i]-'0')
        e++;
        else if(i%2!=0  && s[i]-'0')
        o++;
    }
    if(abs(o-e)%3==0)
    cout<<1<<"\n";
    else
    cout<<0<<"\n";

}
	//code
	return 0;
}
