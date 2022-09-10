/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* build(int instart, int inend, vector<int> &inorder, int poststart, int postend, vector<int> &postorder, unordered_map<int,int> &m){
    if(instart > inend || poststart > postend)   return NULL;
    
    TreeNode* root = new TreeNode(postorder[postend]);
    
    int index = m[root->val];
    int numsleft = index - instart;
    
    root->left = build(instart, index-1, inorder, poststart, poststart + numsleft - 1, postorder, m);
    root->right = build(index+1, inend, inorder, poststart + numsleft, postend-1, postorder, m);
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    if(A.size() == 0)   return NULL;
    unordered_map<int, int> mp;
    for(int i=0;i<A.size();i++)
        mp[A[i]] = i;
    return build(0, A.size()-1, A, 0, B.size()-1, B, mp);
}
