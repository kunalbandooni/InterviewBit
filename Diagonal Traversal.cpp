/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// little modification of vertical traversal
// here diagonal number instead of horizontal distance
typedef map<int, vector<int>> MP;   //{diagonal, elements}
void helper(TreeNode* node, int diagonal, MP &mp){
    if(node == NULL) return;
    mp[diagonal].push_back(node->val);    
    helper(node->left, diagonal + 1, mp);
    helper(node->right, diagonal, mp);
}
vector<int> Solution::solve(TreeNode* root) {
    MP mp;
    int diagonal = 0;
    helper(root, diagonal, mp);
    vector<int> ans;

    for(auto itr = mp.begin(); itr!=mp.end(); ++itr)
        ans.insert(ans.end(), itr->second.begin(), itr->second.end());
    
    return ans;
}
