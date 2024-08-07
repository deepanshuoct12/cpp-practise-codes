#include<bits/stdc++.h>

using namespace std;

int main()
{
    int tcases;
    char mat[55][55];
    cin>>tcases;
    for(int i=0;i<tcases;i++)
    {

        int m,n,k;
        cin>>m>>n>>k;
        vector<int>bulbslit(m,0);
        for(int r=0;r<m;r++)
        {
            for(int c=0;c<n;c++)
            {
                cin>>mat[r][c];

                if(mat[r][c]=='*')
                    ++bulbslit[r];
            }
        }

        //bulblit contain all the bulbs corresponding to row

        sort(bulbslit.begin(),bulbslit.end(),less<int>()); // descending order sort
        int idx=0;
        while(k>0&& idx<m && n-bulbslit[idx]>bulbslit[idx])
        {
            bulbslit[idx]=n-bulbslit[idx];
            --k;
            idx++;
        }
        if(k!=0 && k%2!=0 )
        {
          // auto it= min_element(bulbslit.begin(),bulbslit.end());
             vector<int>::iterator it =min_element(bulbslit.begin(),bulbslit.end());
           (*it)=n - (*it);
        }
             cout<<accumulate(bulbslit.begin(),bulbslit.end(),0)<<"\n";
    }
}
