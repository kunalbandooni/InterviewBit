/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* head, int k) {
    if(head== NULL) 
        return head;
    ListNode *curr = head;
    int n = 1;
    
    while(curr->next){
        curr = curr->next;
        n++;
    }

    curr->next = head;
    if(k > n) 
        k = k%n;
        
    for(int i = 0; i < n-k; i++)
        curr= curr->next;
        
    ListNode *ans = curr->next;
    curr->next = NULL;
    return ans;
}
