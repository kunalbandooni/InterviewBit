vector<int> Solution::maxone(vector<int> &A, int B) {
    int l = 0, r = 0;
    int r1 = 0, l1 = 0;
    int count_zero = 0, max_len = 0;
    int n = A.size();
    
    while(r < n){
        if(A[r] == 0)   count_zero++;
        while(l < n and count_zero > B){
            if(A[l] == 0)   
                count_zero--;
            l++;
        }
        
        r++;
        if(max_len < r-l){
            max_len = r-l;
            l1 = l, r1 = r;
        }
    }
    
    vector<int> res;
    for(int i = l1 ; i < r1 ; i++)
        res.push_back(i);
    return res;
}
