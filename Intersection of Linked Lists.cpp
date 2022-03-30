/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int length(ListNode* A){
    int c=0;
    while(A){
        c++;
        A=A->next;
    }
    return c;
}
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    int n=length(A);
    int m=length(B);
    if(n>m){
        n=n-m;
        while(n--){
            A=A->next;
        }
    }
    else{
        m=m-n;
        while(m--){
            B=B->next;
        }
    }
    while(A!=B){
        A=A->next;
        B=B->next;
    }
    return A;
}
