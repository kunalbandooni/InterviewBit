/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    /*
    Store the even positioned and odd positioned
    nodes in 2 vectors. now reverse the even position vectors
    and then Recombine them to form a linked list.
    All of this will happen in O(n) time.
    */
    if(!A || !A->next || !A->next->next) 
        return A;

    stack<int> s;
    int len = 0;
    ListNode*curr = A;
    while(curr) {
        len+=1;
        if(len%2 == 0) 
            s.push(curr->val);
        curr = curr->next;
    }
    curr = A;
    len = 0;
    while(curr) {
        len += 1;
        if(len%2 == 0) {
            curr->val = s.top();
            s.pop();
        }
        curr = curr->next;
    }
    return A;
}
