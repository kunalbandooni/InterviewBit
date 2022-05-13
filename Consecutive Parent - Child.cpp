/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void util(TreeNode* root, int &res) {
    if(!root)
        return ;
    if(root->left )
        if(abs(root->val-(root->left->val))==1) 
            res++;
    if(root->right )
        if(abs(root->val-(root->right->val))==1) 
            res++;

    util(root->left,res);
    util(root->right,res);
}

int Solution::consecutiveNodes(TreeNode* A) {
    int res = 0;
    if(!A) 
        return res;

    util(A,res);
    return res;
}
