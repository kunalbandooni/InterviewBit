/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Utilizing Inorder Traversal

int res;
void func(TreeNode* p, int k, int &cnt){
    if(!p)
        return;

    func(p->left,k,cnt);
    if(cnt==k){
        res=p->val;
        cnt=INT_MAX;
        return;
    }
    cnt++;
    func(p->right,k,cnt);
}
int Solution::kthsmallest(TreeNode* a, int b){
    int cnt=1;
    res=-1;
    func(a,b,cnt);
    return res;
}
