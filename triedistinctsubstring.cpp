#include<bits/stdc++.h>
class trienode{
    public:
    char data;
    unordered_map<char,trienode* >children;
    bool isterminal;
   
    trienode(char data)
    {
        this->data=data;
        this->isterminal=false;
    }
    
};
int countDistinctSubstrings(string &str)
{
    trienode *root=new trienode('\0');
    int n=str.length();
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        trienode* curr=root;
        for(int j=i;j<n;j++)
        {
          if(curr->children.count(str[j])==0)
          {
              trienode* temp=new trienode(str[j]);
              curr->children[str[j]]=temp;
              cnt++;
          }
            curr=curr->children[str[j]];
            curr->isterminal=true;
        }
    }
    return cnt+1;
    //    Write your code here.
}