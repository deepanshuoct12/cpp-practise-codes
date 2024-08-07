class trienode{
    public:
    char data;
    unordered_map<char,trienode*>children;
    bool isterminal;
    trienode(char ch)
    {
        this->data=ch;
        this->isterminal=false;
    }
};

class Solution {
    trienode* root;
public:
    Solution()
    {
        root=new trienode('\0');
    }
    
    void insert(string word)
    {
        trienode* curr=root;
        for(int i=0;i<word.length();i++)
        {
            char ch=word[i];
            if(curr->children.count(ch)==0)
            {
               trienode* temp = new trienode(ch);
                curr->children[ch]=temp;
                curr=temp;
            }
            else 
                curr=curr->children[ch];
         
        }
        curr->isterminal=true;
    }
    
    string lcp()
    {
        trienode* curr=root;
        if(curr->children.size()>1)
            return "";

        string ans;
        while(1)
        {
            for(int i=0;i<26;i++)
            {
                char ch=(char)(i+'a');
                if(curr->children.count(ch))
                {   ans.push_back(ch);
                    curr=curr->children[ch];
                     break;
                }
            }
            if(curr->children.size()>1 || curr->isterminal==true)
                break;
        }
            
        return ans;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        
         if(strs.size()==1)
            return strs[0];
  
        for(auto x:strs)
        {   
            if(x.length()==0)
                return "";
            insert(x);
        }
        
        return lcp();
        
    }
};