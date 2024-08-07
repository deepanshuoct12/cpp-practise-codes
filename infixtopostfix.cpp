#include<iostream>
#include<stack>
#include<ctype.h>
#include<string>
using namespace std;

char* fun(string s)
{   stack<char>st;
     char*s2;
     int k=0;
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='(')
            st.push(s[i]);

        else if((s[i]>='A'&& s[i]<='Z')||(s[i]>='a' && s[i]<='z') )     // chl aplhabet
        {
            s2[k++]=s[i];
            //s2.push_back(s[i]);
        }

        else if(s[i]=='+'||s[i]=='*'||s[i]=='/'||s[i]=='-')   // chk operator
        {

            if(st.top()=='(')
            {
                st.push(s[i]);
            }

            else if(s[i]=='+')
            {

                if(st.top()=='-')
                {
                    s2[k++]=s[i];
                   // s2.push_back(s[i]);
                }

                else if(st.top()=='/' || st.top()=='*')
                {
                    char temp=st.top();
                    s2[k++]=temp;
                   // s2.push_back(st.top());
                    st.pop();
                    st.push(s[i]);

                }

            }

            else if(s[i]=='-')
            {

                if(st.top()=='+')
                {
                    s2[k++]=s[i];
                   // s2.push_back(s[i]);
                }

                else if(st.top()=='/' || st.top()=='*')
                {
                    char x=st.top();
                    s2[k++]=x;
                    //s2.push_back(st.top());
                    st.pop();
                    st.push(s[i]);

                }

            }


            else if(s[i]=='/')
            {

                if(st.top()=='-' || s[i]=='+')
                {
                    st.push(s[i]);
                }

                else if(st.top()=='*')
                {
                    s2[k++]=s[i];
                    //s2.push_back(s[i]);


                }

            }

        }

           else if(s[i]==')')
            {
                while(s[i]!='(')
                {   char x=st.top();
                    st.pop();
                    s2[k++]=x;
                    //s2.push_back(x);

                }

            }

    }

    return s2;
}
int main()
{

    string s;

    cout<<"\n enter string";
    cin>>s;

    cout<<fun(s);

}
