/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverse(ListNode* A){
    ListNode* curr= A;
    ListNode* pre = NULL;
    ListNode* next = NULL;
    while(curr){
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }
    return pre;
}
ListNode* Solution::solve(ListNode* A, int B) {
    ListNode* next = NULL;
    ListNode* prev = NULL;
    ListNode* curr = A;
    ListNode* dummy = new ListNode(INT_MIN);
    dummy -> next = A;
    A = dummy;
    prev = A;
    curr = prev->next;
    int c = 1;
    while(curr){
        if(c%(2*B)==0)
            prev = curr;
            
        if(c%B==0 && c%(2*B)){
            next = curr->next;
            curr->next = NULL;
            
            curr = reverse(prev->next);
            prev->next = curr;
            
            while(curr->next)
                curr = curr->next;
            curr->next = next;
        }
        c++;
        curr = curr->next;
    }
    return dummy->next;
}
