#include<iostream>
using namespace std;
class base{
int data;

public:
    base()
    {
        data=20;
    }

   virtual void show()=0;
   virtual void show2()=0;
   virtual void show3()=0;

};

class derived:public base{

int data1;

public:
    derived()
    {
        data1=10;
    }

    void show()
    {
        cout<<"derived"<<":"<<data1<<"\n";
    }
    void show2()
    {
        cout<<"derived"<<":"<<data1+10<<"\n";
    }
    void show3()
    {
        cout<<"derived"<<":"<<data1+20<<"\n";
    }

};

int main()
{
//    base b;
    derived d;
    base *bptr;

    bptr=&d;
    //bptr->show();

    bptr=&d;
    bptr->show();
    bptr->show2();
    bptr->show3();
//derived d1;
    //explicit
   // ((derived*)bptr)->show();

     //d.show();
  //  bptr->show();


   /* derived*dptr=&d;
    bptr=dptr;
    bptr->show();*/



}
