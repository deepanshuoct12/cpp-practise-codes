#include<iostream>
using namespace std;

class son;
class father
{

    int data;
public:
    father(int x)
    {
        data=x;
    }
    void operator -()
    {
        data=-data;
    }
    void show()
    {

        cout<<data<<"\n";
    }
    friend int operator+(father,son);
};
class son{

int data1;
public:
    son(int y){
    data1=y;
    }
    friend int operator+(father,son);
    void operator-()
    {
        data1=-data1;
    }
    void show()
    {
        cout<<data1<<"\n";
    }

};

int  operator+(father f,son s)
{
    return(f.data+s.data1);

}
int main()
{

    father f(40);
    son s(30);
    cout<<(f+s)<<"\n";
    -f;
    -s;

    f.show();
    s.show();
}
