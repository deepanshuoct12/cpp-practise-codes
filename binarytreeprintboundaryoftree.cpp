#include<bits/stdc++.h>
using namespace std;

class treenode{
    int data;
    treenode *left;
    treenode *right;

     treenode(int data)
     {
         this->data=data;
         left=nullptr;
         right=nullptr;
     }
};

void printleaves(treenode*root,vector<int>&ans)
{
    if(root==nullptr)
        return;
    printleaves(root->left,ans);
    if(root->left==nullptr && root->right==nullptr)
    ans.push_back(root->data);
    printleaves(root->right,ans);
}
void printleft(treenode*root,vector<int>&ans)
{
    if(root==nullptr)
        return;
    if(root->left)
    {
        ans.push_back(root->data);
        printleft(root->left,ans);
    }
    else if(root->right)
    {
        ans.push_back(root->data);
        printleft(root->right,ans);
    }
}

void printright(treenode*root,vector<int>&ans)
{
    if(root==nullptr)
        return;
    if(root->right)
    {

        printright(root->right,ans);
        ans.push_back(root->data);
    }
    else if(root->left)
    {
        printright(root->left,ans);
        ans.push_back(root->data);
    }
}

void printboundary(treenode *root,vector<int>&ans)
{
    if(root==nullptr)
        return ;
    printleft(root->left,ans);
    printleaves(root->left,ans);
    printleaves(root->right,ans);
    printright(root->right,ans);
}

int main()
{
    vector<int>ans;
    printboundary(root,ans);
    return 0;
}
