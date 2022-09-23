/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    ListNode* dummy = new ListNode(0);
    B--;
    ListNode* prev = dummy;
    dummy->next = A;
    while(A!=NULL){
        int n = B;
            while(n-- and A->next!=NULL){
                ListNode* temp = A->next;
                ListNode* temp2 = prev->next;
                A->next = A->next->next;
                prev->next = temp;
                temp->next = temp2;
            }
        prev = A;
        A = A->next;
    }
    return dummy->next;
}
