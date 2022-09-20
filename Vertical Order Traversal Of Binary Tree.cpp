/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
map<int,vector<int>>mp;
void dfs(TreeNode*A, int pos){
    if(A==NULL)
        return;
    queue<pair<TreeNode*,int>>q;
    q.push({A,pos});
    while(!q.empty()){
        pair<TreeNode*,int> front = q.front();
        q.pop();
        mp[front.second].push_back(front.first->val);
        if(front.first->left!=NULL)
            q.push({front.first->left,front.second-1});
        if(front.first->right!=NULL)
            q.push({front.first->right,front.second+1});
    }
}
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    mp.clear();
    vector<vector<int>>ans;
    dfs(A,0);
    for(auto i:mp){
        ans.push_back(i.second);
    }
    return ans;
}
