#include<iostream>
#include<vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePaths(int sr, int sc, int dr, int dc) {

  if(sr==dr && sc==dc)
  return {""};

   vector<string>subans1;
   vector<string>ans;
   for(int i=1;i<=dc-sc;i++)
   {
       subans1=getMazePaths(sr,sc+i,dr,dc);
       for(auto x:subans1)
      {   string t=to_string(i);
          ans.push_back("h"+t+x);

      }
   }

   vector<string>subans2;
    for(int i=1;i<=dr-sr;i++)
   {
       subans2=getMazePaths(sr+i,sc,dr,dc);
       for(auto x:subans2)
       {
           string t=to_string(i);
          ans.push_back("v"+t+x);

      }
   }

    vector<string>subans3;
    for(int i=1;i<=dc-sc && dr-sr;i++)
   {
       subans3=getMazePaths(sr+i,sc+i,dr,dc);
       for(auto x:subans3)
       {   string t=to_string(i);
          ans.push_back("d"+t+x);

      }
   }


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
