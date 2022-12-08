/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* head) {
    if(head == NULL) return head ;
    vector<ListNode*> v ; 
    ListNode* tmp = head ,*prev = tmp; 
    while(tmp){
        prev = tmp ; 
        tmp = tmp->next ; 
        prev->next = NULL ; 
        v.push_back(prev) ; 
    }
    bool ok = true ; 
    int i = 0 , j = v.size()-1 ; 
    while(i<j){
        if(ok){
            v[i]->next = v[j] ; 
            i++ ; 
        }else{
            v[j]->next = v[i] ; 
            j-- ; 
        }
        ok = !ok ;
    }
    return head ;
}
