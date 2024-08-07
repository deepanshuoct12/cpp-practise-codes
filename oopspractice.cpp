#include<iostream>

using namespace std;

class bc
{

public:
    int b;
    void show()
    {
        cout<<"b="<<b<<"\n";

    }
};
class dc:public bc
{
public:
    int d;
    void show()
    {
       // cout<<"b="<<b<<"d="<<d<<"\n";
       cout<<"d="<<d<<"\n";
    }
};
int main()
{
    bc*bptr;
    bc base;
    bptr=&base;
    bptr->b=100;
    bptr->show();
    dc derived;
    bptr=&derived;
   // bptr->d=300;
    bptr->show();
    dc*dptr;
    dptr=&derived;
    dptr->d=300;
    dptr->show();
    cout<<"using ((dc*))ptr)\n";
    ((dc*)bptr)->d=400;
    cout<<"\n";
    ((dc*)bptr)->show();

}

/*class base
{

public:
    void show()
    {

        cout<<"class::base"<<"\n";
    }

};
class derived:public base
{
public:
    void show()
    {

        cout<<"class::derived"<<"\n";
    }

};
int main()
{
    base*ptr;
    base b;
  //  ptr=&b;
    //ptr->show();
    derived d;
    ptr=&d;
    ptr->show();


}
*/
