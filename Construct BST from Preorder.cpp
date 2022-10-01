/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::constructBST(vector<int> &A) {
    stack<TreeNode*> st;
    TreeNode* root=new TreeNode(A[0]);
    TreeNode* res=root;
    st.push(root);
    for(int i=1;i<A.size();i++){
        TreeNode* prev=NULL;
        while(!st.empty() && st.top()->val<=A[i]){
            prev=st.top();
            st.pop();
        }
        TreeNode* curr=new TreeNode(A[i]);
        if(prev)   prev->right=curr;
        else    st.top()->left=curr;
        st.push(curr);
    }
    return res;
}
