void func(TreeNode* A,vector<int> &v){
    if(!A)
        return;
    func(A->left,v);
    v.push_back(A->val);
    func(A->right,v);
}
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> v;
    func(A,v);
    return v;
}
