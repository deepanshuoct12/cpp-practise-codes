#include<bits/stdc++.h>
using namespace std;
//#define hashmap unordered_map<char,node*>
void init_code(){
   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
class node
{
public:
    char data;
   unordered_map<char,node*> children;
    int prefixcount;
    bool isterminal;

    node(char d)
    {
        data=d;
        prefixcount=0;
        isterminal=false;
    }
};

class trie
{
    node *root;
    public:
        trie()
        {
            root=new node('\0');
        }

     // insertion
     void addword(string word)
     {
         node *temp=root;

         for(int i=0;i<word.length();i++)
         {
             char ch=word[i];
             if(temp->children.count(ch)==0)
             {
                 node *child = new node(ch);
                 temp->children[ch]=child;
                 temp=child;
             }
             else
             {
                 temp=temp->children[ch];
                
             }
              temp->prefixcount++;
         }
         temp->isterminal=true;
     }
   int countprefix(string word)
   {
        node *temp=root;
         for(int i=0;i<word.length();i++)
         {
             char ch=word[i];
             if(temp->children.count(ch)==0)
                return -1;
                 temp=temp->children[ch];
                 
         }
         return temp->prefixcount;
   }
};

int main()
{
    init_code();
    vector<string> word{"apple","ape","codes","coding blocks","no"};

    trie t;

    for(int i=0;i<5;i++)
        t.addword(word[i]);

    // char searchword[30];
     string w;
    cin>>w;
    int ans=t.countprefix(w);
    if(ans!=-1)
    cout<<ans;
    else 
      cout<<"Not possible";   

    return 0;
}