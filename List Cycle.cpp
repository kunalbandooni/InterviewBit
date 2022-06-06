/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    unordered_map<ListNode*, int> mp;
    while(A!=NULL){
        if(mp[A] != 0)
            return A;
        mp[A] = 1;
        A= A->next;
    }
    return NULL;
}
