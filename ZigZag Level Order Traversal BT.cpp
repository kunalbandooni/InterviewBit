/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// Simple BFS, and reversing alternate stored rows
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    if(!A)  return {{}};
    
    vector<vector<int>> res;
    queue<TreeNode* > q;
    q.push(A);
    while(!q.empty()){
        vector<int> temp;
        int size = q.size();
        while(size--){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
            temp.push_back(curr->val);
        }
        
        res.push_back(temp);
    }
    
    for(int i=0;i<res.size();i++)
        if(i%2 == 1)
            reverse(res[i].begin(),res[i].end());
    
    return res;
}
