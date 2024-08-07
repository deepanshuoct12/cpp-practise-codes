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
class trie{
    trienode* root;
    public:
    trie()
    {
        root=new trienode('\0');
    }
    void insert(string str)
    {
        trienode* curr=root;
        for(int i=0;i<str.length();i++)
        {
            char ch=str[i];
            if(!(curr->children.count(ch)))
            {
               trienode* temp=new trienode(ch);
                curr->children[ch]=temp;
            }
            curr=curr->children[ch];
        }
        curr->isterminal=true;
    }
    bool searchallprefixes(string str)
    {
        trienode* curr=root;
       for(int i=0;i<str.length();i++)
        {
            char ch=str[i];
            if(!(curr->children.count(ch)))
            {
               return false;
            }
           else{
               curr=curr->children[ch];
               if(!curr->isterminal)
                   return false;
           }
        }
     return true;
    }
    
};
string completeString(int n, vector<string> &a){
     trie ob;
    string ans="";
    for(int i=0;i<n;i++)
    {
        ob.insert(a[i]);
    }
    
    for(int i=0;i<n;i++)
    {
        string temp=a[i];
        bool f=1;
            if(!ob.searchallprefixes(temp))
            {
                f=0;
            }
        if(f)
        {
            if(a[i].length()>ans.length())
            {
                ans=a[i];
            }
            else if(a[i].length()==ans.length() && a[i]<ans)
            {
                ans=a[i];
            }
        }
        
    }
    if(ans=="")
        ans="None";
    return ans;
    // Write your code here.
}