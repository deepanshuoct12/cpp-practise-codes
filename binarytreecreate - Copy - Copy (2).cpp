#include<iostream>

using namespace std;

class node
{
 public:
    int data;

    node*left;
    node*right;

   /* binarytree()
    {
        this->data=0;
    }*/
    node(int data )
    {  this->data=data;
        left=NULL;
        right=NULL;
    }
};

node* createtree()
{
    int data;

    cin>>data;
    if(data==-1)
       {
           return NULL;

       }


    node*root=new node(data);

    root->left=createtree();
    root->right=createtree();

    return root;
}

void printpreorder (node*root)
{

    if(root==NULL)
        return ;
    cout<<root->data<<" ";

    printpreorder(root->left);
    printpreorder(root->right);
}

void printpostorder(node*root)
{
    if(root=NULL)
        return;
    printpostorder(root->left);
    printpostorder(root->right);
    cout<<root->data<<" ";
}

void printinorder(node*root)
{
    if(root==NULL)
        return ;
    printinorder(root->left);
    cout<<root->data<<" ";
    printinorder(root->right);


}
int main()
{
    node *b=createtree();

  //  printpreorder(b);
    //cout<<"\n";
    printpostorder(b);
    cout<<"\n";
  //  printinorder(b);
    //cout<<"\n";
    return 0;
}
