/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<TreeNode*> helper(int l, int r, vector<vector<vector<TreeNode*>>> &dp) {
    if (l > r)
        return vector<TreeNode*>{NULL};
    if (dp[l][r].size() != 0)
        return dp[l][r];
    vector<TreeNode*> local;
    for (int i = l; i <= r; i++) {
        // get all trees of left sub array
        vector<TreeNode*> left_local = helper(l, i - 1, dp);
        // get all trees of right sub array
        vector<TreeNode*> right_local = helper(i + 1, r, dp);
        for (auto const &ll: left_local) {
            for (auto const &rr: right_local) {
                // make current element the root for all left and right trees
                TreeNode* root = new TreeNode(i);
                root->left = ll;
                root->right = rr;
                local.push_back(root);
            }
        }
    }
    dp[l][r] = local;
    return dp[l][r];
}
vector<TreeNode*> Solution::generateTrees(int A) {
    vector<vector<vector<TreeNode*>>> dp(A + 1, vector<vector<TreeNode*>>(A + 1, vector<TreeNode*>(0)));
    for (int i = 1; i <= A; i++)
        dp[i][i] = vector<TreeNode*>{new TreeNode(i)};
    return helper(1, A, dp);
}

/*
vector<TreeNode*> generateTree(int st, int end){
    if(st>end){
        vector<TreeNode*> ans;
        ans.push_back(NULL);
        return ans;
    }
    vector<TreeNode*> ans;
    for(int i = st; i <= end; i++){
        vector<TreeNode*> l = generateTree(st,i-1);
        vector<TreeNode*> r = generateTree(i+1,end);
        for(int j = 0; j < l.size(); j++){
            for(int k = 0; k < r.size(); k++){
                TreeNode* res = new TreeNode(i);
                res->left = l[j];
                res->right = r[k];
                ans.push_back(res);
            }
        }
    }
    return ans;
}
vector<TreeNode*> Solution::generateTrees(int A) {
    return generateTree(1,A);
}
*/
