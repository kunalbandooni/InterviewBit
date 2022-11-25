/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int x) {
    ListNode *till=NULL;
    ListNode *prev=NULL;
    ListNode *curr=A;
    while(curr){
        if(curr->val<x){
            if(till==NULL){
                if(curr==A){
                    till=curr;
                    prev=till;
                    curr=curr->next;
                }
                else{
                    prev->next=curr->next;
                    till=curr;
                    till->next=A;
                    A=till;
                    curr=prev->next;
                }
            }
            else{
                if(till->next==curr){
                    till=curr;
                    prev=curr;
                    curr=curr->next;
                }
                else{
                    ListNode *temp=till->next;
                    prev->next=curr->next;
                    till->next=curr;
                    curr->next=temp;
                    curr=prev->next;
                    till=till->next;
                }
            }    
        }
        else{
            prev=curr;
            curr=curr->next;
        }  
    }
    return A; 
}
