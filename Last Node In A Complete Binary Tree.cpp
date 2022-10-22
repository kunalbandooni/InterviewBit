/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int depth(TreeNode* root){
    if(root == NULL)    return -1;
    int d=0;
    while(root){
        root = root->left;
        d++;
    }
    return d;
}
int Solution::lastNode(TreeNode* root) {  
    int val=-1;
    while(root){
        val=root->val;
        root = depth(root->left) > depth(root->right) ? root->left : root->right;
    }
    return val;
}
