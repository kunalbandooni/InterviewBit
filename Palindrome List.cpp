/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    stack<int>s;
    ListNode *sp=A,*fp=A;
    while(fp&&fp->next){
        s.push(sp->val);
        sp=sp->next;fp=fp->next->next;
    }
    if(fp)
        sp=sp->next;
    while(!s.empty()){
        if(sp->val!=s.top())
            return 0;
        sp=sp->next;
        s.pop();
    }
    return 1;
}
