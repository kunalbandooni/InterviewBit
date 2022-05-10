/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    TreeLinkNode* prev;
    queue<TreeLinkNode*> q;
    q.push(A);
    while(q.size()>0){
        int sz=q.size();
        prev=NULL;
        for(int i=0;i<sz;i++){
            TreeLinkNode* temp=q.front();
            q.pop();
            if(prev==NULL)
                prev=temp;
            else{
                prev->next=temp;
                prev=temp;
            }
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        prev->next=NULL;
    }
}
