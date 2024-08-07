#include<iostream>
using namespace std;

class india
{

    int population;
    int states;

public:
    india(int p,int s)
    {
        population=p;
        states=s;
    }
    void put1()
    {

        cout<<"\n population of india is"<<"\n";
        cout<<population;
        cout<<"\n no. of states"<<"\n";
        cout<<states<<"\n";
    }
};

class delhi :public india
{
    int pop;
    int reg;

 public:
    delhi(int p,int s):india(p,s)
    {

        pop=p/6;
        reg=25;
    }
    void put2()
    {
        cout<<"\n population of delhi"<<"\n";
        cout<<pop;
        cout<<"\nno. of regions are"<<"\n";
        cout<<reg<<"\n";
    }
};

class dilshadgarden:public delhi
{
    int pop;
    int place;

public:
    dilshadgarden(int p1,int s1):delhi(p1,s1)
    {
        pop=p1/8;
        place=23;
    }
    void put3()
    {
        cout<<"\n population of dilshad garden is"<<"\n";
        cout<<pop;
        cout<<"\n no. of places"<<"\n";
        cout<<place<<"\n";
    }
};

int main()
{
    dilshadgarden d(50000,28);
    d.put1();
    d.put2();
    d.put3();
}
