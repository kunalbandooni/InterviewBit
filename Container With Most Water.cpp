int Solution::maxArea(vector<int> &A) {
    int n = A.size();
    int left_ptr = 0, right_ptr = n-1;
    int max_area = 0;
    
    while(left_ptr <= right_ptr){
        int area = min(A[left_ptr],A[right_ptr]) * (right_ptr - left_ptr);
        max_area = max(area, max_area);
        if(A[left_ptr] < A[right_ptr])   left_ptr++;
        else    right_ptr--;
    }
    
    return max_area;
}
