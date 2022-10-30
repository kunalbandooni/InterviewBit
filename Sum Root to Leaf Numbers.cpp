/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve(TreeNode *root, int ans ,vector<int> &res){
    if(!root) return; 
    
    ans = (ans*10 + root->val)%1003;
     
    if(!root->left && !root->right){
        res.push_back(ans%1003);
        return;
    }
     
    solve(root->left,ans,res);
    solve(root->right,ans,res);
}
int Solution::sumNumbers(TreeNode* A) {
    vector<int> res;
    int ans =0;

    solve(A, ans, res);
    int sum =0;

    for(auto x: res)
    sum += x;

    return sum%1003;
}
