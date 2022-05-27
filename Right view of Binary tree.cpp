/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int max_level(TreeNode *ptr, int l){
    if(not ptr) 
        return l;   
    else 
        return max(max_level(ptr->left,l),max_level(ptr->right, l))+1;
}
vector<int> Solution::solve(TreeNode *A) {
    if(not A) 
        return {};
    queue<pair<TreeNode *,int>> q;
    q.push({A,0});
    vector<int> ans(max_level(A,0));
    while(not q.empty()){
        TreeNode *ptr=q.front().first;
        int level=q.front().second;
        q.pop();
        ans[level]=ptr->val;
        if(ptr->left) 
            q.push({ptr->left, level+1});
        if(ptr->right) 
            q.push({ptr->right, level+1});
    }
    return ans;
}
