/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
vector<vector<TreeLinkNode*>> levelOrder(TreeLinkNode* root) { 
    vector<vector<TreeLinkNode*>> ans;
    if(!root)
        return ans;

    queue<TreeLinkNode*> q;
    q.push(root);
    while(!q.empty()) {
        vector<TreeLinkNode*> v;
        int n = q.size();
        for(int i=0; i<n; i++) {
            TreeLinkNode* node = q.front();
            q.pop();
            v.push_back(node);
            if(node->left)
                q.push(node->left);
            if(node->right) 
                q.push(node->right);
        }
        ans.push_back(v);
    }
    return ans;
}

void Solution::connect(TreeLinkNode* A) {
    vector<vector<TreeLinkNode*>> v;
    v = levelOrder(A);
    for(auto i : v) {
        for(int j=0; j<i.size()-1; j++) {
            i[j]->next = i[j+1];
        }
        i[i.size()-1]->next = NULL;
    }    
}
