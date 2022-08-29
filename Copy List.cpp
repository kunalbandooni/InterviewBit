/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* head) {
        if(!head)
            return NULL;
        RandomListNode* temp=head;
        RandomListNode* pt;
        
        // First pass creates a deep copy
        while(temp!=NULL){
            RandomListNode* p=new RandomListNode(temp->label);
            p->next=temp->next;
            temp->next=p;
            temp=p->next;
        }
        
        
        // connecting the pointers now...
        
        // random ones
        RandomListNode* p;
        temp=head;
        while(temp!=NULL){
            p=temp->next;
            if(!temp->random)
                p->random=NULL;
            else
                p->random=temp->random->next;
            temp=p->next;
        }
        
        // next pointers now
        p=head->next;
        temp=head;
        pt=p;
        while(temp!=NULL){
            temp->next=pt->next;
            temp=temp->next;
            if(pt->next)
                pt->next=temp->next;
            pt=pt->next;
        }
        
        return p;
}
