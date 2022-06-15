int Solution::solve(vector<vector<int> > &A) {
    int N = A.size();
    int i = 0;
    if(N == 0) return 0; 
    
    for(i = 1; i<N; i++){
        A[i][0] += min(A[i-1][1], A[i-1][2]); // if 0 chosen in row 1, min of
        //1 and 2 had to be chosen earlier. Similarly for all
        A[i][1] += min(A[i-1][0], A[i-1][2]);
        A[i][2] += min(A[i-1][0], A[i-1][1]);
    }
    
    // now find min of the 3 elements in last row
    int ans = min(min(A[i-1][0], A[i-1][1]), A[i-1][2]);
    return ans;
}
