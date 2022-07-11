ListNode* Solution::sortList(ListNode* A) {
    ListNode * ptr=A;
    vector<int> vec;
    while(ptr!=0){
        vec.push_back(ptr->val);
        ptr=ptr->next;
    }

    sort(vec.begin(),vec.end());

    for(int i=0;i<vec.size();i++){
        if(vec.size()==1){
            cout<<vec[0]<<" ";
            break;
        }
        else
            cout<<vec[i]<<" ";
    
        if(i<vec.size()-1)
            cout<<"-> ";
    }
  
    // Instead of printing, we can push all
    // elements into a Linked List and return back
    return NULL;
}
