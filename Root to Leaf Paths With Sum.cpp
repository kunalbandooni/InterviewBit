bool f(TreeNode* root, int currsum, int sum, vector<vector<int>> &ans, vector<int> &tempAns){
    if(root->left == NULL and root->right == NULL){
        currsum += root->val;
        tempAns.push_back(root->val);

        if(currsum == sum){
            ans.push_back(tempAns);
            tempAns.pop_back();
            return true;
        }
        tempAns.pop_back();
        return false;
    }

    tempAns.push_back(root->val);
    bool left = 0, right = 0;

    if(root->left != NULL)
        left = f(root->left, currsum + root->val, sum, ans, tempAns);
    
    if(root->right != NULL)
        right = f(root->right, currsum + root->val, sum, ans, tempAns);
    
    tempAns.pop_back();
    return left or right;
}
vector<vector<int> > Solution::pathSum(TreeNode* root, int sum) {
    vector<vector<int>> ans;
    vector<int> tempAns;

    f(root, 0, sum, ans, tempAns);
    return ans;
}
