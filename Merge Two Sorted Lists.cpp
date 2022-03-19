/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    if(!A)
        return B;
    if(!B)
        return A;
    ListNode* temp1=A;
    ListNode* temp2=B;
    ListNode* head=new ListNode(0);
    if(temp1->val <= temp2->val){
        head=temp1;
        temp1=temp1->next;
    }
    else{
        head=temp2;
        temp2=temp2->next;
    }
    ListNode* new_temp=head;
    while(temp1 and temp2){
        if(temp1->val <= temp2->val){
            new_temp->next=temp1;
            temp1=temp1->next;
        }
        else{
            new_temp->next=temp2;
            temp2=temp2->next;
        }
        new_temp = new_temp -> next;
    }
    if(temp1)
        new_temp->next = temp1;
    else
        new_temp->next = temp2;
    return head;
}
