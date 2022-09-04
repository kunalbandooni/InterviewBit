/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Using two vector
/*
vector<int> g;
void func(TreeNode* A, int B, vector<int> v){
    if(!A)   return;
    
    v.push_back(A->val);
    
    if(A->val == B){
        g=v;
        return;
    }
    
    func(A->left,B,v);
    func(A->right,B,v);
}*/

// Using one array...
bool func(TreeNode* root, int x, vector<int> &v){
    if(!root)   return false;
    v.push_back(root->val);
    if(x == root->val)  
        return true;
    if(func(root->left, x, v) or func(root->right, x, v))
        return true;
    v.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> v;
    func(A,B,v);
    return v;
}
