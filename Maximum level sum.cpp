/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int bfs(TreeNode* root){
    int max_sum=-1;
    int sum=0;
    queue<TreeNode*> q;
    q.push(root);
    int size=1;
    while(!q.empty()){
        auto curr=q.front();
        q.pop();
        sum+=curr->val;
        if(curr->left)
            q.push(curr->left);
        if(curr->right)
            q.push(curr->right);
        size--;
        if(size==0){
            size=q.size();
            max_sum=max(sum,max_sum);
            sum=0;
        }
    }
    return max_sum;
}
int Solution::solve(TreeNode* A) {
    if(A==nullptr)
        return 0;
    return bfs(A);
}
