void func(TreeNode* A, vector<int> &v){
    if(!A)
        return;
    func(A->left,v);
    func(A->right,v);
    v.push_back(A->val);
}
vector<int> Solution::postorderTraversal(TreeNode* A) {
    vector<int> v;
    func(A,v);
    return v;
}
