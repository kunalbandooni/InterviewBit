TreeNode* dfs(TreeNode* root,int &a,int &b){
    if(root==NULL)
        return NULL;
    TreeNode *l = dfs(root->left,a,b);
    TreeNode *r = dfs(root->right,a,b);
    if(l!=NULL && r!=NULL)
        return root;
    if(root->val==a || root->val==b){
        a=root->val==a?-1:a;
        b=root->val==b?-1:b;
        return root;
    }
    return l!=NULL?l:r;
} 
int Solution::lca(TreeNode* root, int a, int b) {
    TreeNode* k = dfs(root,a,b);
    if(k!=NULL && a==-1 && b==-1)return k->val;
    return -1;
}
