     #include<iostream>
#include<string.h>
using namespace std;

class strings{

char *str;
int len;

public:

    strings()
    {
        str=NULL;
        len=0;
    }

strings(char *s)
{
    len = strlen(s);

    str = new char[len+1];

    strcpy(str,s);

}

strings operator +(strings & obj)
{
    strings temp;
    temp.len= len + obj.len;

    temp.str = new char[len+obj.len+1];

    strcpy(temp.str,str);
    strcat(temp.str,obj.str);

    return temp;
}

void display()
{
    cout<<"\n";
    cout<<this->str;
}
/*
void operator = (strings & ob)
{
    strcpy(str,ob.str);

}
*/
};


int main()
{
    strings s1("hello");
    strings s2("world");

    strings s3;
    s3 = s1+s2;



    s3.display();
}
