class trienode{
    public:
    char data;
    int wordcnt,prefixcnt;
    unordered_map<char,trienode*>children;
    trienode(char data)
    {
        this->data=data;
        this->wordcnt=0;
        this->prefixcnt=0;
    }
};
class Trie{
   trienode* root;
    public:

    Trie(){
        root=new trienode('\0');
        // Write your code here.
    }

    void insert(string &word){
        trienode* curr=root;
        for(int i=0;i<word.length();i++)
        {
            char ch=word[i];
            if(curr->children.find(ch)==curr->children.end())
            {
               trienode* temp=new trienode(ch);
                curr->children[ch]=temp;
            }
             curr=curr->children[ch];
               curr->prefixcnt++;
        }
        curr->wordcnt++;
    }

    int countWordsEqualTo(string &word){
        trienode* curr=root;
        for(int i=0;i<word.length();i++)
        {
            char ch=word[i];
            if(curr->children.find(ch)==curr->children.end())
            {
              return 0;
            }
            else 
                curr=curr->children[ch];
        }
       
        return curr->wordcnt;
    }

    int countWordsStartingWith(string &prefix){
        trienode* curr=root;
        for(int i=0;i<prefix.length();i++)
        {
            char ch=prefix[i];
            if(curr->children.find(ch)==curr->children.end())
            {
              return 0;
            }
            else 
                curr=curr->children[ch];
        }
        return curr->prefixcnt; 
    }

    void erase(string &word){
         trienode* curr=root;
        for(int i=0;i<word.length();i++)
        {
            char ch=word[i];
            if(curr->children.find(ch)!=curr->children.end())
            {
                curr=curr->children[ch];
                curr->prefixcnt--;
            }
        }
      curr->wordcnt--;
    }
};