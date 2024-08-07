#include<iostream>
using namespace std;

int main()
{
    int const i=10;
    //int j=20;

     int const*const k=&i;
    cout<<i++<<"\n";
//    k=&j;

    cout<<++(*k);
    return 0;
}
