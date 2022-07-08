/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int sum(TreeNode* root, int &ans){
    if(root==NULL)
        return 0;
    int lh = max(0,sum(root->left,ans));
    int rh = max(0,sum(root->right,ans));
    ans =  max(ans, root->val + lh+rh);
    return root->val + max(lh,rh);
}
int Solution::maxPathSum(TreeNode* root) {
    int ans = INT_MIN/2;
    sum(root,ans);
    return ans;
}
