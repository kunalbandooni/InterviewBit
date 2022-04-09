/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
