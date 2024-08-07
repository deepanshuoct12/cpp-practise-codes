#include<iostream>
using namespace std;

int maxprofit(int arr[],int totallen)
{
    if(totallen==0)
        return 0;
    int best=0;
    for(int len=1;len<=totallen;len++){
        int netprofit=arr[len]+maxprofit(arr,totallen,len);
        best=max(best,netprofit);

    }
    return best;

}

int main()
{
    int priceofeachlen[1000];
    int totallen;
    cin>>totallen;

    for(int eachpiece=1;eachpiece<=totallen;totallen++)
    {
        cin>>priceofeachlen[i];
    }
    cout<<"\n";
    int ans= maxprofit(priceofeachlen , totallen);
}
