#include<iostream>
#include<queue>
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

  int replacesum(binarytree* root)
 {
     if(root==NULL)
        return 0;
     if(root->left==NULL && root->right==NULL)
        return root->data;

        int leftsum=replacesum(root->left);
        int rightsum=replacesum(root->right);

        int temp=root->data;
        root->data=leftsum+rightsum;

        return temp+root->data;

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

int height(binarytree *root)
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
}

int main()
{
   binarytree*root= buildtree();
   cout<<"\n";

   print(root);

    return 0;
}

