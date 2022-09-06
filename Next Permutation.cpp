vector<int> Solution::nextPermutation(vector<int> &A) {
    int break_p = -1;
    int n = A.size();
    for(int i=n-1;i>0;i--){
        if(A[i] > A[i-1]){
            break_p = i-1;
            break;
        }
    }
    
    if(break_p == -1){
        reverse(A.begin(), A.end());
        return A;
    }
    
    for(int i=n-1;i>=0;i--){
        if(A[i] > A[break_p]){
            swap(A[i], A[break_p]);
            reverse(A.begin() + break_p + 1, A.end());
            break;
        }
    }
    return A;
}
