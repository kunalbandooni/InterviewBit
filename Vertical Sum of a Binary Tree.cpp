/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void help(TreeNode* root, map<int,int> &m, int location){
    if(!root)
        return;
    m[location] += root->val;
    help(root->left, m, location-1);
    help(root->right, m, location+1);
}
vector<int> Solution::verticalSum(TreeNode* A) {
    if(!A)
        return {};
    vector<int> v;
    map<int,int> m;
    help(A, m, 0);
    for(auto i:m)
        v.push_back(i.second);
    return v;
}
