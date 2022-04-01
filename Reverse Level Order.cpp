/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Simple Solution
vector<int> Solution::solve(TreeNode* A) {
    vector<int> G,i;
    queue<TreeNode* > Q;
    TreeNode* root = A;
    Q.push(A);
    while(!Q.empty()){
        root = Q.front();
        Q.pop();
        G.push_back(root->val);
        if(root->right)
            Q.push(root->right);
        if(root->left)
            Q.push(root->left);
    }
    for(int j = G.size()-1;j>=0;j--)        
        cout<<G[j]<<" ";
    return i;
}

// TC: O(n)
/*vector<int> Solution::solve(TreeNode* A) {
    queue<pair<int, TreeNode*>> q;
    int x=0;
    vector<int> ans,subv;
    q.push({0,A});
    while(!q.empty()){
        TreeNode* n = q.front().second;
        int level = q.front().first;
        q.pop();
        if(level > x){
            x++;
            ans.insert(ans.begin(),subv.begin(),subv.end());
            subv.clear();
        }

        if(n->left)
            q.push({level+1,n->left});
        if(n->right)
            q.push({level+1,n->right});
        
        if(level == x)
            subv.push_back(n->val);
    }
    ans.insert(ans.begin(),subv.begin(),subv.end());
    return ans;
}*/
