 #include<bits/stdc++.h>
using namespace std;

string multiply(string a,string b)
{
    int len1 = a.length();
    int len2=b.length();

    reverse(a.begin(),a.end());
    reverse(b.begin(),b.begin());
    vector<int>mat(len1+len2,0);
    int j;
    for( int i=0;i<len1;i++)
    {
        int carry=0;
        int n1=a[i]-'0';
        for( j=0;j<len2;j++)
        {
             int n2=b[j]-'0';
             int v= n1*n2 + mat[i+j] + carry;
             mat[i+j]=v%10;
             carry=v/10;
             //carry=carry/10;

        }
        if(carry!=0)
        {
            j++;
            mat[i+j]+=carry;
            carry/=10;
        }
    }

    int i = mat.size() - 1;
    while (i>=0 && mat[i] == 0)
    i--;


    if (i == -1)
    return "0";


    string s = "";

    while (i >= 0)
        s += to_string(mat[i--]);

    return s;

}
int main()
{


    string a,b;
        cin>>a>>b;
    cout<<multiply(a,b);
}
