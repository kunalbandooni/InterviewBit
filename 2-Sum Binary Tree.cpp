/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTiterator
{
    stack<TreeNode*> st;
    bool reverse;
    void pushAll(TreeNode* root){
        while(root!= NULL){
            st.push(root);
            if(!reverse)    root = root->left;
            else    root = root->right;
        }
    }
    public:
    BSTiterator(TreeNode *root, bool rev)
    {
        reverse = rev;
        pushAll(root);
    }

    int next()
    {
        TreeNode* root = st.top();
        st.pop();
        if(!reverse) pushAll(root->right);
        else    pushAll(root->left);
        return root->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};
int Solution::t2Sum(TreeNode* root, int k) {
    if(!root)    return false;
    BSTiterator l(root, false);
    BSTiterator r(root, true);
    
    int i = l.next();
    int j = r.next();
    
    while(i<j){
        if(i+j == k)    return true;
        if(i+j < k)    
            i = l.next();
        else
            j = r.next();
    }
        
    return false;
}
