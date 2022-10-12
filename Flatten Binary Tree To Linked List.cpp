/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void func(TreeNode* root){
    if(!root)  return;
    
    TreeNode *node, *temp;
    
    temp = root->right;
    root->right = root->left;
    
    root->left = NULL;
    node = root;
    
    while(node->right)
        node = node->right;
    
    node->right = temp;
    func(root->right);
}
TreeNode* Solution::flatten(TreeNode* root) {
    func(root);
    return root;
}
