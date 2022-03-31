/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int ans=0;
void help(TreeNode* A, int B){
    if(!A->left and !A->right){
        if(B - A->val == 0)
            ans++;
    }
    if(A->left)
        help(A->left, B - A->val);
    if(A->right)
        help(A->right, B - A->val);
}
int Solution::hasPathSum(TreeNode* A, int B) {
    ans=0;
    help(A,B);
    return ans&&1;
}
