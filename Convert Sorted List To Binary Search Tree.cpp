/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
TreeNode* createBST(vector<int> &lv, int s, int e){
    int n = lv.size();
    if(s < 0 || e >= n || e < s)
        return NULL;
    TreeNode *res;
    if(s == e){
        res = new TreeNode(lv[s]);
        return res;
    }
    int mid = (s + (e-s)/2);
    int value = lv[mid];
    res = new TreeNode(value);
    
    TreeNode *left = createBST(lv, s, mid-1);
    TreeNode *right = createBST(lv, mid+1, e);
    
    res->left = left;
    res->right = right;
    return res;
}
TreeNode* Solution::sortedListToBST(ListNode* A) {
    int n = 0;
    ListNode *node = A;
    vector<int> lv;
    while(node != NULL){
        n++;
        lv.push_back(node->val);
        node = node->next;
    }
    TreeNode *ans = createBST(lv, 0, n-1);
    return ans;
}
