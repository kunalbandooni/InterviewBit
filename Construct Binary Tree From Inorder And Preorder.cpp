/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* build(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int,int> &m){
    if(inStart > inEnd || preStart > preEnd)  return NULL;
    
    TreeNode* root = new TreeNode(preorder[preStart]);
    
    int inRoot = m[root->val];
    int numsleft = inRoot - inStart;
    
    root->left = build(preorder, preStart + 1, preStart + numsleft, inorder, inStart, inRoot - 1, m);
    root->right = build(preorder, preStart + numsleft + 1, preEnd, inorder, inRoot + 1, inEnd, m);
    
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    map<int, int> m;
    for(int i=0;i<B.size();i++)
        m[B[i]] = i;
    TreeNode* root = build(A, 0, A.size()-1, B, 0, B.size()-1, m);
    return root;
}
