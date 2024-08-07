/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 TreeNode* helper(vector<int> &pre,vector<int> &in,int s,int e,int &i)
{
     if(s>e)
     return NULL;

     TreeNode* root = new TreeNode(pre[i]);
     int index=-1;
     for(int j=s;j<=e;j++)
     {
         if(pre[i]==in[j])
         {
             index=j;
             break;
         }
     }
     i++;
     root->left=helper(pre,in,s,index-1,i);
     root->right=helper(pre,in,index+1,e,i);


     return root;

}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {

   int i=0;
    TreeNode* ans=helper(A,B,0,A.size()-1,i);
    return ans;
}

