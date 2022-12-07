/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* tree(vector<int> &node, int start, int end){
    if(start > end) return NULL;

    int maxi = INT_MIN, ind = -1;
    for( int i = start; i <= end; i++){
        if(maxi < node[i]){
            maxi = node[i];
            ind = i;
        }
    }

    TreeNode* root = new TreeNode(node[ind]);
    root->left = tree(node,start,ind-1);
    root->right = tree(node, ind+1, end);

    return root;
}
TreeNode* Solution::buildTree(vector<int> &node) {
    return tree(node,0,node.size()-1);
}
