#define mod 10000003
int Solution::seats(string A) {

    long long  int ans=0;//t=-1;
    vector<long long int>v;
    for(int i=0;i<A.length();i++)
    {
        if(A[i]=='x')
        {
            v.push_back(i);

        }
    }
    long long int n=v.size();
    long long int m=n/2;


    for(int i=0;i<v.size();i++)
    {

        ans+=(abs(v[m]-v[i])-(abs(m-i)))%mod;
    }
    return int(ans%mod);
}

