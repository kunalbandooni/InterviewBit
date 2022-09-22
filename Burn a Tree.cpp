/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void getAdjacents(TreeNode*root,TreeNode*parent,unordered_map<int,vector<int>>&mp){
    if(!root)   return;

    vector<int>temp;
    if(parent!=NULL)
        temp.push_back(parent->val);

    if(root->left)
        temp.push_back(root->left->val);   

    if(root->right)
        temp.push_back(root->right->val);

    mp[root->val]=temp;
    getAdjacents(root->left,root,mp);
    getAdjacents(root->right,root,mp);
}
int Solution::solve(TreeNode* root, int start){
    unordered_map<int,vector<int>>mp;
    getAdjacents(root,NULL,mp);
    unordered_map<int,bool>vis;
    queue<int>q;

    int count=0;
    q.push(start);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            int node=q.front();
            vis[node]=true;
            q.pop();
            
            for(auto it:mp[node]){
                if(!vis[it])
                    q.push(it);   
            }

        }
        count++;
    }
    return count-1;
}
