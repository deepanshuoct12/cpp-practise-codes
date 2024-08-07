#include<bits/stdc++.h>
using namespace std;


class node{
int data;
node*left,*right;
node(int v){
    this->data=v;
    this->left=nullptr;
    this->right=nullptr;
}

};

void printpath(vector<int>path,int i){
    for(int j=i;j<path.size();j++)
        cout<<path[j]<<" ";

}

void pathsum(node *root,vector<int>path,int sum){
if(root==nullptr||sum==0)
    return;

    path.push_back(root->data);

    pathsum(root->left,path,sum);
    pathsum(root->right,path,sum);
    int s=0;
    for(int i=path.size()-1;i>=0;i--)
    {
        s+=path[i];
        if(s==sum)
            printpath(path,i);
    }
    path.pop_back();
}
int main(){


return 0;
}
