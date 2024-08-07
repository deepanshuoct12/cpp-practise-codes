/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    if(A==NULL)
    return ans;

    queue<pair<TreeNode*,int> >q;
    map<int,vector<int> >mp;

    q.push(make_pair(A,0));

    while(!q.empty())
    {
        pair<TreeNode*,int> p = q.front();
        q.pop();
        int dist=p.second;
        int value=p.first->val;
        mp[dist].push_back(value);


        if(p.first->left!=NULL)
        q.push(make_pair(p.first->left,dist-1));

        if(p.first->right!=NULL)
         q.push(make_pair(p.first->right,dist+1));

    }
     vector<int>v,ans;

    for(auto x:mp)
    {   v=x.second;

        ans.push_back(v[0]);
    }
    return ans;

}

