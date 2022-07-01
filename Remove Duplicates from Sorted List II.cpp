/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* head) {
    ListNode *curr=head;
    unordered_map<int, int> count;
        ListNode* p = head;
        while (p) {            
            count[p->val] ++;
            p = p->next;
        }
        ListNode* dummy = new ListNode(-1);
        p = dummy;
        while (head) {
            if (count[head->val] == 1) {
                p->next = new ListNode(head->val);
                p = p->next;
            }
            head = head->next;
        }
        return dummy->next;
    
    /*
    
    ListNode *prev=head;
    if(!head->next)
        return head;
        
    if(head->next->val == head->val){
        cur = head->next->next;
        prev = head->next;
        head = cur;
    }
    
    while(cur!=NULL && cur->next!=NULL){
        if(cur->val==cur->next->val){
            ListNode *temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        }
        else
            cur = cur->next;
    }
    return head;*/
        
}
