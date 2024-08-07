#include<stdio.h>
struct bstnode{
int info;
struct bstnode*left;
struct bstnode*right;
};
struct bstnode*insertnode(struct bstnode*root,int data)
{
    if(root==NULL)
    {
        struct bstnode*newnode=(struct bstnode*)malloc(sizeof(struct bstnode));
        newnode->info=data;
        newnode->left=NULL;
        newnode->right=NULL;
        return newnode;
    }

    else if(data<root->info)
    {
        root->left=insertnode(root->left,data);
    }
     else if(data>root->info)
    {
        root->right=insertnode(root->right,data);
    }
    return root;
};

void display(struct bstnode*root)
{

    if(root==NULL){
        return;
    }

    display(root->left);
    printf("%d",root->info);
    printf(" ");
    display(root->right);
}

int main()
{
    int data;
    struct bstnode*root=(struct bstnode*)malloc(sizeof(struct bstnode));
    root=NULL;
    printf("enter data\n");
    scanf("%d",&data);

    while(data!=-1)
    {
        root=insertnode(root,data);
        printf("now enter data");
        printf("\n");
        scanf("%d",&data);
    }
    printf("\n");
    display(root);
}
