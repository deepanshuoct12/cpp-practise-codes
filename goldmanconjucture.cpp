#include<bits/stdc++.h>
using namespace std;


void constructSeive(int A, vector<bool> &sieve){
    for(int i = 2; i <= ceil(sqrt(A)); i++){
        if(sieve[i] == true){
            for(int j = i*i; j < sieve.size(); j = j + i)
                sieve[j] = false;
        }
    }
}

vector<int> primesum(int A) {
    vector<int> res (2, 0);

    vector<bool> sieve(A, true);
    constructSeive(A, sieve);

    //After constructing sieve, search for the pair
    for (int i=2; i<A; i++)
    {
        if (sieve[i] && sieve[A-i])
        {
            res[0] = i;
            res[1] = A-i;
            break;
        }
    }

    return res;
}

int main()
{
    int n;
    cin>>n;
    vector<int> ans = primesum(n);
    cout<<ans[0]<<":"<<ans[1];

}

