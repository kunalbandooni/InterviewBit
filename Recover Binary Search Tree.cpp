/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inorder(TreeNode* A,vector < int> &v){
    if(A==NULL)
        return ;
    inorder(A->left,v);
    v.push_back(A->val);
    inorder(A->right,v);
}
vector<int> Solution::recoverTree(TreeNode* A) {
    vector< int> v,c,d;
    inorder(A,v);
    int n=v.size();
    for(int i=0;i<n;i++)
        c.push_back(v[i]);
    sort(c.begin(),c.end());
    for(int i=0;i<n;i++){
        if(c[i]!=v[i]){
            d.push_back(c[i]);
            d.push_back(v[i]);
            break;
        }
    }
    return d;
}
