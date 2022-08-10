/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct comp{
    bool operator()(ListNode*a, ListNode*b){
        return a->val > b->val;
    }
};
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    priority_queue<ListNode*, vector<ListNode*>, comp > pq;
    for(int i=0;i<A.size();i++)
        pq.push(A[i]);
    ListNode* head = NULL;
    ListNode* temp;
    while(!pq.empty()){
        ListNode* tp = pq.top();
        pq.pop();
        if(head == NULL){
            head = tp;
            temp = tp;
        }
        else{
            temp ->next = tp;
            temp = temp->next;
        }

        if(tp->next)
            pq.push(tp->next);
    }   
    return head;
}
