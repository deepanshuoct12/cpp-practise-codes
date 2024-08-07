/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=INT_MIN;
    int helper(TreeNode *root)
    {
          if(root==NULL)
            return 0;
        int leftsum=helper(root->left);
        int rightsum=helper(root->right);

        int a=root->val;
        int b=root->val+leftsum;
        int c=root->val+rightsum;
        int d=root->val+leftsum+rightsum;
        ans=max(ans,max(max(a,b),max(c,d)));
        return max(max(a,b),c);
    }

    int maxPathSum(TreeNode* root) {
      helper(root);
        return ans;
//         if(root->left==NULL && root->right==NULL)
//             return root->val;
//         int leftsum=maxPathSum(root->left);
//         int rightsum=maxPathSum(root->right);
//         if(leftsum>0 && rightsum<0)
//         {
//             return max(leftsum,leftsum+root->val);
//         }
//          if(rightsum>0 && leftsum<0)
//         {
//             return max(rightsum,rightsum+root->val);
//         }
//         if(leftsum<0 && rightsum<0)
//         {
//             if(root->val<0)
//                 return max(max(leftsum,rightsum),root->val);
//             return root->val;
//         }
//         if(root->val<0)
//         {
//             return max(max(leftsum,rightsum),leftsum+rightsum+root->val);
//         }
//         return leftsum+rightsum+root->val;
    }
};
