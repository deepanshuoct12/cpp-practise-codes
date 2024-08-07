
#include<iostream>
//#include<queue>
using namespace std;

class binarysearchtree
{
    public:
    int data;
    binarysearchtree *left;
    binarysearchtree*right;

    binarysearchtree( int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

/*binarysearchtree* buildtree()
{   int data;
    cout<<"\n entre data"<<"\n";
    cin>>data;
    queue<binarysearchtree *>q;
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
*/
binarysearchtree*inbst(binarysearchtree*root,int data)
{
    if(root==NULL)
        return new binarysearchtree(data);

    if(data<=root->data)
    {

        root->left=inbst(root->left,data);

    }

    else
        root->right=inbst(root->right,data);

    return root;
}

binarysearchtree*buildtree()
{

    int d;
  //  cout<<"\n enter data for root";
    cin>>d;
    cout<<"\n";
    binarysearchtree*root=NULL;
    while(d!=-1)
    {
        root=inbst(root,d);
      //  cout<<"enter data for left/right children"<<"\n";
        cin>>d;

    }
}

void print(binarysearchtree*root)
{
    if(root==NULL)
        return;

    print(root->left);
    cout<<root->data<<" " ;
    print(root->right);
}
/*
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
}  */

int main()
{
   binarysearchtree*root= buildtree();
   cout<<"\n";

   print(root);

    return 0;
}
