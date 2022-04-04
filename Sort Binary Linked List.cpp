/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    if(A==NULL||A->next==NULL){
        return A;
    }
    ListNode* count = A,*curr = A;
    while(curr!=NULL){
        if(curr->val!=1){
            swap(curr->val , count->val);
            count = count->next;
        }
        curr = curr->next;
    }
    return A;
}
