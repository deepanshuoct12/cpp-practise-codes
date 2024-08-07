#include<iostream>
using namespace std;


void printMazePaths(int sr, int sc, int dr, int dc, string psf) {
        // write your code here
         if(sr==dr && sc==dc)
          {
              cout<<psf<<"\n";
              return;

          }

   for(int i=1;i<=dc-sc;i++)
   {
       string t=to_string(i);
      printMazePaths(sr,sc+i,dr,dc,psf+"h"+t);
   }

    for(int i=1;i<=dr-sr;i++)
   {
      string t=to_string(i);
     printMazePaths(sr+i,sc,dr,dc,psf+"v"+t);
   }

    for(int i=1;i<=dc-sc && dr-sr;i++)
   {
        string t=to_string(i);
     printMazePaths(sr+i,sc+i,dr,dc,psf+"d"+t);
   }
}

int main() {
        int n ;
        int m ;cin>>n>>m;
        printMazePaths(0, 0, n - 1, m - 1, "");
    }
