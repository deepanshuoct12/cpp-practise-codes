
#include<iostream>
#include<string>
using namespace std;

class employee;
class buisnessman
{
    friend class employee;

    string name;
    int age;
    int salary;

    buisnessman(string s,int age,int salary)
    {
        name=s;
        this->age=age;
        this->salary=salary;
    }
public:
    void put1()
    {
        cout<<"buisness man details are\n";
         cout<<name<<":"<<age<<":"<<salary<<"\n";

    }

};

class employee
{
    string name;
    int sal;
    int id;

public:


    employee(string s,int salary,int age,string str,int i)
    {
        buisnessman b(s,salary,age);
        name=str;
        sal=salary/5;
        id=i;
        b.put1();
    }

    void put2()
    {
        cout<<"\n employee details are\n";
        cout<<name<<":"<<sal<<":"<<id;
        cout<<"\n";
    }
};
int main()
{
    employee e("divyanshu",60000,25,"dev",065);

    e.put2();
}
