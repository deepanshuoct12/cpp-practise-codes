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
//     void inorder(TreeNode *root,vector<int> &temp)
//     {
//         if(root==nullptr)
//             return;

//         inorder(root->left,temp);
//         temp.push_back(root->val);
//         inorder(root->right,temp);
//     }
    int cnt=0;
    int kthSmallest(TreeNode* root, int k) {

        if(root==nullptr)
            return 0;
        int l=kthSmallest(root->left,k);
        if(l!=0)
            return l;
        cnt++;
        if(cnt==k)
         return root->val;

        return kthSmallest(root->right,k);
        // vector<int>temp;
        // inorder(root,temp);
        // return temp[k-1];
    }
};
