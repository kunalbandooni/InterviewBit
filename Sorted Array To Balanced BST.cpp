/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* buildutil(const vector<int> &A, int start, int end){
    if (start>end)
        return NULL;

    int mid = start + (end-start)/2;
    TreeNode* root = new TreeNode(A[mid]);

    if (start == end)
        return root;
    else {
        root->left = buildutil(A, start, mid-1);
        root->right = buildutil(A, mid+1, end);
    }
    return root;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    return buildutil(A, 0, A.size()-1);
}
