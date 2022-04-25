/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int length(ListNode *x){
    int l=0;
    while(x){
        l++;
        x=x->next;
    }
    return l;
}
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    int l1=length(A);
    int l2=length(B);
    if(l2>l1)
        return addTwoNumbers(B,A);
    ListNode *head=A,*k=B,*h;
    int r=0,d=0,a; // listnode h and k taken for make use a new node and i don’t know how to make new node;
    while(B){
        a=A->val+B->val+d;
        d=a/10;
        r=a%10;
        A->val=r;
        A=A->next;
        B=B->next;
    }
    while(A){
        if(A->next==NULL)
            h=A;
        a=A->val+d;
        d=a/10;
        r=a%10;
        A->val=r;
        A=A->next;
    }
    if(d==1){ 
        k->val=1;
        k->next=NULL;
        h->next=k;
    }
    return head;
}
