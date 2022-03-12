/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// NOTE :- Using RECURSION is not allowed

vector<int> Solution::preorderTraversal(TreeNode* A) {
    if(!A)
        return {};
    stack<TreeNode*> s;
    vector<int> v;
    s.push(A);
    while(!s.empty()){
        TreeNode* temp=s.top();
        v.push_back(temp->val);
        s.pop();
        if(temp->right)
            s.push(temp->right);
        if(temp->left)
            s.push(temp->left);
    }
    return v;
}
