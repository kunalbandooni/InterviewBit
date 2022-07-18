/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> v;
    
    func(A,B,v);
    
    return g;
}
