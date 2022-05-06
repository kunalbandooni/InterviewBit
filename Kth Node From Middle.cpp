/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A, int B) {
    int n=0;            //total number of nodes
    ListNode* head = A;
    while(head != NULL){
        n++;
        head= head->next;
    }
    int m = (n/2)+1;    //middle node
    if(B>=m)
        return -1;      //if B doesn’t exist inside the node
    else
        for(int i=1;i< m-B;i++)
            A= A->next;
    return A->val;
}
