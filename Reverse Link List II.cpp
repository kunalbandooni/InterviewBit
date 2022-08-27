/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
   
    ListNode* dummy= new ListNode(-1);
    dummy->next=A;
    auto prev=dummy;
    for(int i=0;i<B-1;i++)
        prev=prev->next;
   
    auto curr=prev->next;
    for(int i=0;i<C-B;i++){
        auto nxt=curr->next;
       
        curr->next=nxt->next;
        nxt->next=prev->next;
        prev->next=nxt;
    }
   
    return dummy->next;
}
