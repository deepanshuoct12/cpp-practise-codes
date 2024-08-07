// C++ program to evaluate a given expression
#include <iostream>
#include<stack>
using namespace std;

// function to check if paranthesis are balanced
bool areParanthesisBalanced(string expr)
{
    stack<char> s;
    char x;

    // Traversing the Expression
    for (int i=0; i<expr.length(); i++)
    {
        if (expr[i]=='('||expr[i]=='['||expr[i]=='{')
        {
            // Push the element in the stack
            s.push(expr[i]);
            continue;
        }

        // IF current current character is not opening
        // bracket, then it must be closing. So stack
        // cannot be empty at this point.
        if (s.empty())
           return false;

        switch (expr[i])
        {
        case ')':

            // Store the top element in a
            x = s.top();
            s.pop();
            if (x=='{' || x=='[')
                return false;
            break;

        case '}':

            // Store the top element in b
            x = s.top();
            s.pop();
            if (x=='(' || x=='[')
                return false;
            break;

        case ']':

            // Store the top element in c
            x = s.top();
            s.pop();
            if (x =='(' || x == '{')
                return false;
            break;
        }
    }

    // Check Empty Stack
    return (s.empty());
}

// Driver program to test above function
int main()
{
    string expr = "{A+(B-C)}";

    if (areParanthesisBalanced(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}


/*int main()
{
    char expr1[] = "1+2*5+3";
    int res = evaluate(expr1);
    (res == -1)? cout << expr1 << " is " << "Invalid\n":
                 cout << "Value of " << expr1 << " is " << res << endl;

    char expr2[] = "1+2*3";
    res = evaluate(expr2);
    (res == -1)? cout << expr2 << " is " << "Invalid\n":
                 cout << "Value of " << expr2 << " is " << res << endl;

    char expr3[] = "4-2+6*3";
    res = evaluate(expr3);
    (res == -1)? cout << expr3 << " is " << "Invalid\n":
                 cout << "Value of " << expr3 << " is " << res << endl;

    char expr4[] = "1++2";
    res = evaluate(expr4);
    (res == -1)? cout << expr4 << " is " << "Invalid\n":
                 cout << "Value of " << expr4 << " is " << res << endl;
    return 0;
}*/
