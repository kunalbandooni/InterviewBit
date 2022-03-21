/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int comparer(TreeNode* A, TreeNode* B){
    if(!A && !B) 
        return 1;
    if(!A || !B) 
        return 0;
    if(A->val != B->val) 
        return 0;
    return (comparer(A->left, B->right) && comparer(A->right, B->left));
} 
int Solution::isSymmetric(TreeNode* A) {
    return comparer(A,A);
}
