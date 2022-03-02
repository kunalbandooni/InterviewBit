//Simply calculate the height of a tree

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Recursive Approach:-
int Solution::maxDepth(TreeNode* A) {
    if(!A)
        return 0;
    return 1+max(maxDepth(A->left),maxDepth(A->right));
}
