#include<bits/stdc++.h>
using namespace std;
class Queue{
  stack<int>s1,s2;

  public:
      void Push(int x)
      {
          s1.push(x);
      }
      int Pop()
      {
          if(s1.empty())
            return -1;

            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            int v=s2.top();
            s2.pop();
             while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
      }

};
int main()
{


}
