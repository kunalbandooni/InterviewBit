/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    ListNode* current = A;
    ListNode* prev = NULL;
    int count = 0;
    if(A == NULL || B == 0)
        return A;

    //Calculate length
    while(current!=NULL){
        current = current->next;
        count++;
    }

    //If B is greater than or = to length, delete first Node
    if(B >= count){
        A = A->next;
        return A;
    }
    int temp = count - B;
    current = A;

    //Traverse the list again till we reach the Node to be delete.
    //Save the pointer to prev Node
    //Update prev->next tp current->next and set NULL To current->next
    while(temp){
        prev = current;
        current = current->next;
        temp--;
    }
    prev->next = current->next;
    current->next = NULL;
    return A;
}
