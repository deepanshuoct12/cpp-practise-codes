#include<bits/stdc++.h>

using namespace std;
//gcd
int gcd(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }

    return a;
}
// gcd euclid
int gcd(int a,int b)
{

    if(b==0)
    {

        return a;
    }

    return gcd(a/2,b%(a/2 ));
}

// extended euclid algo.
int x,y,Gcd;
void extendedeuclid(int a,int b)
{

    if(b==0)
    {
        x=1;
        y=0;
        Gcd=a;
        return;
    }

    //recursive
    extendedeuclid(b,a%b);
    int cx=y;
    int cy=x-(a/b)*y;

    x=cx;
    y=cy;
}
// inverse modulo
int inversemodulo(int a,int m)
{

    extendedeuclid(a,m);
    return(x+m)%m;  // we add m so that answer is positive .as extendedeuclid can return answer in negative also
}

// linear diophantine eq.



void lde(int a,int b,int c)
{
    int g= gcd(a,b);

    if(c%g!=0)
    {  cout<<"\n not possible"<<"\n";
        return;
    }
    int k=c/g;
    extendedeuclid(k*a,k*b);

     int x1,y1;

     for(int t=0;t<10;t++)  // let us find 10 integer values
     {
         x1=(x+(b/g)*t);
         y1=(y-(a/g)*t);
         cout<<x1<<" "<<y1<<"\n";
     }

}
int main()
{

    lde(18,30,36);//18x+30y=36
   // cout<<inversemodulo(8,7);
/*
extendedeuclid(18,30);
cout<<x<<" "<<y;
*/

   /* int x=gcd(10,14);

    cout<<"lcm"<<" "<<(10*14)*x;*/
}
