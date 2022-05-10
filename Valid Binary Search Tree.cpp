/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool isBSTUtil(TreeNode *root, int minVal, int maxVal){
    if(root == NULL) 
        return true;
    if(root->val > minVal && 
        root->val < maxVal && 
        isBSTUtil(root->left, minVal, root->val) && 
        isBSTUtil(root->right, root->val, maxVal))
        return true;
    else 
        return false;
    // we check if left subtree nodes value in range (minVal to root val)
    // and right subtree nodes value in range (root val to maxVal) recursively
} 
int Solution::isValidBST(TreeNode* A) {
    return isBSTUtil(A, INT_MIN, INT_MAX);
}
