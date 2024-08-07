#include<iostream>
using namespace std;

class grandparent{
string gnm;
int balance;

public:
    grandparent()
    {
        cout<<"\n grandparent constructor's called";
    }

    grandparent(string name,int acc)
    {

        gnm=name;
        balance=acc;
    }

    void gshow()
    {
        cout<<"\n grandparent details are"<<"\n";
        cout<<gnm<<":"<<balance<<"\n";
         cout<<"\n";
    }

    ~grandparent()
    {
        cout<<"\n grandparent's destructor called";
    }
};



class parent1:virtual public grandparent
{
 string nm;
 int balance;

 public:
     parent1()
     {
         cout<<"\n parent1 constructor called";

     }
    parent1(string name,int acc):nm(name),balance(acc)
    {

    }
    void pshow1()
    {
        cout<<"\n parent1 details are"<<"\n";
        cout<<nm<<":"<<balance;
         cout<<"\n";

    }

    ~parent1()
    {
        cout<<"\n parent1 destructor called";
    }

};

class parent2:virtual public grandparent
{
 string nm;
 int balance;

 public:
     parent2()
     {
         cout<<"\n parent2 constructor called";

     }
    parent2(string name,int acc):nm(name),balance(acc)
    {

    }
    void pshow2()
    {
        cout<<"\n parent2 details are"<<"\n";
        cout<<nm<<":"<<balance;
         cout<<"\n";

    }

    ~parent2()
    {
        cout<<"\n parent2 destructor called";
    }

};
class son:public parent1,public parent2
{
    string snm;
    int balance;
public:
    son()
    {
        cout<<"\n son's constructor called";

    }

    son(string name,int acc,string pname1,int acc1,string pname2,int acc2):grandparent(name,acc),parent1(pname1,acc1),parent2(pname2,acc2)
    {
        snm="son";
        balance=10;
    }

    void sshow()
    {
        cout<<"\n son's details are"<<"\n";
        cout<<snm<<":"<<balance;
        cout<<"\n";
    }
    ~son()
    {
        cout<<"\n son's destructor called";
    }
};

int main()
{
    //son s;
    son s("grandfather",10000,"father",1000,"mother",100);
    s.gshow();
    s.pshow1();
    s.pshow2();
    s.sshow();
}
