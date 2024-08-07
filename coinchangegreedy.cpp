#include<bits/stdc++.h>
using namespace std;

void init_code(){
   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
int make_change(int *coins,int n,int money){
int ans = 0;
while(money>0){
    int idx = upper_bound(coins,coins+n,money) - 1 - coins;
    cout<<coins[idx]<<":";
    money = money - coins[idx];
    ans++;
}
return ans;
}

void printcoinchange(int coins[],int n,int money)
{  vector<int>ans;
   for(int i=n-1;i>=0;i--)
   {
      while(coins[i]<=money)
      {
        money-=coins[i];
         ans.push_back(coins[i]);
      }
   }
   cout<<"\n";
   for(auto x:ans)
    cout<<x<<" ";

}
int main(){
    init_code();
int coins[]={1,2,5,10,20,50,100,200,500,2000};

int  t = sizeof(coins)/sizeof(int);

cout<<"\n"<<make_change(coins,t,99);
 printcoinchange(coins,t,99);
return 0;
}
