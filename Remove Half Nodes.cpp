/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::solve(TreeNode* A) {
    if(!A)
        return nullptr;
    if(A->left and A->right){
        A->left = solve(A->left);
        A->right = solve(A->right);
    }
    else if(A->left)
        A = solve(A->left);
    else if(A->right)
        A = solve(A->right);
    return A;
}
