/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode* A) {
    if(!A)
        return 0;
    if(!A->left and !A->right)
        return 1;
    int l=INT_MAX,r=INT_MAX;
    if(A->right)
        r=minDepth(A->right);
    if(A->left)
        l=minDepth(A->left);
    return 1 + min(l,r);
}
