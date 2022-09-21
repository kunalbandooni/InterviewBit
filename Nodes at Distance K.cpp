/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define pb push_back
void DepthK(TreeNode *root,int k,vector<int>&ans){
    if(!root) return;
    if(k==0){
        ans.pb(root->val);
        return;
    }
    DepthK(root->left,k-1,ans);
    DepthK(root->right,k-1,ans);
}
int helper(TreeNode* root,int b,int k,vector<int>&ans){
    if(!root)
        return -1;
    if(root->val==b){
        DepthK(root,k,ans);
        return 0;
    }
    int lD=helper(root->left,b,k,ans);
    if(lD!=-1){
        if(lD+1==k)
            ans.pb(root->val);
        DepthK(root->right,k-lD-2,ans);
        return lD+1;
    }
    
    int rD=helper(root->right,b,k,ans);
    if(rD!=-1){
        if(rD+1==k)
            ans.pb(root->val);
        DepthK(root->left,k-rD-2,ans);
        return rD+1;
    }
    return -1;
}
vector<int> Solution::distanceK(TreeNode* A, int B, int C) {
    vector<int>ans;
    helper(A,B,C,ans);
    return ans;    
}
