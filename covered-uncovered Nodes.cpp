/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
long Solution::coveredNodes(TreeNode* A) {
    queue<TreeNode*> q;
    q.push(A);
    set<TreeNode*> s1;
    set<TreeNode*> s2;

    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            TreeNode* t = q.front(); q.pop();
            if(i == 0 || i == n-1)
                s1.insert(t);
            else
                s2.insert(t);
            
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
        }
    }
    long l1 = 0, l2 = 0;
    for(auto it:s1)
        l1 += it->val;
    for(auto it:s2)
        l2 += it->val;
    return ((long)abs((long)l1 - (long)l2));
}
