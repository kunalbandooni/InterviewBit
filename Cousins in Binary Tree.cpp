/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* root, int k) {
    queue<pair<TreeNode*,TreeNode*>> q;
    q.push({root,NULL});
    vector<int> ans;
   
    while(!q.empty())
    {
        int size=q.size();
        vector<pair<int,TreeNode*>> temp;
        TreeNode* parent=NULL;
        bool flag=false;
        while(size--)
        {
            TreeNode* node=q.front().first;
            TreeNode* par=q.front().second;  // "par" is parent of every node.
            q.pop();
            if(node->val==k)
            {
                flag=true;
                parent=par;  // "parent" is parent of targeted node
            }
            temp.push_back({node->val,par});  
            if(node->left)
            {
                q.push({node->left,node});
            }
            if(node->right)
            {
                q.push({node->right,node});
            }
        }
       
        if(flag)
        {
            for(auto x: temp)
            {
                // checking for different parent in same level of binary tree.
                if(x.second!=parent)
                    ans.push_back(x.first);
            }  
            break;
        }
       
    }
    return ans;
}
