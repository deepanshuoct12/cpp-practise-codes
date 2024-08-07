
#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

class binarytree
{
    public:
    int data;
    binarytree *left;
    binarytree*right;

    binarytree( int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

class pair
{
    public:

    int h;
    bool b;

    pair()
    {
        h=0;
        b=false;
    }
};
//pair pb;

pair balance( binarytree*root)           /// balance chk f'n
{
    pair p;
    if(root==NULL)
    {
        p.h=0;
        p.b=true;
        return p;
    }

    pair left=balance(root->left);           /* chk  for left and right balance*/
    pair right=balance(root->right);            //post order traversal

    p.h=max(left.h,right.h)+1;

    if(abs(left.h-right.h)<=1 && left.b==true && right.b==true)
    {
        p.b=true;

    }
    else
        p.b=false;

    return p;
}

binarytree* buildtree()
{   int data;
    cout<<"\n entre data"<<"\n";
    cin>>data;
    queue<binarytree *>q;
    if(data==-1)
        return NULL;
    binarytree* root=new binarytree(data);
    q.push(root);

    while(!q.empty())
    {
        binarytree*curr= q.front();
        q.pop();
        int leftdata,rightdata;

        cin>>leftdata;
        if(leftdata!=-1)
        {
            binarytree*leftnode=new binarytree(leftdata);
            curr->left=leftnode;
            q.push(leftnode);
        }

        cin>>rightdata;
        if(rightdata!=-1)
        {
            binarytree*rightnode=new binarytree(rightdata);
            curr->right=rightnode;
            q.push(rightnode);
        }
    }
    return root;
}

/*int height(binarytree *root)
{
     if(root==NULL)
        return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    return max(lh,rh)+1;
}

void printlevelwise(binarytree*root,int k)
{
    if(root==NULL)
        return ;
    if(k==1 && root!=NULL)
        cout<<root->data<<" ";

    printlevelwise(root->left,k-1);
    printlevelwise(root->right,k-1);
}
void print(binarytree* root)
{
    if(root==NULL)
        return;
    int h=height(root);

    for(int i=1;i<=h;i++)
    {
        printlevelwise(root,i);
    }

    return ;
}*/

int main()
{
   binarytree*root= buildtree();
   cout<<"\n";

   //print(root);*/
   if(balance(root).b)
    cout<<"balance\n";
   else
    cout<<"\n not balance";

    return 0;
}

