#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;
class stack
{
    int s[10];
    int top;
    public:
    stack()
    {
        top=-1;
    }
    void push(int data)
    {
        if(top==9)
        {
            cout<<"STACK OVERFLOWS"<<"\n";
        }
        else
        {
            top++;
            s[top]=data;
        }
    }
    void pop()
    {
        if(top==-1)
            cout<<"stack underflows"<<"\n";
        else
        {
           // cout<<"element popped is"<<s[top]<<"\n";
            top--;
        }
    }
    bool isempty()
    {
        return top==-1;

    }
    int topelement()
    {
        if(top==-1)
            cout<<"empty stack"<<"\n";
        return s[top];
    }
    int size()
    {
        return top+1;
    }
    void display()
    {
         if(top==-1)
          cout<<"stack empty"<<"\n";
        else
        {
            for(int i=top;i>=0;i--)
            cout<<s[i]<<" ";
        }
    }
};
stack s;

int postfixevaluate(string str)
{

    for(int i=0;i<str.size();i++)
    {
        /*if(isdigit(str[i]))
        {
            s.push(str[i]);
        }*/

       //  if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
        //    {
                if(str[i]=='+')
                {
                    int x=s.topelement();
                    s.pop();
                    int y=s.topelement();
                    s.pop();
                    s.push(x+y);
                }
                else if(str[i]=='-')
                {
                    int x=s.topelement();
                    s.pop();
                    int y=s.topelement();
                    s.pop();
                    s.push(y-x);
                }
                else if(str[i]=='*')
                {
                    int x=s.topelement();
                    s.pop();
                    int y=s.topelement();
                    s.pop();
                    s.push(x*y);
                }
                else if(str[i]=='/')
                {
                    int x=s.topelement();
                    s.pop();
                    int y=s.topelement();
                    s.pop();
                    s.push(y/x);
                }
          //  }

           else
            s.push(str[i]-48);


    }

    return s.topelement();

}
int main()
{
    int data;
    string str;
    cout<<"enter expression";
    cin>>str;
     int ans = postfixevaluate(str);
   cout<<ans<<"is answer"<<"\n";
  /*  for(int i=0;i<5;i++)
    {
        cout<<"enter data"<<"\n";
        cin>>data;
        s.push(data);
    }
    cout<<"size is"<<"\n";
    cout<<s.size();
    cout<<"\n";
    cout<<"top element is"<<"\n";
    cout<<s.topelement();
    cout<<"\n";
    s.pop();
    cout<<s.topelement();
    cout<<"\n";
    cout<<"chking is stack is empty"<<"\n";
    cout<<s.isempty()<<"\n";

    s.display();*/
    return 0;

}

