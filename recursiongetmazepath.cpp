#include<iostream>
#include<vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePaths(int sr, int sc, int dr, int dc) {

  if(sc>dc || sr>dr)
  return {};
  if(sr==dr && sc==dc)
  return {""};

   vector<string>subans=getMazePaths(sr,sc+1,dr,dc);
   vector<string>ans;

   for(auto x:subans)
   ans.push_back('h'+x);

   subans=getMazePaths(sr+1,sc,dr,dc);

   for(auto x:subans)
   ans.push_back('v'+x);

   return ans;
}

void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }

    cout << "]"<<endl;
}


int main() {
    int n,m; cin >> n >> m;
    vector<string> ans = getMazePaths(0,0,n-1,m-1);
    display(ans);

    return 0;
}
