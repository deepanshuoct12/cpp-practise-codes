
#include<iostream>
using namespace std;
class student
{
     static int totalstudent;

public:

    student()
    {
        totalstudent++;
    }
    static int gettotalstudent()
    {
        return totalstudent;
    }
};
int student::totalstudent ;
int main()
{
    student s[10];
    cout<<student::gettotalstudent()<<"\n";
    student s1;
    student s2;
    student s3;
    student s4;
    cout<<student::gettotalstudent()<<"\n";
}
