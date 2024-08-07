#include<bits/stdc++.h>
using namespace std;
//#define hashmap unordered_map<char,node*>

class node
{
public:
    char data;
   unordered_map<char,node*> children;

    bool isterminal;

    node(char d)
    {
        data=d;
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
         }
         temp->isterminal=true;
     }

     // searching
     bool search(string word)
     {
         node *temp=root;

         for(int i=0;i<word.length();i++)
         {
             char ch=word[i];
             if(temp->children.count(ch))
             {
                 temp=temp->children[ch];
             }
             else
                return false;
         }

         return temp->isterminal;

     }

     void deletehelper(string word,node* curr)
     {
        if(word.length()==0)   // if found the word in trie make it terminal false, as it no longer exist 
        {
            curr->isterminal=false;
            return;
        }

        char ch=word[0];

        if(curr->children.count(ch)==0)
            return;
        node* child = curr->children[ch];
        deletehelper(word.substr(1),child);
        if(child->isterminal==false)
        {
            if(!child->children.empty()) // if child further had children nodes so dont remove this ch key 
                return;

            root->children.erase(ch); // else remove it 
        }
     }
     //delete trie node
     void deleteword(string word)
     {    node* curr=root;
          deletehelper(word,curr);
     }


};
int main()
{
    vector<string> word{"apple","ape","codes","coding blocks","no"};

    trie t;

    for(int i=0;i<5;i++)
        t.addword(word[i]);

    // char searchword[30];
     string searchword;
    cin>>searchword;

    if(t.search(searchword))
    {
        cout<<searchword<<" "<<"found"<<"\n";

    }

    else
    {
        cout<<"not found";
    }

    return 0;
}
////////////without map/////////////

// class TrieNode{
// public:
//     bool end;
//     TrieNode* child[27];
//     TrieNode(){
//         end = false;
//         memset(children, NULL, sizeof(children));
//     }
// };

// TrieNode* root = new TrieNode();        /* Root Creation */

// void insert(string word) {              /* Insert word into the trie */
//     TrieNode* node = root;
//     for(char c : word){
//         if(!node -> child[c - 'a']){
//             node -> child[c - 'a'] = new TrieNode();
//         }
//         node = node -> child[c - 'a'];
//     }
//     node -> end = true;
// }


// bool search(string word) {             /* Search word into the trie */
//     TrieNode* node = root;
//     for(char c : word){
//         if(!node -> child[c - 'a']){
//             return false;
//         }
//         node = node -> child[c - 'a'];
//     }
//     return node -> end;
// }


/////////////////////////////perul///////////////////////////////
// class TrieNode{
   
//    public :     
//    char data;
//    vector<TrieNode*> children;
//    bool isEnd;
   
//    TrieNode (char data) {
//     this->data = data;
//     children.resize(26);
//     for (int i=0; i<26; i++)
//     children[i] = NULL;
//     this->isEnd=false;
//  }

// };



// class Trie {
    
//     private :
//     TrieNode *root;
    
//     public:
    
//     Trie() {
//         root = new TrieNode('\0');
//     }
    
//     void insertWord(string word, TrieNode *root) {
//         if(word.size()==0) {
//             root->isEnd = true;
//             return;
//         }
        
//         int index = word[0]-'a';    
//          TrieNode* children = root->children[index]; 
//         if(root->children[index] == NULL) {
          
//             children = new TrieNode(word[0]);
//             root->children[index]=children;
//         }
        
//         insertWord(word.substr(1),children);
//     }
    
//     void insertWord (string word) {
//         insertWord(word, root);
//     }
    
//     bool searchWord (string word, TrieNode *root) {
        
//         if(root == NULL)
//             return false;
        
//         if (word.length() == 0)
//             return root->isEnd;
            
//         int index = word[0]-'a';
        
//         TrieNode *children = root->children[index];
        
//         if (children==NULL) 
//             return false;
        
//         return searchWord (word.substr(1), children);
        
                
//     }
    
//     bool searchWord (string word) {
//         return searchWord (word, root);
//     }
    
//     void removeWord (string word , TrieNode *root) {   
//         if (word.length() == 0) {
//             root->isEnd = false;
//             return;
//         }
//         int index = word[0] - 'a';  
//         TrieNode *child = root->children[index];     
//         // not found word
//         if (child == NULL)
//             return;      
//         removeWord(word.substr(1), child);      
//         if (child->isEnd == false) {         
//             for (int i=0; i<26; i++) {
//                 if(child->children[i]!=NULL) {
//                     return;
//                 }
//             }
//             delete child;
//             root->children[index] =  NULL;
//         }            
//     }
    
//     void removeWord (string word) {
//         removeWord(word, root);
//     }
// };