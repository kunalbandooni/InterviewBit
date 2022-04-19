/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    ListNode* head = A;
    while(A and A->next){
        swap(A->val, A->next->val);
        A=A->next->next;
    }
    return head;
}
